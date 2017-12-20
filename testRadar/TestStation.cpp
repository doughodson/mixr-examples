
#include "TestStation.hpp"

#include "mixr/models/system/Antenna.hpp"
#include "mixr/models/player/air/AirVehicle.hpp"

#include "mixr/simulation/Simulation.hpp"

#include "mixr/base/numeric/Boolean.hpp"

#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"
#include "mixr/base/units/Angles.hpp"
#include "mixr/base/Timers.hpp"

#include "mixr/ui/glut/GlutDisplay.hpp"

using namespace mixr;

IMPLEMENT_SUBCLASS(TestStation, "TestStation")

BEGIN_SLOTTABLE(TestStation)
    "glutDisplay",
END_SLOTTABLE(TestStation)

BEGIN_SLOT_MAP(TestStation)
    ON_SLOT(1, setSlotGlutDisplay, glut::GlutDisplay)
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

   rstSw1 = org.rstSw1;
   frzSw1 = org.frzSw1;
   wpnRelSw1 = org.wpnRelSw1;
   tgtStepSw1 = org.tgtStepSw1;
   incTagPlayerSw1 = org.incTagPlayerSw1;
   bgAntenna = org.bgAntenna;
}

void TestStation::deleteData()
{
   setSlotGlutDisplay(nullptr);
}

void TestStation::updateTC(const double dt)
{
   // manage the timers
   base::Timer::updateTimers(dt);
   graphics::Graphic::flashTimer(dt);

   if (glutDisplay != nullptr) {
      glutDisplay->updateTC(dt);
   }

   BaseClass::updateTC(dt);
}

void TestStation::updateData(const double dt)
{
   // ### Don't call updateData for our 'glutDisplay', which is derived from
   // graphics::GlutDisplay, because graphics::GlutDisplay handles calling updateData() for it's
   // own displays.

   BaseClass::updateData(dt);
}

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

bool TestStation::setSlotGlutDisplay(glut::GlutDisplay* const d)
{
   glutDisplay = d;
   glutDisplay->container(this);
   return true;
}

