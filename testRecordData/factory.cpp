
#include "factory.hpp"

#include "mixr/base/Object.hpp"

#include "TestDisplay.hpp"
#include "TestIoHandler.hpp"
#include "SimStation.hpp"

#include "xrecorder/factory.hpp"
#include "xpanel/factory.hpp"

#include "mixr/base/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/interop/dis/factory.hpp"
#include "mixr/instruments/factory.hpp"
#include "mixr/linkage/factory.hpp"
#include "mixr/ighost/cigi/factory.hpp"
#include "mixr/ighost/pov/factory.hpp"
#include "mixr/recorder/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/simulation/factory.hpp"
#include "mixr/ui/glut/factory.hpp"

#include <string>

mixr::base::Object* factory(const std::string& name)
{
    mixr::base::Object* obj {};

    if ( name == SimStation::getFactoryName() ) {
        obj = new SimStation();
    }
    else if ( name == TestDisplay::getFactoryName() ) {
        obj = new TestDisplay();
    }
    else if ( name == TestIoHandler::getFactoryName() ) {
        obj = new TestIoHandler();
    }

    // Example libraries
    if (obj == nullptr) obj = mixr::xrecorder::factory(name);
    if (obj == nullptr) obj = mixr::xpanel::factory(name);

    // MIXR packages
    if (obj == nullptr) obj = mixr::simulation::factory(name);
    if (obj == nullptr) obj = mixr::instruments::factory(name);
    if (obj == nullptr) obj = mixr::linkage::factory(name);
    if (obj == nullptr) obj = mixr::instruments::factory(name);
    if (obj == nullptr) obj = mixr::recorder::factory(name);
    if (obj == nullptr) obj = mixr::models::factory(name);
    if (obj == nullptr) obj = mixr::cigi::factory(name);
    if (obj == nullptr) obj = mixr::pov::factory(name);
    if (obj == nullptr) obj = mixr::dis::factory(name);
    if (obj == nullptr) obj = mixr::graphics::factory(name);
    if (obj == nullptr) obj = mixr::glut::factory(name);
    if (obj == nullptr) obj = mixr::base::factory(name);

    return obj;
}
