//----------------------------------------------------------------
// Demo app for Efis
//----------------------------------------------------------------
#include "mixr/base/Pair.hpp"
#include "mixr/base/Timers.hpp"
#include "mixr/base/edl_parser.hpp"
#include "mixr/graphics/Graphic.hpp"


#include "mixr/ui/glut/GlutDisplay.hpp"
#include <GL/glut.h>

// factories
#include "mixr/instruments/factory.hpp"
#include "mixr/ui/glut/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/base/factory.hpp"

// Test pages
#include "TestMechanical.hpp"
#include "TestElectronic.hpp"

#include <string>
#include <cstdlib>

// frame rate
const unsigned int frameRate = 20;

// System descriptions
mixr::glut::GlutDisplay* glutDisplay = nullptr;

// timerFunc() -- Time critical stuff)
void timerFunc(int)
{
   const auto dt = 1.0 / static_cast<double>(frameRate);
   const auto millis = static_cast<unsigned int>(dt * 1000);
   glutTimerFunc(millis, timerFunc, 1);

   mixr::base::Timer::updateTimers(dt);
   mixr::graphics::Graphic::flashTimer(dt);
   glutDisplay->updateTC(dt);
}

// our class factory
mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj = nullptr;

   // Tests
   if ( name == TestMechanical::getFactoryName() ) {
      obj = new TestMechanical;
   }
   else if ( name == TestElectronic::getFactoryName() ) {
      obj = new TestElectronic;
   }

   else {
      if (obj == nullptr) obj = mixr::instruments::factory(name);
      if (obj == nullptr) obj = mixr::graphics::factory(name);
      if (obj == nullptr) obj = mixr::glut::factory(name);
      if (obj == nullptr) obj = mixr::base::factory(name);
   }
   return obj;
}

// display builder
mixr::glut::GlutDisplay* builder(const std::string& filename)
{
   // read configuration file
   unsigned int num_errors = 0;
   mixr::base::Object* obj = mixr::base::edl_parser(filename, factory, &num_errors);
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
   std::string configFilename = "glutdisplay.edl";

   glutDisplay = builder(configFilename);

   // create a display window
   glutDisplay->createWindow();

   // set timer
   const auto dt = 1.0 / static_cast<double>(frameRate);
   const auto millis = static_cast<unsigned int>(dt * 1000);
   glutTimerFunc(millis, timerFunc, 1);

   glutMainLoop();
   return 0;
}
