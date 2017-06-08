
#include "factory.hpp"

#include "mxrp/base/Object.hpp"

#include "Display.hpp"
#include "RealBeamRadar.hpp"
#include "TestStation.hpp"

// factories
#include "mxrp/simulation/factory.hpp"
#include "mxrp/models/factory.hpp"
#include "mxrp/terrain/factory.hpp"
#include "mxrp/graphics/factory.hpp"
#include "mxrp/gui/glut/factory.hpp"
#include "mxrp/base/factory.hpp"

#include <string>

mxrp::base::Object* factory(const std::string& name)
{
    mxrp::base::Object* obj = nullptr;

    if ( name == Display::getFactoryName() ) {
        obj = new Display();
    }
    else if ( name == RealBeamRadar::getFactoryName() ) {
        obj = new RealBeamRadar();
    }
    else if ( name == TestStation::getFactoryName() ) {
        obj = new TestStation();
    }

    if (obj == nullptr) obj = mxrp::simulation::factory(name);
    if (obj == nullptr) obj = mxrp::models::factory(name);
    if (obj == nullptr) obj = mxrp::terrain::factory(name);
    if (obj == nullptr) obj = mxrp::graphics::factory(name);
    if (obj == nullptr) obj = mxrp::glut::factory(name);
    if (obj == nullptr) obj = mxrp::base::factory(name);

    return obj;
}
