
#include "TestStation.hpp"

#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"
#include "mixr/base/Timers.hpp"

#include "mixr/models/player/air/AirVehicle.hpp"

#include "mixr/simulation/Simulation.hpp"

#include "mixr/ui/glut/GlutDisplay.hpp"

IMPLEMENT_SUBCLASS(TestStation, "TestStation")

BEGIN_SLOTTABLE(TestStation)
    "glutDisplay",
END_SLOTTABLE(TestStation)

BEGIN_SLOT_MAP(TestStation)
    ON_SLOT(1, setSlotGlutDisplay, mixr::glut::GlutDisplay)
END_SLOT_MAP()

TestStation::TestStation()
{
   STANDARD_CONSTRUCTOR()
}

void TestStation::copyData(const TestStation& org, const bool)
{
   BaseClass::copyData(org);

   setSlotGlutDisplay(nullptr);
   glutDisplayInit = false;
}

// delete member data
void TestStation::deleteData()
{
   setSlotGlutDisplay(nullptr);
}

//------------------------------------------------------------------------------
// updateTC() -- Update time critical stuff here
//------------------------------------------------------------------------------
void TestStation::updateTC(const double dt)
{
   if (glutDisplay != nullptr) {
      glutDisplay->updateTC(dt);
   }
   BaseClass::updateTC(dt);
}

//------------------------------------------------------------------------------
// updateData() -- update non-time critical stuff here
//------------------------------------------------------------------------------
void TestStation::updateData(const double dt)
{
   // ### Don't call updateData for our 'glutDisplay', which is derived from
   // graphics::GlutDisplay, because graphics::GlutDisplay handles calling updateData() for it's
   // own displays.

   // manage the timers
   mixr::base::Timer::updateTimers(dt);
   mixr::graphics::Graphic::flashTimer(dt);

   BaseClass::updateData(dt);
}

//------------------------------------------------------------------------------
// reset() -- Reset the station
//------------------------------------------------------------------------------
void TestStation::reset()
{
    BaseClass::reset();

   // ---
   // Create the GLUT window
   // ---
    if (!glutDisplayInit && glutDisplay != nullptr) {
        glutDisplay->createWindow();
        glutDisplay->focus(glutDisplay);
        glutDisplayInit = true;
    }
}

//------------------------------------------------------------------------------
// stepOwnshipPlayer() -- Step to the next local player
//------------------------------------------------------------------------------
void TestStation::stepOwnshipPlayer()
{
   mixr::base::PairStream* pl{getSimulation()->getPlayers()};
   if (pl != nullptr) {

      mixr::models::Player* f{};
      mixr::models::Player* n{};
      bool found{};

      // Find the next player
      mixr::base::List::Item* item{pl->getFirstItem()};
      while (item != nullptr) {
         const auto pair = static_cast<mixr::base::Pair*>(item->getValue());
         if (pair != nullptr) {
            const auto ip = static_cast<mixr::models::Player*>( pair->object() );
            if ( ip->isMode(mixr::models::Player::ACTIVE) &&
               ip->isLocalPlayer()
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

bool TestStation::setSlotGlutDisplay(mixr::glut::GlutDisplay* const d)
{
    glutDisplay = d;
    glutDisplay->container(this);
    return true;
}

