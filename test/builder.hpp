
//-------------------------
// Generic builder template
//-------------------------

#include <string>
#include <iostream>

#include "mixr/base/Pair.hpp"
#include "mixr/base/edl_parser.hpp"

namespace mixr {
namespace base { class Object; }
}

mixr::base::Object* factory(const std::string& name);

template <class T>
T builder(const std::string& filename)
{
   // read configuration file
   int num_errors{};
   mixr::base::IObject* obj{mixr::base::edl_parser(filename, factory, &num_errors)};
   if (num_errors > 0) {
      std::cerr << "File: " << filename << ", number of errors: " << num_errors << std::endl;
      std::exit(EXIT_FAILURE);
   }

   // test to see if an object was created
   if (!obj) {
      std::cerr << "Invalid configuration file, no objects defined!" << std::endl;
      std::exit(EXIT_FAILURE);
   }

   // do we have a base::Pair, if so, point to object in Pair, not Pair itself
   const auto pair = dynamic_cast<mixr::base::Pair*>(obj);
   if (pair) {
      obj = pair->object();
      obj->ref();
      pair->unref();
   }

   // try to cast to proper object, and check
   const auto objT = dynamic_cast<T>(obj);
   if (!objT) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return objT;
}

