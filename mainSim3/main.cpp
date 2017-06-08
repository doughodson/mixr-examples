
#include "mxrp/base/Pair.hpp"
#include "mxrp/base/Timers.hpp"
#include "mxrp/base/edl_parser.hpp"

#include "mxrp/gui/glut/GlutDisplay.hpp"
#include <GL/glut.h>
#include "mxrp/base/util/system_utils.hpp"

// factories
#include "../shared/xzmq/factory.hpp"
#include "mxrp/gui/glut/factory.hpp"
#include "mxrp/base/factory.hpp"
#include "mxrp/graphics/factory.hpp"
#include "mxrp/instruments/factory.hpp"
#include "mxrp/simulation/factory.hpp"
#include "mxrp/models/factory.hpp"
#include "mxrp/terrain/factory.hpp"
#include "mxrp/interop/dis/factory.hpp"
#include "mxrp/otw/factory.hpp"

#include "MapPage.hpp"
#include "Station.hpp"
#include "Display.hpp"

#include <string>
#include <cstdlib>

// frame rate
const unsigned int frameRate = 20;

Station* station = nullptr;

// timer function, in this case, the background (updateData) function
void timerFunc(int)
{
    const double dt0 = 1.0 / static_cast<double>(frameRate);
    const auto millis = static_cast<unsigned int>(dt0 * 1000);
    glutTimerFunc(millis, timerFunc, 1);

    // Current time
    const double time = mxrp::base::getComputerTime();

    // N-1 Time
    static double time0 = time;

    // Compute delta time
    const double dt = static_cast<double>(time - time0);
    time0 = time;

    mxrp::base::Timer::updateTimers(dt);
    mxrp::graphics::Graphic::flashTimer(dt);
    station->updateData(dt);
}

// our class factory
mxrp::base::Object* factory(const std::string& name)
{
    mxrp::base::Object* obj = nullptr;

    if ( name == MapPage::getFactoryName() )       { obj = new MapPage(); }
    else if ( name == Station::getFactoryName() )  { obj = new Station(); }
    else if ( name == Display::getFactoryName() )  { obj = new Display(); }

    // example libraries
    if (obj == nullptr)  { obj = mxrp::xzmq::factory(name);         }

    // framework libraries
    if (obj == nullptr)  { obj = mxrp::otw::factory(name);          }
    if (obj == nullptr)  { obj = mxrp::instruments::factory(name);  }
    if (obj == nullptr)  { obj = mxrp::simulation::factory(name);   }
    if (obj == nullptr)  { obj = mxrp::models::factory(name);       }
    if (obj == nullptr)  { obj = mxrp::terrain::factory(name);      }
    if (obj == nullptr)  { obj = mxrp::dis::factory(name);          }
    if (obj == nullptr)  { obj = mxrp::graphics::factory(name);     }
    if (obj == nullptr)  { obj = mxrp::glut::factory(name);         }
    if (obj == nullptr)  { obj = mxrp::base::factory(name);         }

    return obj;
}

// station builder
Station* builder(const std::string& filename)
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
   const auto station = dynamic_cast<Station*>(obj);
   if (station == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return station;
}

//
int main(int argc, char* argv[])
{
   glutInit(&argc, argv);

   // default configuration filename
   std::string configFilename = "test.edl";

   // build a station
   station = builder(configFilename);

   // reset the Simulation
   station->event(mxrp::base::Component::RESET_EVENT);

   // set timer for the background tasks
   const double dt = 1.0 / static_cast<double>(frameRate);
   const auto millis = static_cast<unsigned int>(dt * 1000);

   // ensure everything is reset
   station->updateData(dt);
   station->updateTC(dt);
   station->event(mxrp::base::Component::RESET_EVENT);

   glutTimerFunc(millis, timerFunc, 1);

   // create the Time Critical Thread (updateTC())
   station->createTimeCriticalProcess();

   glutMainLoop();
   return 0;
}
