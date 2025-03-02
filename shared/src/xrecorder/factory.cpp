
#include "shared/xrecorder/factory.hpp"

#include "mixr/base/IObject.hpp"

#include "shared/xrecorder/DataRecorder.hpp"

#include <string>

namespace mixr {
namespace xrecorder {

base::IObject* factory(const std::string& name)
{
    base::IObject* obj{};

   if ( name == DataRecorder::getFactoryName() ) {
      obj = new DataRecorder();
   }

    return obj;
}

}
}
