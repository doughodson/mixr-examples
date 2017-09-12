
#include "factory.hpp"

#include "mixr/base/Object.hpp"

#include "TestDisplay.hpp"
#include "TestStation.hpp"
#include "DspRadar.hpp"
#include "DspRwr.hpp"
#include "TdAzPtr.hpp"
#include "TdElevPtr.hpp"

#include "mixr/simulation/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/terrain/factory.hpp"
#include "mixr/interop/dis/factory.hpp"
#include "mixr/instruments/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/base/factory.hpp"
#include "mixr/ui/glut/factory.hpp"

#include <string>

mixr::base::Object* factory(const std::string& name)
{
    mixr::base::Object* obj {};

    if ( name == TestStation::getFactoryName() ) {
        obj = new TestStation();
    }
    else if ( name == TestDisplay::getFactoryName() ) {
        obj = new TestDisplay();
    }
    else if ( name == DspRadar::getFactoryName() ) {
        obj = new DspRadar();
    }
    else if ( name == DspRwr::getFactoryName() ) {
        obj = new DspRwr();
    }
    else if ( name == TdAzPtr::getFactoryName() ) {
        obj = new TdAzPtr();
    }
    else if ( name == TdElevPtr::getFactoryName() ) {
        obj = new TdElevPtr();
    }

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
