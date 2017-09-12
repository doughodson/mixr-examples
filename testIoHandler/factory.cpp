
#include "factory.hpp"

#include "mixr/base/Object.hpp"

#include "Display.hpp"
#include "Table.hpp"

// factories
#include "mixr/iodevice/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/base/factory.hpp"
#include "mixr/ui/glut/factory.hpp"

#include <string>

mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj {};

   if ( name == Display::getFactoryName() ) {
      obj = new Display();
   }
   else if ( name == Table::getFactoryName() ) {
      obj = new Table();
   }

   if (obj == nullptr) obj = mixr::iodevice::factory(name);
   if (obj == nullptr) obj = mixr::glut::factory(name);
   if (obj == nullptr) obj = mixr::graphics::factory(name);
   if (obj == nullptr) obj = mixr::base::factory(name);

    return obj;
}
