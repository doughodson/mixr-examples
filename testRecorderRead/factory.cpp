
#include "factory.hpp"

#include "mixr/base/Object.hpp"

#include "DataRecordTest.hpp"
#include "PrintMyData.hpp"

#include "mixr/base/factory.hpp"
#include "mixr/recorder/factory.hpp"
#include "mixr/simulation/factory.hpp"
#include "mixr/models/factory.hpp"

#include <string>

mixr::base::Object* factory(const std::string& name)
{
    mixr::base::Object* obj {};

    if ( name == DataRecordTest::getFactoryName() ) {
        obj = new DataRecordTest();
    }
    else if ( name == PrintMyData::getFactoryName() ) {
        obj = new PrintMyData();
    }
    else {
        if (obj == nullptr) obj = mixr::simulation::factory(name);
        if (obj == nullptr) obj = mixr::models::factory(name);
        if (obj == nullptr) obj = mixr::base::factory(name);
        if (obj == nullptr) obj = mixr::recorder::factory(name);
    }

    return obj;
}
