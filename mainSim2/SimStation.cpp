
#include "SimStation.hpp"

#include "mixr/simulation/ISimulation.hpp"

#include "mixr/models/player/air/AirVehicle.hpp"

#include "mixr/ui/glut/GlutDisplay.hpp"

#include "mixr/base/Identifier.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"
#include "mixr/base/Timers.hpp"
#include "mixr/base/numeric/Boolean.hpp"
#include "mixr/base/units/angles.hpp"
#include "mixr/base/units/times.hpp"

IMPLEMENT_SUBCLASS(SimStation, "SimStation")
EMPTY_DELETEDATA(SimStation)

BEGIN_SLOTTABLE(SimStation)
    "display",                  //  1: main display
    "autoResetTimer",           //  2: Auto RESET timer value (base::Time); default: zero (no auto reset)
END_SLOTTABLE(SimStation)

BEGIN_SLOT_MAP(SimStation)
    ON_SLOT( 1, setSlotDisplay,        mixr::glut::GlutDisplay)
    ON_SLOT( 2, setSlotAutoResetTime,  mixr::base::ITime)
END_SLOT_MAP()

SimStation::SimStation()
{
    STANDARD_CONSTRUCTOR()
}

void SimStation::copyData(const SimStation& org, const bool)
{
    BaseClass::copyData(org);

    display = org.display->clone();
    //setSlotAutoResetTime(org.autoResetTimer0);
    autoResetTimer0 = org.autoResetTimer0->clone();
}

void SimStation::reset()
{
    if (display != nullptr && !displayInit) {
        display->createWindow();
        mixr::base::Pair* p{display->findByType(typeid(mixr::graphics::Page))};
        if (p != nullptr) display->focus(static_cast<mixr::graphics::Graphic*>(p->object()));
        else display->focus(nullptr);
        displayInit = true;
    }
    // reset all of our subcomponents
    if (display != nullptr) display->reset();

    // auto reset timer
    if (autoResetTimer0 != nullptr) {
        autoResetTimer = autoResetTimer0->getValueInSeconds();
    } else {
        autoResetTimer = 0.0;
    }

    // reset our baseclass
    BaseClass::reset();
}

void SimStation::updateTC(const double dt)
{
    // First update the simulation
    BaseClass::updateTC(dt);

    mixr::base::Timer::updateTimers(dt);
    mixr::graphics::Graphic::flashTimer(dt);

    // Update any TC stuff in our main display
    if (display != nullptr) display->updateTC(dt);
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

       mixr::models::IPlayer* f{};
       mixr::models::IPlayer* n{};
       bool found{};

       // Find the next player
       mixr::base::IList::Item* item{pl->getFirstItem()};
       while (item != nullptr) {
           const auto pair = static_cast<mixr::base::Pair*>(item->getValue());
           if (pair != nullptr) {
               const auto ip = static_cast<mixr::models::IPlayer*>(pair->object());
               if ( ip->isMode(mixr::models::IPlayer::Mode::ACTIVE) &&
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

bool SimStation::setSlotDisplay(mixr::glut::GlutDisplay* const x)
{
    bool ok{};
    display = x;
    if (display != nullptr) {
        display->container(this);
        ok = true;
    }
    return ok;
}

// setSlotAutoResetTime() -- Sets the startup RESET pulse timer
bool SimStation::setSlotAutoResetTime(mixr::base::ITime* const x)
{
    autoResetTimer0 = x;
    if (autoResetTimer0 != nullptr) {
        autoResetTimer = autoResetTimer0->getValueInSeconds();
    } else {
        autoResetTimer = -1.0;
    }
    return true;
}

