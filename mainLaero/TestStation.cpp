
#include "TestStation.hpp"

#include "mixr/models/system/Antenna.hpp"
#include "mixr/models/player/air/AirVehicle.hpp"

#include "mixr/base/numeric/Boolean.hpp"

#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"
#include "mixr/base/units/Angles.hpp"
#include "mixr/base/Timers.hpp"

#include "mixr/ui/glut/GlutDisplay.hpp"

IMPLEMENT_SUBCLASS(TestStation, "TestStation")

BEGIN_SLOTTABLE(TestStation)
    "glutDisplay",
    "mapDisplay",
END_SLOTTABLE(TestStation)

BEGIN_SLOT_MAP(TestStation)
    ON_SLOT(1, setSlotGlutDisplay, mixr::glut::GlutDisplay)
    ON_SLOT(2, setSlotMapDisplay, mixr::glut::GlutDisplay)
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
   setSlotMapDisplay(nullptr);
   mapDisplayInit = false;
}

void TestStation::deleteData()
{
   setSlotGlutDisplay(nullptr);
   setSlotMapDisplay(nullptr);
}

void TestStation::updateTC(const double dt)
{
   // manage the timers
   mixr::base::Timer::updateTimers(dt);
   mixr::graphics::Graphic::flashTimer(dt);

   if (glutDisplay != nullptr) glutDisplay->updateTC(dt);
   if (mapDisplay != nullptr) mapDisplay->updateTC(dt);

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

   // create the MAP window
   if (!mapDisplayInit && mapDisplay != nullptr) {
      mapDisplay->createWindow();
      mapDisplay->focus(mapDisplay);
      mapDisplayInit = true;
   }
}

bool TestStation::setSlotGlutDisplay(mixr::glut::GlutDisplay* const d)
{
   glutDisplay = d;
   glutDisplay->container(this);
   return true;
}

bool TestStation::setSlotMapDisplay(mixr::glut::GlutDisplay* const d)
{
   mapDisplay = d;
   mapDisplay->container(this);
   return true;
}

