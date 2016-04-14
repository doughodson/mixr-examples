
#include <iostream>
#include <string>
#include <cstdlib>

#include "openeaagles/base/Pair.h"
#include "openeaagles/base/edl_parser.h"

// factories
#include "openeaagles/base/factory.h"

#include "Uniform.h"
#include "Exp.h"

namespace oe {
namespace tutorial {

Random* random = nullptr;

// our class factory
base::Object* factory(const std::string& name)
{
   base::Object* obj = nullptr;

   // look in application's classes
   if ( name == Uniform::getFactoryName() ) {
      obj = new Uniform();
   }
   else if ( name == Exp::getFactoryName() ) {
      obj = new Exp();
   }

   // look in base classes
   if (obj == nullptr) obj = base::factory(name);

   return obj;
}

// random builder
Random* builder(const std::string& filename)
{
   // read configuration file
   unsigned int num_errors = 0;
   base::Object* obj = base::edl_parser(filename, factory, &num_errors);
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
   base::Pair* pair = dynamic_cast<base::Pair*>(obj);
   if (pair != nullptr) {
      obj = pair->object();
      obj->ref();
      pair->unref();
   }

   // try to cast to proper object, and check
   Random* random = dynamic_cast<Random*>(obj);
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
   random = builder(configFilename);

   for (unsigned int i=0; i<10; i++) {
      std::cout << random->getNum() << std::endl;
   }

   random->unref();

   return 0;
}

} // namespace tutorial
} // namespace oe

//
int main(int argc, char* argv[])
{
  oe::tutorial::main(argc, argv);
}
