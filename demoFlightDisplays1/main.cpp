//----------------------------------------------------------------
// Example flight displays 1
//----------------------------------------------------------------
#include "mixr/base/Pair.hpp"
#include "mixr/base/Timers.hpp"
#include "mixr/base/edl_parser.hpp"
#include "mixr/graphics/Graphic.hpp"
#include "mixr/ui/glut/GlutDisplay.hpp"
#include <GL/glut.h>

// factories
#include "mixr/base/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/instruments/factory.hpp"
#include "mixr/ui/glut/factory.hpp"

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

const int frameRate{20};
mixr::glut::GlutDisplay* glutDisplay{};

// timerFunc() -- Time critical stuff
void timerFunc(int)
{
    const double dt{1.0 / static_cast<double>(frameRate)};
    const int millis{static_cast<int>(dt * 1000)};
    glutTimerFunc(millis, timerFunc, 1);

    mixr::base::Timer::updateTimers(dt);
    mixr::graphics::Graphic::flashTimer(dt);
    glutDisplay->updateTC(dt);
}

mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj{};

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

   if (obj == nullptr) obj = mixr::instruments::factory(name);
   if (obj == nullptr) obj = mixr::graphics::factory(name);
   if (obj == nullptr) obj = mixr::glut::factory(name);
   if (obj == nullptr) obj = mixr::base::factory(name);

   return obj;
}

mixr::glut::GlutDisplay* builder(const std::string& filename)
{
   // read configuration file
   int num_errors{};
   mixr::base::Object* obj{mixr::base::edl_parser(filename, factory, &num_errors)};
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
   const auto pair = dynamic_cast<mixr::base::Pair*>(obj);
   if (pair != nullptr) {
      obj = pair->object();
      obj->ref();
      pair->unref();
   }

   // try to cast to proper object, and check
   const auto glutDisplay = dynamic_cast<mixr::glut::GlutDisplay*>(obj);
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
   const double dt{1.0/static_cast<double>(frameRate)};
   const int millis{static_cast<int>(dt * 1000)};
   glutTimerFunc(millis, timerFunc, 1);

   // main loop
   glutMainLoop();
   return 0;
}
