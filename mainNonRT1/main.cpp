
#include "mixr/simulation/Simulation.hpp"
#include "mixr/base/edl_parser.hpp"
#include "mixr/base/Pair.hpp"

// factories
#include "mixr/simulation/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/terrain/factory.hpp"
#include "mixr/base/factory.hpp"

#include <string>
#include <cstdlib>

// frame rate (50 Hz)
const int frameRate{50};

// class factory
mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj{mixr::simulation::factory(name)};
   if (obj == nullptr) obj = mixr::models::factory(name);
   if (obj == nullptr) obj = mixr::terrain::factory(name);
   if (obj == nullptr) obj = mixr::base::factory(name);
   return obj;
}

// simulation builder
mixr::simulation::Simulation* builder(const std::string& filename)
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
   const auto simulation = dynamic_cast<mixr::simulation::Simulation*>(obj);
   if (simulation == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return simulation;
}

int main(int argc, char* argv[])
{
   // default configuration filename
   std::string configFilename = "test1.edl";

   // read filename from command line if provided
   for (int i = 1; i < argc; i++) {
      if ( std::string(argv[i]) == "-f" ) {
         configFilename = argv[++i];
      }
   }

   // build simulation
   mixr::simulation::Simulation* simulation{builder(configFilename)};

   // reset component tree
   simulation->reset();

   // delta time (20ms)
   const double dt{1.0 / static_cast<double>(frameRate)};

   // execute simulation as fast as possible
   for(; simulation->getExecTimeSec() < 50.0; ) {
      // print out simulation time
      std::cout << simulation->getExecTimeSec() << std::endl;
      // execute timestep
      simulation->tcFrame( dt );
      simulation->updateData( dt );
   }
   return 0;
}
