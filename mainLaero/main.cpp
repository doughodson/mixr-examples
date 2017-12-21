//--------------------------------------------------------------
// Example that demonstrates Laero model functionality
//--------------------------------------------------------------

#include "mixr/graphics/Graphic.hpp"
#include "mixr/base/edl_parser.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/Timers.hpp"
#include "mixr/simulation/Station.hpp"
#include "mixr/base/util/system_utils.hpp"

#include "factory.hpp"

#include <GL/glut.h>
#include <string>
#include <cstdlib>

// background frame rate
const int bgRate{10};
mixr::simulation::Station* station{};

// station builder
mixr::simulation::Station* builder(const std::string& filename)
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
   const auto station = dynamic_cast<mixr::simulation::Station*>(obj);
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
void updateDataCB(int)
{
   const double dt0{1.0 / static_cast<double>(bgRate)};
   const int millis{static_cast<int>(dt0 * 1000)};
   glutTimerFunc(millis, updateDataCB, 1);

   // current time
   const double time{mixr::base::getComputerTime()};

   // N-1 Time
   static double time0{time};

   // compute delta time
   const double dt{time - time0};
   time0 = time;

   station->updateData(dt);
}

//
int main(int argc, char* argv[])
{
   glutInit(&argc, argv);

   // default configuration filename
   std::string configFilename = "test.edl";

   // parse command arguments
   for (int i=1; i<argc; i++) {
      if ( std::string(argv[i]) == "-f" ) {
         configFilename = argv[++i];
      }
   }

   // build a station
   station = builder(configFilename);

   // reset the simulation
   station->event(mixr::base::Component::RESET_EVENT);

   // create the time critical thread
   station->createTimeCriticalProcess();

   // set timer for the background tasks
   const double dt{1.0 / static_cast<double>(bgRate)};
   const int millis{static_cast<int>(dt * 1000)};

   // ensure everything is reset
   station->updateData(dt);
   station->event(mixr::base::Component::RESET_EVENT);

   glutTimerFunc(millis, updateDataCB, 1);

   // main loop to update graphics
   glutMainLoop();

   return 0;
}
