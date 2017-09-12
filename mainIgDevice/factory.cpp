
#include "factory.hpp"

#include "SimStation.hpp"
#include "SimpleIGen.hpp"

#include "mixr/base/Object.hpp"
#include "mixr/base/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/ui/glut/factory.hpp"
#include "mixr/interop/dis/factory.hpp"
#include "mixr/instruments/factory.hpp"
#include "mixr/iodevice/factory.hpp"
#include "mixr/ig/viewpoint/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/simulation/factory.hpp"

#include <string>

using namespace mixr;

base::Object* factory(const std::string& name)
{
   base::Object* obj {};

   if (name == SimpleIGen::getFactoryName()) {
      obj = new SimpleIGen;
   }
   else if ( name == SimStation::getFactoryName()) {
      obj = new SimStation();
   }

   // platform libraries
   if (obj == nullptr) obj = simulation::factory(name);
   if (obj == nullptr) obj = models::factory(name);
   if (obj == nullptr) obj = instruments::factory(name);
   if (obj == nullptr) obj = iodevice::factory(name);
   if (obj == nullptr) obj = models::factory(name);
   if (obj == nullptr) obj = viewpoint::factory(name);
   if (obj == nullptr) obj = dis::factory(name);
   if (obj == nullptr) obj = graphics::factory(name);
   if (obj == nullptr) obj = glut::factory(name);
   if (obj == nullptr) obj = base::factory(name);

   return obj;
}

