//----------------------------------------------------------------
// Example flight displays 1
//----------------------------------------------------------------
#include "mxrp/base/Pair.hpp"
#include "mxrp/base/Timers.hpp"
#include "mxrp/base/edl_parser.hpp"
#include "mxrp/graphics/Graphic.hpp"
#include "mxrp/gui/glut/GlutDisplay.hpp"
#include <GL/glut.h>

// factories
#include "mxrp/base/factory.hpp"
#include "mxrp/graphics/factory.hpp"
#include "mxrp/instruments/factory.hpp"
#include "mxrp/gui/glut/factory.hpp"

// test pages
#include "TestPfd.hpp"
#include "TestSD.hpp"
// instruments
#include "CrsPntr.hpp"
#include "Hsi.hpp"
#include "Pfd.hpp"
#include "RdrAlt.hpp"
#include "SituationalDisplay.hpp"
#include "SpdLines.hpp"
#include "TerrainFollower.hpp"

#include <string>
#include <cstdlib>

// frame rate
const unsigned int frameRate = 20;

// System descriptions
mxrp::glut::GlutDisplay* glutDisplay = nullptr;

// timerFunc() -- Time critical stuff
void timerFunc(int)
{
    const auto dt = 1.0 / static_cast<double>(frameRate);
    const auto millis = static_cast<unsigned int>(dt * 1000);
    glutTimerFunc(millis, timerFunc, 1);

    mxrp::base::Timer::updateTimers(dt);
    mxrp::graphics::Graphic::flashTimer(dt);
    glutDisplay->updateTC(dt);
}

// our class factory
mxrp::base::Object* factory(const std::string& name)
{
   mxrp::base::Object* obj = nullptr;

   // Test the primary flight display (PFD)
   if ( name == TestPfd::getFactoryName() ) {
      obj = new TestPfd;
   }
   // situational display
   else if ( name == TestSD::getFactoryName() ) {
      obj = new TestSD;
   }
   // CrsPntr
   else if ( name == CrsPntr::getFactoryName() ) {
      obj = new CrsPntr;
   }
   // Hsi
   else if ( name == Hsi::getFactoryName() ) {
      obj = new Hsi;
   }
   // Pfd
   else if ( name == Pfd::getFactoryName() ) {
      obj = new Pfd;
   }
   // RdrAlt
   else if ( name == RdrAlt::getFactoryName() ) {
      obj = new RdrAlt;
   }
   // SituationalDisplay
   else if ( name == SituationalDisplay::getFactoryName() ) {
      obj = new SituationalDisplay;
   }
   // SpdLines
   else if ( name == SpdLines::getFactoryName() ) {
      obj = new SpdLines;
   }
   // TerrainFollower
   else if ( name == TerrainFollower::getFactoryName() ) {
      obj = new TerrainFollower;
   }

   if (obj == nullptr) obj = mxrp::instruments::factory(name);
   if (obj == nullptr) obj = mxrp::graphics::factory(name);
   if (obj == nullptr) obj = mxrp::glut::factory(name);
   if (obj == nullptr) obj = mxrp::base::factory(name);

   return obj;
}

// display builder
mxrp::glut::GlutDisplay* builder(const std::string& filename)
{
   // read configuration file
   unsigned int num_errors = 0;
   mxrp::base::Object* obj = mxrp::base::edl_parser(filename, factory, &num_errors);
   if (num_errors > 0) {
      std::cerr << "File: " << filename << ", number of errors: " << num_errors << std::endl;
      std::exit(EXIT_FAILURE);
   }

   // test to see if an object was created
   if (obj == nullptr) {
      std::cerr << "Invalid configuration file, no objects defined!" << std::endl;
      std::exit(EXIT_FAILURE);
   }

   // do we have a base::Pair, if so, point to object in Pair, not Pair itself
   const auto pair = dynamic_cast<mxrp::base::Pair*>(obj);
   if (pair != nullptr) {
      obj = pair->object();
      obj->ref();
      pair->unref();
   }

   // try to cast to proper object, and check
   const auto glutDisplay = dynamic_cast<mxrp::glut::GlutDisplay*>(obj);
   if (glutDisplay == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return glutDisplay;
}

//
int main(int argc, char* argv[])
{
   glutInit(&argc, argv);

   // default configuration filename
   std::string configFilename = "test.edl";
   glutDisplay = builder(configFilename);

   glutDisplay->createWindow();

   // set timer
   const double dt = 1.0/static_cast<double>(frameRate);
   const auto millis = static_cast<unsigned int>(dt * 1000);
   glutTimerFunc(millis, timerFunc, 1);

   // main loop
   glutMainLoop();
   return 0;
}
