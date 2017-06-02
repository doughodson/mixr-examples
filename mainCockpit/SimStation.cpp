
#include "SimStation.hpp"

#include "mxrp/simulation/Simulation.hpp"

#include "mxrp/models/player/AirVehicle.hpp"

#include "mxrp/gui/glut/GlutDisplay.hpp"
#include "mxrp/base/Identifier.hpp"
#include "mxrp/base/Boolean.hpp"
#include "mxrp/base/Pair.hpp"
#include "mxrp/base/PairStream.hpp"
#include "mxrp/base/functors/Tables.hpp"
#include "mxrp/base/Timers.hpp"
#include "mxrp/base/units/Angles.hpp"
#include "mxrp/base/units/Times.hpp"

IMPLEMENT_SUBCLASS(SimStation, "SimStation")
EMPTY_SERIALIZER(SimStation)
EMPTY_DELETEDATA(SimStation)

// slot table for this class type
BEGIN_SLOTTABLE(SimStation)
    "display",                  //  1) Main Display
    "autoResetTimer",           //  2: Auto RESET timer value (base::Time); default: zero (no auto reset)
END_SLOTTABLE(SimStation)

//  Map slot table to handles
BEGIN_SLOT_MAP(SimStation)
    ON_SLOT( 1, setSlotMainDisplay,    oe::glut::GlutDisplay)
    ON_SLOT( 2, setSlotAutoResetTime,  oe::base::Time)
END_SLOT_MAP()

SimStation::SimStation()
{
    STANDARD_CONSTRUCTOR()

    mainDisplay = nullptr;
    displayInit = false;

    autoResetTimer0 = nullptr;
    autoResetTimer = 0.0;
}

void SimStation::copyData(const SimStation& org, const bool cc)
{
    BaseClass::copyData(org);
    if (cc) {
        autoResetTimer0 = nullptr;
    }

    setSlotAutoResetTime(org.autoResetTimer0);
    autoResetTimer = org.autoResetTimer;
}

void SimStation::reset()
{
    if (!displayInit && mainDisplay != nullptr) {
        mainDisplay->createWindow();
        oe::base::Pair* p = mainDisplay->findByType(typeid(oe::graphics::Page));
        if (p != nullptr) mainDisplay->focus(static_cast<oe::graphics::Graphic*>(p->object()));
        else mainDisplay->focus(nullptr);
        displayInit = true;
    }
    // reset all of our subcomponents
    if (mainDisplay != nullptr) mainDisplay->reset();

    // auto reset timer
    if (autoResetTimer0 != nullptr) {
        autoResetTimer = oe::base::Seconds::convertStatic(*autoResetTimer0);
    }
    else {
        autoResetTimer = 0;
    }

    // reset our baseclass
    BaseClass::reset();
}

void SimStation::updateTC(const double dt)
{
    // update station
    BaseClass::updateTC(dt);

    oe::base::Timer::updateTimers(dt);
    oe::graphics::Graphic::flashTimer(dt);

    // Update any TC stuff in our main display
    if (mainDisplay != nullptr) mainDisplay->updateTC(dt);
}

void SimStation::updateData(const double dt)
{
    // ### Don't call updateData for our 'mainDisplay', which is derived from
    // graphics::GlutDisplay, because graphics::GlutDisplay handles calling updateData() for it's
    // own displays.

    // ---
    // Auto RESET/FREEZE timer --
    // ---
    if ( autoResetTimer > 0 && getSimulation()->isNotFrozen() ) {
       autoResetTimer -= dt;
       if (autoResetTimer <= 0) {
         oe::base::Boolean newFrz(true);
         getSimulation()->event(FREEZE_EVENT, &newFrz);
         this->event(RESET_EVENT);
       }
    }

    BaseClass::updateData(dt);
}

// step to the next local player
void SimStation::stepOwnshipPlayer()
{
   oe::base::PairStream* pl = getSimulation()->getPlayers();
   if (pl != nullptr) {

      oe::models::Player* f = nullptr;
      oe::models::Player* n = nullptr;
      bool found = false;

      // Find the next player
      oe::base::List::Item* item = pl->getFirstItem();
      while (item != nullptr) {
         const auto pair = static_cast<oe::base::Pair*>(item->getValue());
         if (pair != nullptr) {
            const auto ip = static_cast<oe::models::Player*>(pair->object());
            if ( ip->isMode(oe::models::Player::ACTIVE) &&
               ip->isLocalPlayer() &&
               ip->isClassType(typeid(oe::models::AirVehicle))
               ) {
                  if (f == nullptr) { f = ip; }  // Remember the first
                  if (found) { n = ip; ; break; }
                  if (ip == getOwnship()) found = true;
            }
         }
         item = item->getNext();
      }
      if (found && n == nullptr) n = f;
      if (n != nullptr) setOwnshipPlayer(n);

      pl->unref();
    }
}

// Main Display
bool SimStation::setSlotMainDisplay(oe::glut::GlutDisplay* const d)
{
    if (mainDisplay != nullptr) mainDisplay->container(nullptr);
    mainDisplay = d;
    if (mainDisplay != nullptr) mainDisplay->container(this);
    displayInit = false;
    return true;
}

// setSlotAutoResetTime() -- Sets the startup RESET pulse timer
bool SimStation::setSlotAutoResetTime(const oe::base::Time* const num)
{
    if (autoResetTimer0 != nullptr) {
        autoResetTimer0->unref();
        autoResetTimer0 = nullptr;
        autoResetTimer = -1.0;
    }
    autoResetTimer0 = num;
    if (autoResetTimer0 != nullptr) {
        autoResetTimer0->ref();
        autoResetTimer = oe::base::Seconds::convertStatic(*autoResetTimer0);
    }
    return true;
}

