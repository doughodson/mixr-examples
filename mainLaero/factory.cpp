
#include "factory.hpp"

#include "mixr/base/Object.hpp"

#include "TestStation.hpp"
#include "AdiDisplay.hpp"
#include "MapDisplay.hpp"
#include "MapPage.hpp"

// factories
#include "../shared/xzmq/factory.hpp"
#include "mixr/base/factory.hpp"
#include "mixr/simulation/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/terrain/factory.hpp"
#include "mixr/interop/dis/factory.hpp"
#include "mixr/instruments/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/ui/glut/factory.hpp"

#include <string>

mixr::base::Object* factory(const std::string& name)
{
    mixr::base::Object* obj{};

    if ( name == TestStation::getFactoryName() ) {
        obj = new TestStation();
    }
    else if ( name == AdiDisplay::getFactoryName() ) {
        obj = new AdiDisplay();
    }
    else if ( name == MapDisplay::getFactoryName() ) {
        obj = new MapDisplay();
    }
    else if ( name == MapPage::getFactoryName() ) {
        obj = new MapPage();
    }

    // Example libraries
    if (obj == nullptr) obj = mixr::xzmq::factory(name);

    // Framework libraries
    if (obj == nullptr) obj = mixr::simulation::factory(name);
    if (obj == nullptr) obj = mixr::models::factory(name);
    if (obj == nullptr) obj = mixr::terrain::factory(name);
    if (obj == nullptr) obj = mixr::instruments::factory(name);
    if (obj == nullptr) obj = mixr::dis::factory(name);
    if (obj == nullptr) obj = mixr::graphics::factory(name);
    if (obj == nullptr) obj = mixr::glut::factory(name);
    if (obj == nullptr) obj = mixr::base::factory(name);

    return obj;
}
