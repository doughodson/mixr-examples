
#include "factory.hpp"

#include "mixr/base/IObject.hpp"

#include "TestDisplay.hpp"
#include "TestIoHandler.hpp"
#include "SimStation.hpp"

#include "xpanel/factory.hpp"

// factories
#include "xzmq/factory.hpp"
#include "mixr/base/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/graphics/fonts/ftgl/factory.hpp"
#include "mixr/interop/dis/factory.hpp"
#include "mixr/instruments/factory.hpp"
#include "mixr/linkage/factory.hpp"
#include "mixr/ighost/cigi/factory.hpp"
#include "mixr/ighost/flightgear/factory.hpp"
#include "mixr/ighost/pov/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/models/dynamics/jsbsim/factory.hpp"
#include "mixr/terrain/factory.hpp"
#include "mixr/simulation/factory.hpp"
#include "mixr/ui/glut/factory.hpp"

#include <string>

mixr::base::IObject* factory(const std::string& name)
{
    mixr::base::IObject* obj{};

    if ( name == SimStation::getFactoryName() ) {
        obj = new SimStation();
    }
    else if ( name == TestDisplay::getFactoryName() ) {
        obj = new TestDisplay();
    }
    else if ( name == TestIoHandler::getFactoryName() ) {
        obj = new TestIoHandler();
    }

    // example libraries
    if (obj == nullptr) obj = mixr::xpanel::factory(name);
    if (obj == nullptr) obj = mixr::xzmq::factory(name);

    // framework libraries
    if (obj == nullptr) obj = mixr::simulation::factory(name);
    if (obj == nullptr) obj = mixr::instruments::factory(name);
    if (obj == nullptr) obj = mixr::linkage::factory(name);
    if (obj == nullptr) obj = mixr::instruments::factory(name);
    if (obj == nullptr) obj = mixr::models::factory(name);
    if (obj == nullptr) obj = mixr::models::jsbsim::factory(name);
    if (obj == nullptr) obj = mixr::terrain::factory(name);
    if (obj == nullptr) obj = mixr::ighost::cigi::factory(name);
    if (obj == nullptr) obj = mixr::ighost::flightgear::factory(name);
    if (obj == nullptr) obj = mixr::ighost::pov::factory(name);
    if (obj == nullptr) obj = mixr::dis::factory(name);
    if (obj == nullptr) obj = mixr::graphics::factory(name);
    if (obj == nullptr) obj = mixr::graphics::ftgl::factory(name);
    if (obj == nullptr) obj = mixr::glut::factory(name);
    if (obj == nullptr) obj = mixr::base::factory(name);

    return obj;
}
