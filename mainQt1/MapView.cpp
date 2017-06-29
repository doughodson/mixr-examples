
#include "MapView.hpp"
#include "MainWindow.hpp"
#include "MapItem.hpp"
#include "Station.hpp"
#include "PlayerItem.hpp"

#include "mixr/models/player/Player.hpp"

#include "mixr/models/WorldModel.hpp"

#include "mixr/base/List.hpp"
#include "mixr/base/PairStream.hpp"
#include "mixr/base/Pair.hpp"

#include <QTimer>
#include <iostream>
#include <QResizeEvent>

MapView::MapView(QWidget* parent) : QGraphicsView(parent)
{
   QGraphicsScene* myScene = new QGraphicsScene(this);
   myScene->setItemIndexMethod(QGraphicsScene::NoIndex);
   myScene->setSceneRect(-(width()/2), -(height()/2), width(), height());
   setScene(myScene);

   // now add the map item
   map = new MapItem(this);
   map->setSize(width(), height());
   map->setNorthUp(false);
   scene()->addItem(map);

   players.clear();

   // setup a timer to call background refresh
   QTimer* bgTimer = new QTimer(this);
   connect(bgTimer, SIGNAL(timeout()), this, SLOT(refreshView()));
   bgTimer->start(20);
}

MapView::~MapView()
{
   if (stn != nullptr) {
      stn->unref();
      stn = nullptr;
   }
}

void MapView::resizeEvent(QResizeEvent* event)
{
   if (map != nullptr) {
       map->setSize(event->size().width(), event->size().height());
   }
   QGraphicsView::resizeEvent(event);
}

void MapView::clearPlayers()
{
   while (!players.isEmpty()) {
      PlayerItem* p = players.last();
      scene()->removeItem(players.last());
      players.removeLast();
      delete p;
   }
}

void MapView::refreshView()
{
   // find our station
   if (stn == nullptr) {
      // and get the station from it, so we can set some defaults up
      QWidget* wid = dynamic_cast<QWidget*>(parent());
      MainWindow* win = dynamic_cast<MainWindow*>(wid);
      // keep checking our parent(s) until we find the main window.
      while (win == nullptr && wid != nullptr) {
         wid = dynamic_cast<QWidget*>(wid->parent());
         if (wid != nullptr) win = dynamic_cast<MainWindow*>(wid);
      }
      if (win != nullptr) {
         stn = win->getStation();
         if (stn != nullptr) {
            stn->ref();
            // init the map
            if (map != nullptr && !map->isInit()) {
               // grab our simulation, if we have one
               auto sim = dynamic_cast<const mixr::models::WorldModel*>(stn->getSimulation());
               if (sim != nullptr) {
                  map->initialize(sim->getRefLatitude(), sim->getRefLongitude(), 100);
               }
            }
         }
      }
   }
   else {
      // update the map and players
      if (map != nullptr) map->updateBG();
      auto sim = dynamic_cast<const mixr::models::WorldModel*>(stn->getSimulation());
      if (sim != nullptr) {
         const mixr::base::PairStream* stream = sim->getPlayers();
         if (stream != nullptr) {
            // go through the players and add new or update existing players
            const mixr::base::List::Item* item = stream->getFirstItem();
            while (item != nullptr) {
               const auto pair = (const mixr::base::Pair*)item->getValue();
               if (pair != nullptr) {
                  const auto ply = dynamic_cast<const mixr::models::Player*>(pair->object());
                  if (ply != nullptr) {
                     // hold onto this player, just to be safe
                     ply->ref();
                     // see if we have a graphical representation of this player
                     bool found = false;
                     unsigned short id = ply->getID();
                     for (int i = 0; i < players.size() && !found; i++) {
                        found = (id == players[i]->getPlayerId());
                        // if we find it, update it
                        if (found)   { players[i]->refreshPlayer(ply);  }
                     }

                     // create a new player
                     if (!found) {
                        PlayerItem* p = new PlayerItem(this, map);
                        // default image is a fighter
                        p->useDefaultImage(":fighter.png", QSize(32, 32));
                        p->refreshPlayer(ply);
                        scene()->addItem(p);
                        players << p;
                     }

                     // all done with player
                     ply->unref();
                  }
               }
               item = item->getNext();
            }
            // now we have checked the sim against our players... let's check
            // our players against the sim, removing any old players
            for (int i = 0; i < players.size(); i++) {
               unsigned short id = players[i]->getPlayerId();
               const auto ply = dynamic_cast<const mixr::models::Player*>(sim->findPlayer(id));
               if (ply == nullptr) {
                  // player is gone, remove
                  PlayerItem* p = players[i];
                  scene()->removeItem(p);
                  players.removeAt(i);
                  delete p;
                  i--;
               }
            }
         }
      }
      // no sim, clear players
      else {
         clearPlayers();
      }
   }
}
