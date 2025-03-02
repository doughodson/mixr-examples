
#include "factory.hpp"

#include "mixr/base/IObject.hpp"

#include "TestDisplay.hpp"
#include "SimStation.hpp"

// factories
#include "shared/xbehaviors/factory.hpp"
#include "shared/xpanel/factory.hpp"

#include "mixr/base/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/graphics/fonts/ftgl/factory.hpp"
#include "mixr/ui/glut/factory.hpp"
#include "mixr/interop/dis/factory.hpp"
#include "mixr/instruments/factory.hpp"
#include "mixr/ighost/cigi/factory.hpp"
#include "mixr/ighost/flightgear/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/models/dynamics/jsbsim/factory.hpp"
#include "mixr/simulation/factory.hpp"
#include "mixr/terrain/factory.hpp"

#include <string>

mixr::base::IObject* factory(const std::string& name)
{
    mixr::base::IObject* obj {};

    if ( name == SimStation::getFactoryName() ) {
        obj = new SimStation();
    }
    else if ( name == TestDisplay::getFactoryName() ) {
        obj = new TestDisplay();
    }

    // Example library packages
    if (obj == nullptr) obj = mixr::xbehaviors::factory(name);
    if (obj == nullptr) obj = mixr::xpanel::factory(name);

    // MIXR packages
    if (obj == nullptr) obj = mixr::simulation::factory(name);
    if (obj == nullptr) obj = mixr::instruments::factory(name);
    if (obj == nullptr) obj = mixr::instruments::factory(name);
    if (obj == nullptr) obj = mixr::models::factory(name);
    if (obj == nullptr) obj = mixr::models::jsbsim::factory(name);
    if (obj == nullptr) obj = mixr::terrain::factory(name);
    if (obj == nullptr) obj = mixr::cigi::factory(name);
    if (obj == nullptr) obj = mixr::flightgear::factory(name);
    if (obj == nullptr) obj = mixr::dis::factory(name);
    if (obj == nullptr) obj = mixr::graphics::factory(name);
    if (obj == nullptr) obj = mixr::graphics::ftgl::factory(name);
    if (obj == nullptr) obj = mixr::glut::factory(name);
    if (obj == nullptr) obj = mixr::base::factory(name);

    return obj;
}
