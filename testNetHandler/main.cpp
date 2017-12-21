//-----------------------------------------------------------------------------
// Test NetHandler functionality
//-----------------------------------------------------------------------------

#include "Endpoint.hpp"
#include "Sender.hpp"
#include "Echo.hpp"

#include "mixr/base/edl_parser.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/util/system_utils.hpp"

// factories
#include "mixr/base/factory.hpp"
#include "../shared/xzmq/factory.hpp"

#include <string>
#include <cstdlib>

const int UPDATE_RATE{10};  // main loop update rate (Hz)

mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj{};

   if ( name == Sender::getFactoryName() ) {
      obj = new Sender();
   } else if ( name == Echo::getFactoryName() ) {
      obj = new Echo();
   }

   // example libraries
   if (obj == nullptr) obj = mixr::xzmq::factory(name);
   // framework libraries
   if (obj == nullptr) obj = mixr::base::factory(name);

   return obj;
}

// endpoint builder
Endpoint* builder(const std::string& filename)
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
   const auto endpoint = dynamic_cast<Endpoint*>(obj);
   if (endpoint == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return endpoint;
}

//
int main(int argc, char* argv[])
{
   // default configuration filename
   std::string configFilename = "configs/senderUdpBroadcast.edl";
   // parse command line arguments
   for (int i = 1; i < argc; i++) {
      if ( std::string(argv[i]) == "-f" ) {
         configFilename = argv[++i];
      }
   }

   // build an endpoint
   Endpoint* endpoint{builder(configFilename)};

   // send a reset event
   std::cout << "Reset event: which will establish the networks." << std::endl;
   endpoint->event(mixr::base::Component::RESET_EVENT);

   // system time of day
   const double dt{1.0 / static_cast<double>(UPDATE_RATE)};   // Delta time
   double simTime{};                                          // Simulator time reference
   double startTime{mixr::base::getComputerTime()};           // Time of day (sec) run started

   // main loop
   std::cout << "Starting main loop ..." << std::endl;
   for(;;) {

      endpoint->updateTC( static_cast<double>(dt) );
      endpoint->updateData( static_cast<double>(dt) );

      simTime += dt;                                  // time of next frame
      double timeNow{mixr::base::getComputerTime()};  // time now

      double elapsedTime{timeNow - startTime};
      double nextFrameStart{simTime - elapsedTime};
      const int sleepTime{static_cast<int>(nextFrameStart*1000.0)};

      // wait for the next frame
      if (sleepTime > 0)
         mixr::base::msleep(sleepTime);
   }

   return 0;
}
