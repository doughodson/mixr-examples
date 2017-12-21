
#include "SimStation.hpp"

#include "mixr/simulation/Simulation.hpp"

#include "mixr/models/player/air/AirVehicle.hpp"

#include "mixr/ui/glut/GlutDisplay.hpp"
#include "mixr/base/Identifier.hpp"
#include "mixr/base/numeric/Boolean.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"
#include "mixr/base/Timers.hpp"
#include "mixr/base/units/Angles.hpp"
#include "mixr/base/units/Times.hpp"

IMPLEMENT_SUBCLASS(SimStation, "SimStation")
EMPTY_DELETEDATA(SimStation)

BEGIN_SLOTTABLE(SimStation)
    "display",                  //  1) Main Display
    "autoResetTimer",           //  2: Auto RESET timer value (base::Time); default: zero (no auto reset)
END_SLOTTABLE(SimStation)

BEGIN_SLOT_MAP(SimStation)
    ON_SLOT( 1, setSlotMainDisplay,    mixr::glut::GlutDisplay)
    ON_SLOT( 2, setSlotAutoResetTime,  mixr::base::Time)
END_SLOT_MAP()

SimStation::SimStation()
{
    STANDARD_CONSTRUCTOR()
}

void SimStation::copyData(const SimStation& org, const bool)
{
    BaseClass::copyData(org);

    setSlotAutoResetTime(org.autoResetTimer0);
    autoResetTimer = org.autoResetTimer;
}

void SimStation::reset()
{
    if (!displayInit && mainDisplay != nullptr) {
        mainDisplay->createWindow();
        mixr::base::Pair* p{mainDisplay->findByType(typeid(mixr::graphics::Page))};
        if (p != nullptr) mainDisplay->focus(static_cast<mixr::graphics::Graphic*>(p->object()));
        else mainDisplay->focus(nullptr);
        displayInit = true;
    }
    // reset all of our subcomponents
    if (mainDisplay != nullptr) mainDisplay->reset();

    // auto reset timer
    if (autoResetTimer0 != nullptr) {
        autoResetTimer = mixr::base::Seconds::convertStatic(*autoResetTimer0);
    } else {
        autoResetTimer = 0;
    }

    // reset our baseclass
    BaseClass::reset();
}

void SimStation::updateTC(const double dt)
{
    // update station
    BaseClass::updateTC(dt);

    mixr::base::Timer::updateTimers(dt);
    mixr::graphics::Graphic::flashTimer(dt);

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
         mixr::base::Boolean newFrz(true);
         getSimulation()->event(FREEZE_EVENT, &newFrz);
         this->event(RESET_EVENT);
       }
    }

    BaseClass::updateData(dt);
}

// step to the next local player
void SimStation::stepOwnshipPlayer()
{
   mixr::base::PairStream* pl{getSimulation()->getPlayers()};
   if (pl != nullptr) {

      mixr::models::Player* f{};
      mixr::models::Player* n{};
      bool found = false;

      // Find the next player
      mixr::base::List::Item* item{pl->getFirstItem()};
      while (item != nullptr) {
         const auto pair = static_cast<mixr::base::Pair*>(item->getValue());
         if (pair != nullptr) {
            const auto ip = static_cast<mixr::models::Player*>(pair->object());
            if ( ip->isMode(mixr::models::Player::ACTIVE) &&
               ip->isLocalPlayer() &&
               ip->isClassType(typeid(mixr::models::AirVehicle))
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
bool SimStation::setSlotMainDisplay(mixr::glut::GlutDisplay* const d)
{
    if (mainDisplay != nullptr) mainDisplay->container(nullptr);
    mainDisplay = d;
    if (mainDisplay != nullptr) mainDisplay->container(this);
    displayInit = false;
    return true;
}

// setSlotAutoResetTime() -- Sets the startup RESET pulse timer
bool SimStation::setSlotAutoResetTime(const mixr::base::Time* const num)
{
    if (autoResetTimer0 != nullptr) {
        autoResetTimer0->unref();
        autoResetTimer0 = nullptr;
        autoResetTimer = -1.0;
    }
    autoResetTimer0 = num;
    if (autoResetTimer0 != nullptr) {
        autoResetTimer0->ref();
        autoResetTimer = mixr::base::Seconds::convertStatic(*autoResetTimer0);
    }
    return true;
}

