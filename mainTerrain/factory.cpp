
#include "factory.hpp"

#include "mixr/base/IObject.hpp"

#include "Display.hpp"

#include "mixr/terrain/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/ui/glut/factory.hpp"
#include "mixr/base/factory.hpp"

#include <string>

mixr::base::IObject* factory(const std::string& name)
{
    mixr::base::IObject* obj {};

    if ( name == Display::getFactoryName() ) {
        obj = new Display();
    }

    if (obj == nullptr) obj = mixr::terrain::factory(name);
    if (obj == nullptr) obj = mixr::graphics::factory(name);
    if (obj == nullptr) obj = mixr::glut::factory(name);
    if (obj == nullptr) obj = mixr::base::factory(name);

    return obj;
}
