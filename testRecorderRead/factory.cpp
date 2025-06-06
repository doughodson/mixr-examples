
#include "factory.hpp"

#include "mixr/base/IObject.hpp"

#include "DataRecordTest.hpp"
#include "PrintMyData.hpp"

#include "mixr/base/factory.hpp"
#include "mixr/recorder/protobuf_v2/factory.hpp"
#include "mixr/simulation/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/models/dynamics/jsbsim/factory.hpp"

#include <string>

mixr::base::IObject* factory(const std::string& name)
{
    mixr::base::IObject* obj {};

    if ( name == DataRecordTest::getFactoryName() ) {
        obj = new DataRecordTest();
    }
    else if ( name == PrintMyData::getFactoryName() ) {
        obj = new PrintMyData();
    }
    else {
        if (obj == nullptr) obj = mixr::simulation::factory(name);
        if (obj == nullptr) obj = mixr::models::factory(name);
        if (obj == nullptr) obj = mixr::models::jsbsim::factory(name);
        if (obj == nullptr) obj = mixr::base::factory(name);
        if (obj == nullptr) obj = mixr::recorder::protobuf_v2::factory(name);
    }

    return obj;
}
