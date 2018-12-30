
#include "mixr/base/edl_parser.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/units/angles.hpp"

// factories
#include "mixr/base/factory.hpp"

#include "mixr/graphics/readouts/readout_utils.hpp"

#include <string>
#include <cstdlib>

void testReadouts();

using namespace mixr;

mixr::base::Object* factory(const std::string& name)
{
   // base library
   mixr::base::Object* obj{mixr::base::factory(name)};
   return obj;
}

// Object builder
mixr::base::Object* builder(const std::string& filename)
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

   return obj;
}

void testFileReader()
{
   // default configuration filename
   std::string configFilename = "testFileReader.edl";

   return;
}

int main(int argc, char* argv[])
{
   testReadouts();
   return 0;
}
