
#include "factory.hpp"

#include "mixr/base/Object.hpp"

#include "TestIoDisplay.hpp"
#include "Table.hpp"
#include "TestIoHandler.hpp"

// factories
#include "mixr/linkage/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/base/factory.hpp"
#include "mixr/ui/glut/factory.hpp"

#include <string>

mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj {};

   if ( name == TestIoDisplay::getFactoryName() ) {
      obj = new TestIoDisplay();
   }
   else if ( name == Table::getFactoryName() ) {
      obj = new Table();
   }
   else if ( name == TestIoHandler::getFactoryName() ) {
      obj = new TestIoHandler();
   }

   if (obj == nullptr) obj = mixr::linkage::factory(name);
   if (obj == nullptr) obj = mixr::glut::factory(name);
   if (obj == nullptr) obj = mixr::graphics::factory(name);
   if (obj == nullptr) obj = mixr::base::factory(name);

    return obj;
}
