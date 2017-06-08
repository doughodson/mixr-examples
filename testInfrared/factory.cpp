
#include "factory.hpp"

#include "mxrp/base/Object.hpp"

#include "TestDisplay.hpp"
#include "TestStation.hpp"
#include "TestComputer.hpp"

// factories
#include "mxrp/base/factory.hpp"
#include "mxrp/graphics/factory.hpp"
#include "mxrp/instruments/factory.hpp"
#include "mxrp/gui/glut/factory.hpp"
#include "mxrp/simulation/factory.hpp"
#include "mxrp/models/factory.hpp"
#include "mxrp/terrain/factory.hpp"
#include "mxrp/interop/dis/factory.hpp"
#include "mxrp/otw/factory.hpp"

#include <string>

mxrp::base::Object* factory(const std::string& name)
{
    mxrp::base::Object* obj = nullptr;

   if ( name == TestStation::getFactoryName() ) {
      obj = new TestStation;
   }
   else if ( name == TestDisplay::getFactoryName() ) {
      obj = new TestDisplay;
   }
   else if ( name == TestComputer::getFactoryName() ) {
      obj = new TestComputer;
   }

   if (obj == nullptr) obj = mxrp::otw::factory(name);
   if (obj == nullptr) obj = mxrp::simulation::factory(name);
   if (obj == nullptr) obj = mxrp::models::factory(name);
   if (obj == nullptr) obj = mxrp::terrain::factory(name);
   if (obj == nullptr) obj = mxrp::dis::factory(name);
   if (obj == nullptr) obj = mxrp::instruments::factory(name);
   if (obj == nullptr) obj = mxrp::graphics::factory(name);
   if (obj == nullptr) obj = mxrp::glut::factory(name);
   if (obj == nullptr) obj = mxrp::base::factory(name);

   return obj;
}
