
#include "factory.hpp"

#include "mxrp/base/Object.hpp"

#include "DataRecordTest.hpp"
#include "PrintMyData.hpp"

#include "mxrp/base/factory.hpp"
#include "mxrp/recorder/factory.hpp"
#include "mxrp/simulation/factory.hpp"
#include "mxrp/models/factory.hpp"

#include <string>

mxrp::base::Object* factory(const std::string& name)
{
    mxrp::base::Object* obj = nullptr;

    if ( name == DataRecordTest::getFactoryName() ) {
        obj = new DataRecordTest();
    }
    else if ( name == PrintMyData::getFactoryName() ) {
        obj = new PrintMyData();
    }
    else {
        if (obj == nullptr) obj = mxrp::simulation::factory(name);
        if (obj == nullptr) obj = mxrp::models::factory(name);
        if (obj == nullptr) obj = mxrp::base::factory(name);
        if (obj == nullptr) obj = mxrp::recorder::factory(name);
    }

    return obj;
}
