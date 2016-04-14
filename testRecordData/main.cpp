
#include "factory.h"

#include "openeaagles/simulation/Station.h"
#include "openeaagles/graphics/Graphic.h"
#include "openeaagles/base/edl_parser.h"
#include "openeaagles/base/Pair.h"
#include "openeaagles/base/Timers.h"
#include "openeaagles/base/util/system.h"

#include <GL/glut.h>

#include <string>
#include <cstdlib>

namespace oe {
namespace test {

// default background frame rate
const unsigned int BG_RATE = 10;

simulation::Station* station = nullptr;

// station builder
simulation::Station* builder(const std::string& filename)
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
   simulation::Station* station = dynamic_cast<simulation::Station*>(obj);
   if (station == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return station;
}

//-----------------------------------------------------------------------------
// Station's background tasks -- a callback from a GLUT timer, it's basically the
// top level of our background thread.  (Note: GlutDisplay will handle the
// background thread, updateData, for all of its graphics components)
//-----------------------------------------------------------------------------
void updateDataCB(int msecs)
{
   glutTimerFunc(msecs, updateDataCB, msecs);

   // Current time
   const double time = base::getComputerTime();

   // Compute delta time
   static double time0 = time;   // N-1 Time
   const double dt = static_cast<double>(time - time0);
   time0 = time;

   station->updateData(dt);
}

//
int main(int argc, char* argv[])
{
   glutInit(&argc, argv);

   // default configuration filename
   std::string configFilename = "test.edl";

   // parse arguments
   for (int i = 1; i < argc; i++) {
      if ( std::string(argv[i]) == "-f" ) {
         configFilename = argv[++i];
      }
   }

   // build a station
   station = builder(configFilename);

   // reset the Simulation
   station->event(base::Component::RESET_EVENT);

   // set timer for the background tasks
   const double dt = 1.0 / static_cast<double>(BG_RATE);
   const int msecs = static_cast<int>(dt * 1000);

   // ensure everything is reset
   station->updateData(dt);
   station->updateTC(dt);
   station->event(base::Component::RESET_EVENT);

   glutTimerFunc(msecs, updateDataCB, msecs);

   // create the time critical thread
   station->createTimeCriticalProcess();

   // main loop
   glutMainLoop();
   return EXIT_SUCCESS;
}

}
}

//
int main(int argc, char* argv[])
{
   return oe::test::main(argc, argv);
}
