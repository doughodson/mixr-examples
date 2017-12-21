
#include "DataRecordTest.hpp"

#include "mixr/base/edl_parser.hpp"
#include "mixr/base/Pair.hpp"

#include "mixr/simulation/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/base/factory.hpp"
#include "mixr/recorder/factory.hpp"

#include <string>
#include <cstdlib>

mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj{};

   if ( name == DataRecordTest::getFactoryName() ) {
      obj = new DataRecordTest();
   } else {
      if (obj == nullptr) obj = mixr::simulation::factory(name);
      if (obj == nullptr) obj = mixr::models::factory(name);
      if (obj == nullptr) obj = mixr::base::factory(name);
      if (obj == nullptr) obj = mixr::recorder::factory(name);
   }

   return obj;
}

DataRecordTest* builder(const std::string& filename)
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

   // do we have a mixr::base::Pair, if so, point to object in Pair, not Pair itself
   const auto pair = dynamic_cast<mixr::base::Pair*>(obj);
   if (pair != nullptr) {
      obj = pair->object();
      obj->ref();
      pair->unref();
   }

   // try to cast to proper object, and check
   const auto dataRecordTest = dynamic_cast<DataRecordTest*>(obj);
   if (dataRecordTest == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return dataRecordTest;
}

int main(int argc, char* argv[])
{
   // default configuration filename
   std::string configFilename = "test.edl";
   // parse command line arguments
   for (int i = 1; i < argc; i++) {
      if ( std::string(argv[i]) == "-f" ) {
         configFilename = argv[++i];
      }
   }

   // build data recorder test
   DataRecordTest* dataRecordTest{builder(configFilename)};

   // Start test (we don't come back!)
 //  dataRecordTest->testEvents();
   dataRecordTest->testSerialize();
 //  dataRecordTest->testSelect();

   return 0;
}
