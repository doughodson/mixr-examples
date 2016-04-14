//------------------------------------------------------------------------------
// Example terrain functions
//------------------------------------------------------------------------------
#include "Display.h"
#include "factory.h"

#include "openeaagles/terrain/ded/DedFile.h"
#include "openeaagles/base/util/system.h"

#include "openeaagles/base/Pair.h"
#include "openeaagles/base/Timers.h"
#include "openeaagles/base/edl_parser.h"
#include "openeaagles/base/functors/Tables.h"
#include "openeaagles/base/units/Angles.h"
#include "openeaagles/graphics/Graphic.h"

#include "openeaagles/gui/glut/GlutDisplay.h"
#include <GL/glut.h>

#include <string>
#include <cstdlib>

namespace oe {
namespace example {

// frame rate
const unsigned int frameRate = 10;

Display* display = nullptr;

// timerFunc() -- time critical stuff
void timerFunc(int)
{
   const double dt = 1.0 / static_cast<double>(frameRate);
   const unsigned int millis = static_cast<unsigned int>(dt * 1000);
   glutTimerFunc(millis, timerFunc, 1);

   base::Timer::updateTimers(static_cast<double>(dt));
   graphics::Graphic::flashTimer(static_cast<double>(dt));
   display->tcFrame(static_cast<double>(dt));
}

// display builder
Display* builder(const std::string& filename)
{
   // read configuration file
   unsigned int num_errors = 0;
   base::Object* obj = base::edl_parser(filename, factory, &num_errors);
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
   base::Pair* pair = dynamic_cast<base::Pair*>(obj);
   if (pair != nullptr) {
      obj = pair->object();
      obj->ref();
      pair->unref();
   }

   // try to cast to proper object, and check
   Display* display = dynamic_cast<Display*>(obj);
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
   std::string configFilename = "test.edl";

   // build a display
   display = builder(configFilename);

   // resetting the system will load the data files
   std::cout << "starting loading files --" << std::endl;
   const double start = base::getComputerTime();

   display->reset();

   const double end = base::getComputerTime();
   const double dtime = (end - start);
   std::cout << "finished loading files: time(s) = " << dtime << std::endl;

   // create a display window
   display->createWindow();

   // set timer
   const double dt = 1.0 / static_cast<double>(frameRate);
   const unsigned int millis = static_cast<unsigned int>(dt * 1000);
   glutTimerFunc(millis, timerFunc, 1);

   glutMainLoop();
   return 0;
}

}
}

//
int main(int argc, char* argv[])
{
   return oe::example::main(argc,argv);
}
