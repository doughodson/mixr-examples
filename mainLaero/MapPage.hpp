
#ifndef __MapPage_H__
#define __MapPage_H__

#include "mixr/graphics/MapPage.hpp"

#include <array>

namespace mixr {
namespace models { class Player; }
namespace graphics { class SymbolLoader; }
}

class TestStation;

// -------------------------------------------------------------------------------
// Class: MapPage
// Description:
//      Derived MapPage that will show how to add, remove, and update symbols with the
//      SymbolLoader class.
// -------------------------------------------------------------------------------
class MapPage final: public mixr::graphics::MapPage
{
   DECLARE_SUBCLASS(MapPage, mixr::graphics::MapPage)

public:
   MapPage();

   void drawFunc() final;
   void updateData(const double dt = 0.0) final;

private:
   void drawLine(const double x, const double y);
   void drawSemiCircle(const double startAngle, const double radius);
   void drawHoldingPattern();

   // holds our players
   static const int MAX_PLAYERS{200};
   static const int MAX_READOUTS{20};

   std::array<mixr::models::Player*, MAX_PLAYERS> player{};   // player pointer
   std::array<int, MAX_PLAYERS> playerIdx{};                  // index of our symbol for the given player
   // player symbol loader
   mixr::graphics::SymbolLoader* loader{};    // holds our loader for quick reference
   TestStation* pStn{};                       // holds our station (to get the player list quickly)

   // is our route loaded?
   bool routeLoaded{};

   // show where our lat/lons are
   SendData latsSD[MAX_READOUTS];
   std::array<int, MAX_READOUTS> lats{};

   SendData latReadoutXPosSD[MAX_READOUTS];
   std::array<float, MAX_READOUTS> latReadoutXPos{};

   SendData latReadoutYPosSD[MAX_READOUTS];
   std::array<float, MAX_READOUTS> latReadoutYPos{};

   // lons
   SendData lonsSD[MAX_READOUTS];
   std::array<int, MAX_READOUTS> lons{};

   SendData lonReadoutXPosSD[MAX_READOUTS];
   std::array<float, MAX_READOUTS> lonReadoutXPos{};

   SendData lonReadoutYPosSD[MAX_READOUTS];
   std::array<float, MAX_READOUTS> lonReadoutYPos{};
};

#endif
