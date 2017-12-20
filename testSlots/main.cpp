
#include <iostream>
#include <string>

#include "mixr/base/Pair.hpp"
#include "mixr/base/edl_parser.hpp"

// factories
#include "mixr/base/factory.hpp"

#include "Base.hpp"
#include "Derived.hpp"

// class factory
mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj{};

   // application classes
   if ( name == Base::getFactoryName() ) {
      obj = new Base;
   }
   if ( name == Derived::getFactoryName() ) {
      obj = new Derived;
   }

   // platform classes
   if (obj == nullptr) obj = mixr::base::factory(name);
   return obj;
}

// builder
Base* builder(const std::string& filename)
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
   const auto base = dynamic_cast<Base*>(obj);
   if (base == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return base;
}

int main(int argc, char* argv[])
{
   // default configuration filename
   std::string configFilename = "file0.edl";

   Base* base{builder(configFilename)};

   base->unref();

   return 0;
}
