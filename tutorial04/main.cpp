
#include <iostream>
#include <string>
#include <cstdlib>

#include "mixr/base/Pair.hpp"
#include "mixr/base/edl_parser.hpp"

// factories
#include "mixr/base/factory.hpp"

#include "rngs/AbstractRng.hpp"
#include "rngs/Exponential.hpp"
#include "rngs/Lognormal.hpp"
#include "rngs/Uniform.hpp"

// class factory
mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj{};

   // look in application's classes
   if ( name == Exponential::getFactoryName() ) {
      obj = new Exponential();
   } else if ( name == Lognormal::getFactoryName() ) {
      obj = new Lognormal();
   } else if ( name == Uniform::getFactoryName() ) {
      obj = new Uniform();
   }

   // look in base classes
   if (obj == nullptr) obj = mixr::base::factory(name);

   return obj;
}

// random builder
AbstractRng* builder(const std::string& filename)
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
   const auto random = dynamic_cast<AbstractRng*>(obj);
   if (random == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return random;
}

int main(int argc, char* argv[])
{
   // default configuration filename
   std::string configFilename = "file0.edl";

   // build random
   AbstractRng* rng{builder(configFilename)};

   for (int i=0; i<10; i++) {
      std::cout << rng->num() << std::endl;
   }

   rng->unref();

   return 0;
}
