
#include <QApplication>

#include "MainWindow.hpp"
#include "Station.hpp"

#include "mixr/base/edl_parser.hpp"
#include "mixr/base/Pair.hpp"

// factories
#include "mixr/base/factory.hpp"
#include "mixr/simulation/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/interop/dis/factory.hpp"

#include <cstdlib>
#include <string>

mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj {};

   if ( name == Station::getFactoryName() ) {
      obj = new Station;
   }

   if (obj == nullptr)  { obj = mixr::dis::factory(name);         }
   if (obj == nullptr)  { obj = mixr::simulation::factory(name);  }
   if (obj == nullptr)  { obj = mixr::models::factory(name);  }
   if (obj == nullptr)  { obj = mixr::base::factory(name);        }
   
   return obj;
}

// Station builder
Station* builder(const std::string& filename)
{
   // Read the description file
   int num_errors {};
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
   mixr::base::Pair* pair = dynamic_cast<mixr::base::Pair*>(obj);
   if (pair != nullptr) {
      obj = pair->object();
      obj->ref();
      pair->unref();
   }

   // try to cast to proper object, and check
   Station* station = dynamic_cast<Station*>(obj);
   if (station == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return station;
}

int main(int argc, char* argv[])
{
   // default configuration filename
   std::string configFilename = "test.edl";
   // parse arguments
   for (int i = 1; i < argc; i++) {
      if ( std::string(argv[i]) == "-f" ) {
         configFilename = argv[++i];
      }
   }

   Station* station = builder(configFilename);

   // prime the station
   station->event(mixr::base::Component::RESET_EVENT);

   // create the time critical process
   station->createTimeCriticalProcess();
   station->createWindow(argc, argv);

   return 0;
}
