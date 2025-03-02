
#include "factory.hpp"

#include "SimStation.hpp"
#include "SimpleIGen.hpp"

#include "mixr/base/IObject.hpp"

#include "mixr/base/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/ui/glut/factory.hpp"

#include <string>

using namespace mixr;

base::IObject* factory(const std::string& name)
{
   base::IObject* obj{};

   if (name == SimpleIGen::getFactoryName()) {
      obj = new SimpleIGen;
   }
   else if ( name == SimStation::getFactoryName()) {
      obj = new SimStation();
   }

   // platform libraries
   if (obj == nullptr) obj = graphics::factory(name);
   if (obj == nullptr) obj = glut::factory(name);
   if (obj == nullptr) obj = base::factory(name);

   return obj;
}

