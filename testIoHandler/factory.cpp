
#include "factory.hpp"

#include "mxrp/base/Object.hpp"

#include "Display.hpp"
#include "Table.hpp"

// factories
#include "mxrp/iodevice/factory.hpp"
#include "mxrp/gui/glut/factory.hpp"
#include "mxrp/graphics/factory.hpp"
#include "mxrp/base/factory.hpp"

#include <string>

mxrp::base::Object* factory(const std::string& name)
{
   mxrp::base::Object* obj = nullptr;

   if ( name == Display::getFactoryName() ) {
      obj = new Display();
   }
   else if ( name == Table::getFactoryName() ) {
      obj = new Table();
   }

   if (obj == nullptr) obj = mxrp::iodevice::factory(name);
   if (obj == nullptr) obj = mxrp::glut::factory(name);
   if (obj == nullptr) obj = mxrp::graphics::factory(name);
   if (obj == nullptr) obj = mxrp::base::factory(name);

    return obj;
}
