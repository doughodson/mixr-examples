//------------------------------------------------------------------------------
// Example terrain functions
//------------------------------------------------------------------------------
#include "Display.hpp"
#include "factory.hpp"

#include "mixr/terrain/ded/DedFile.hpp"
#include "mixr/base/util/system_utils.hpp"

#include "mixr/base/Pair.hpp"
#include "mixr/base/Timers.hpp"
#include "mixr/base/edl_parser.hpp"
#include "mixr/base/units/Angles.hpp"
#include "mixr/graphics/Graphic.hpp"

#include "mixr/ui/glut/GlutDisplay.hpp"
#include <GL/glut.h>

#include <string>
#include <cstdlib>

const int frameRate{10};
Display* display{};

// timerFunc() -- time critical stuff
void timerFunc(int)
{
   const double dt{1.0 / static_cast<double>(frameRate)};
   const int millis{static_cast<int>(dt * 1000)};
   glutTimerFunc(millis, timerFunc, 1);

   mixr::base::Timer::updateTimers(static_cast<double>(dt));
   mixr::graphics::Graphic::flashTimer(static_cast<double>(dt));
   display->tcFrame(static_cast<double>(dt));
}

// display builder
Display* builder(const std::string& filename)
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
   const auto display = dynamic_cast<Display*>(obj);
   if (display == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return display;
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);

   // default configuration filename
   std::string configFilename = "test.edl";

   // build a display
   display = builder(configFilename);

   // resetting the system will load the data files
   std::cout << "starting loading files --" << std::endl;
   const double start{mixr::base::getComputerTime()};

   display->reset();

   const double end{mixr::base::getComputerTime()};
   const double dtime{end - start};
   std::cout << "finished loading files: time(s) = " << dtime << std::endl;

   // create a display window
   display->createWindow();

   // set timer
   const double dt{1.0 / static_cast<double>(frameRate)};
   const int millis{static_cast<int>(dt * 1000)};
   glutTimerFunc(millis, timerFunc, 1);

   glutMainLoop();
   return 0;
}
