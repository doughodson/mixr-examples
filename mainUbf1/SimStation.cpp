
#include "SimStation.hpp"

#include "mixr/simulation/Simulation.hpp"

#include "mixr/models/player/air/AirVehicle.hpp"

#include "mixr/ui/glut/GlutDisplay.hpp"

#include "mixr/base/numeric/Boolean.hpp"
#include "mixr/base/units/Angles.hpp"
#include "mixr/base/units/Times.hpp"

#include "mixr/base/Identifier.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"
#include "mixr/base/Timers.hpp"

using namespace mixr;

IMPLEMENT_SUBCLASS(SimStation, "SimStation")
EMPTY_COPYDATA(SimStation)
EMPTY_DELETEDATA(SimStation)

BEGIN_SLOTTABLE(SimStation)
    "display",                  //  1) Main Display
END_SLOTTABLE(SimStation)

BEGIN_SLOT_MAP(SimStation)
    ON_SLOT( 1, setSlotMainDisplay, glut::GlutDisplay)
END_SLOT_MAP()

SimStation::SimStation()
{
    STANDARD_CONSTRUCTOR()
}

void SimStation::reset()
{
    // setup ownship player pointer
    setOwnshipByName( getOwnshipName()->getString() );

    if (!displayInit && mainDisplay != nullptr) {
        mainDisplay->createWindow();
        base::Pair* p{mainDisplay->findByType(typeid(graphics::Page))};
        if (p != nullptr) mainDisplay->focus(static_cast<graphics::Graphic*>(p->object()));
        else mainDisplay->focus(nullptr);
        displayInit = true;
    }
    // reset all of our subcomponents
    if (mainDisplay != nullptr) mainDisplay->reset();

    // reset our baseclass
    BaseClass::reset();
}

void SimStation::updateTC(const double dt)
{
    // First update the simulation
    BaseClass::updateTC(dt);

    base::Timer::updateTimers(dt);
    graphics::Graphic::flashTimer(dt);

    // Update any TC stuff in our main display
    if (mainDisplay != nullptr) mainDisplay->updateTC(dt);
}

//------------------------------------------------------------------------------
// stepOwnshipPlayer() -- Step to the next local player
//------------------------------------------------------------------------------
void SimStation::stepOwnshipPlayer()
{
   base::PairStream* pl{getSimulation()->getPlayers()};
   if (pl != nullptr) {

      models::Player* f{};
      models::Player* n{};
      bool found{};

      // Find the next player
      base::List::Item* item{pl->getFirstItem()};
      while (item != nullptr) {
         const auto pair = static_cast<base::Pair*>(item->getValue());
         if (pair != nullptr) {
            const auto ip = static_cast<models::Player*>(pair->object());
            if ( ip->isMode(models::Player::ACTIVE) &&
               ip->isLocalPlayer() &&
               ip->isClassType(typeid(models::AirVehicle))
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

bool SimStation::setSlotMainDisplay(glut::GlutDisplay* const d)
{
    if (mainDisplay != nullptr) mainDisplay->container(nullptr);
    mainDisplay = d;
    if (mainDisplay != nullptr) mainDisplay->container(this);
    displayInit = false;
    return true;
}

