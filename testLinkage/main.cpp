//----------------------------------------------------------------
// I/O device test program
//----------------------------------------------------------------
#include "TestIoDisplay.hpp"
#include "factory.hpp"

#include "mixr/base/Pair.hpp"
#include "mixr/base/Timers.hpp"
#include "mixr/base/edl_parser.hpp"

#include <GL/glut.h>

#include <string>
#include <cstdlib>

const int frameRate{20};
TestIoDisplay* display{};

// timerFunc() -- Time critical stuff)
void timerFunc(int)
{
   const double dt{1.0 / static_cast<double>(frameRate)};
   const int millis{static_cast<int>(dt * 1000)};
   glutTimerFunc(millis, timerFunc, 1);

   mixr::base::Timer::updateTimers(dt);
   mixr::graphics::Graphic::flashTimer(dt);
   display->updateTC(dt);
}

// display builder
TestIoDisplay* builder(const std::string& filename)
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
   const auto display = dynamic_cast<TestIoDisplay*>(obj);
   if (display == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return display;
}

//
int main(int argc, char* argv[])
{
   glutInit(&argc, argv);

   // default configuration filename
   std::string configFilename{"test1.edl"};
   // parse arguments
   for (int i{1}; i < argc; i++) {
      if ( std::string(argv[i]) == "-f" ) {
         configFilename = argv[++i];
      }
   }

   // build a display
   display = builder(configFilename);

   // create a display window
   display->createWindow();

   // reset the system
   display->reset();

   // set timer
   const double dt{1.0 / static_cast<double>(frameRate)};
   const int millis{static_cast<int>(dt * 1000)};
   glutTimerFunc(millis, timerFunc, 1);

   // main loop
   glutMainLoop();
   return 0;
}
