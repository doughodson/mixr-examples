
#include "TestStation.hpp"

#include "mxrp/models/system/Antenna.hpp"
#include "mxrp/models/player/AirVehicle.hpp"

#include "mxrp/base/Boolean.hpp"
#include "mxrp/base/Pair.hpp"
#include "mxrp/base/PairStream.hpp"
#include "mxrp/base/units/Angles.hpp"
#include "mxrp/base/Timers.hpp"

#include "mxrp/gui/glut/GlutDisplay.hpp"

IMPLEMENT_SUBCLASS(TestStation, "TestStation")

BEGIN_SLOTTABLE(TestStation)
    "glutDisplay",
    "mapDisplay",
END_SLOTTABLE(TestStation)

BEGIN_SLOT_MAP(TestStation)
    ON_SLOT(1, setSlotGlutDisplay, mxrp::glut::GlutDisplay)
    ON_SLOT(2, setSlotMapDisplay, mxrp::glut::GlutDisplay)
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
   mxrp::base::Timer::updateTimers(dt);
   mxrp::graphics::Graphic::flashTimer(dt);

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

bool TestStation::setSlotGlutDisplay(mxrp::glut::GlutDisplay* const d)
{
   glutDisplay = d;
   glutDisplay->container(this);
   return true;
}

bool TestStation::setSlotMapDisplay(mxrp::glut::GlutDisplay* const d)
{
   mapDisplay = d;
   mapDisplay->container(this);
   return true;
}

std::ostream& TestStation::serialize(std::ostream& sout, const int i, const bool slotsOnly) const
{
   int j = 0;
   if ( !slotsOnly ) {
      sout << "( " << getFactoryName() << std::endl;
      j = 4;
   }

   if (glutDisplay != nullptr) {
      indent(sout,i+j);
      sout << "glutDisplay: ";
      glutDisplay->serialize(sout,i+j+4);
   }

   BaseClass::serialize(sout,i+j,true);

   if ( !slotsOnly ) {
      indent(sout,i);
      sout << ")" << std::endl;
   }

   return sout;
}
