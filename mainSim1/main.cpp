
#include "mixr/simulation/Station.hpp"
#include "mixr/base/edl_parser.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/numeric/Integer.hpp"
#include "mixr/base/units/Angles.hpp"
#include "mixr/base/util/system_utils.hpp"

// factories
#include "../shared/xzmq/factory.hpp"
#include "mixr/simulation/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/interop/dis/factory.hpp"
#include "mixr/ighost/cigi/factory.hpp"
#include "mixr/ighost/pov/factory.hpp"
#include "mixr/terrain/factory.hpp"
#include "mixr/base/factory.hpp"

#include <string>
#include <cstdlib>

// background frame rate
const int bgRate{10};

mixr::base::Object* factory(const std::string& name)
{
   // example libraries
   mixr::base::Object* obj{mixr::xzmq::factory(name)};

   // framework libraries
   if (obj == nullptr) obj = mixr::cigi::factory(name);
   if (obj == nullptr) obj = mixr::pov::factory(name);
   if (obj == nullptr) obj = mixr::simulation::factory(name);
   if (obj == nullptr) obj = mixr::models::factory(name);
   if (obj == nullptr) obj = mixr::terrain::factory(name);
   if (obj == nullptr) obj = mixr::dis::factory(name);
   if (obj == nullptr) obj = mixr::base::factory(name);
   return obj;
}

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

int main(int argc, char* argv[])
{
   // default configuration filename
   std::string configFilename = "test0.edl";

   for (int i = 1; i < argc; i++) {
      if ( std::string(argv[i]) == "-f" ) {
         configFilename = argv[++i];
      }
   }

   // build Station
   mixr::simulation::Station* station{builder(configFilename)};

   // send a reset event and frame sim once
   station->event(mixr::base::Component::RESET_EVENT);
   station->tcFrame( static_cast<double>(1.0/static_cast<double>(station->getTimeCriticalRate())) );

   // create time critical thread
   station->createTimeCriticalProcess();
   // short pause to allow os to startup thread
   mixr::base::msleep(1000);

   // calc delta time for background thread
   const double dt{1.0/static_cast<double>(bgRate)};

   // system Time of Day
   double simTime{};                                        // Simulator time reference
   const double startTime{mixr::base::getComputerTime()};   // Time of day (sec) run started

   int k {};
   std::cout << "Starting background main loop ..." << std::endl;
   for(;;) {

      // update background thread
      station->updateData( static_cast<double>(dt) );

      simTime += dt;                                         // time of next frame
      const double timeNow{mixr::base::getComputerTime()};  // time now
      const double elapsedTime{timeNow - startTime};
      const double nextFrameStart{simTime - elapsedTime};
      const int sleepTime{static_cast<int>(nextFrameStart * 1000.0)};

      // wait for the next frame
      if (sleepTime > 0)
         mixr::base::msleep(sleepTime);

      std::cout << "." << std::flush;
      k += 1;
      if ( k == 40 ) {
         std::cout << "\n";
         k = 0;
      }
   }
   return 0;
}
