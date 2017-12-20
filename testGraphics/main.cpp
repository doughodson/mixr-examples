
#include "mixr/base/Pair.hpp"
#include "mixr/base/Timers.hpp"
#include "mixr/base/edl_parser.hpp"
#include "mixr/base/units/Angles.hpp"

#include "mixr/graphics/Graphic.hpp"
#include "mixr/graphics/Image.hpp"

#include "mixr/ui/glut/GlutDisplay.hpp"

#include "TestDisplay.hpp"

// factories
#include "mixr/base/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/ui/glut/factory.hpp"

#include <GL/glut.h>

#include "MfdPage.hpp"
#include "TestOne.hpp"
#include "TestTwo.hpp"
#include "TdAzPtr.hpp"
#include "TdElevPtr.hpp"
#include "TestRotator.hpp"

#include <string>
#include <cstdlib>

// graphics frame rate (Hz)
const int frame_rate{10};
// derived delta times
const double dt_secs{1.0 / static_cast<double>(frame_rate)};
const int dt_msecs{static_cast<int>(dt_secs * 1000.0)};

TestDisplay* testDisplay{};

// timerFunc() -- time critical stuff
void timerFunc(int)
{
   glutTimerFunc(dt_msecs, timerFunc, 1);

   mixr::base::Timer::updateTimers(dt_secs);
   mixr::graphics::Graphic::flashTimer(dt_secs);
   testDisplay->tcFrame(dt_secs);
}

// our class factory
mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj{};

   //
   if ( name == TestDisplay::getFactoryName() ) {
      obj = new TestDisplay;
   }
   else if ( name == MfdPage::getFactoryName() ) {
      obj = new MfdPage;
   }

   // TestX
   else if ( name == TestOne::getFactoryName() ) {
      obj = new TestOne;
   }

   // TestY
   else if ( name == TestTwo::getFactoryName() ) {
      obj = new TestTwo;
   }
   else if ( name == TdAzPtr::getFactoryName() ) {
      obj = new TdAzPtr;
   }
   else if ( name == TdElevPtr::getFactoryName() ) {
      obj = new TdElevPtr;
   }
   else if ( name == TestRotator::getFactoryName() ) {
      obj = new TestRotator;
   }

   else {
      if (obj == nullptr) obj = mixr::graphics::factory(name);
      if (obj == nullptr) obj = mixr::glut::factory(name);
      if (obj == nullptr) obj = mixr::base::factory(name);
   }
   return obj;
}

// test display builder
TestDisplay* builder(const std::string& filename)
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
   const auto testDisplay = dynamic_cast<TestDisplay*>(obj);
   if (testDisplay == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return testDisplay;
}

int main(int argc, char* argv[])
{
   glutInit(&argc, argv);

   // default configuration filename
   std::string configFilename = "test1.edl";

   // parse arguments
   for (int i = 1; i < argc; i++) {
      if ( std::string(argv[i]) == "-f" ) {
         configFilename = argv[++i];
      }
   }

   // build display
   testDisplay = builder(configFilename);

   // create a display window
   testDisplay->createWindow();

   // start timer to kick off animation
   glutTimerFunc(dt_msecs, timerFunc, 1);

   glutMainLoop();

   return 0;
}
