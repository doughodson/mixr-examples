
#include <iostream>
#include <string>
#include <cstdlib>
#include <memory>

#include "mixr/base/colors/Color.hpp"

#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"
#include "mixr/base/edl_parser.hpp"
#include "mixr/base/String.hpp"

// factories
#include "mixr/base/factory.hpp"

#include "MyObj.hpp"

// our class factory
mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj{};

   // look in application's classes
   if ( name == MyObj::getFactoryName() ) {
      obj = new MyObj;
   }
   // look in base classes
   if (obj == nullptr) obj = mixr::base::factory(name);
   return obj;
}

// MyObj builder
MyObj* builder(const std::string& filename)
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
   const auto myObj = dynamic_cast<MyObj*>(obj);
   if (myObj == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return myObj;
}

int main(int argc, char* argv[])
{
   // default configuration filename
   std::string configFilename = "file0.edl";

   // build my object
   MyObj* myObj{builder(configFilename)};
   // print/dump contents to console
   myObj->dumpContents();
   // unref/delete
   myObj->unref();

   return 0;
}
