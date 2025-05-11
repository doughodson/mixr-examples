
#include "shared/xrecorder/factory.hpp"

#include "mixr/base/IObject.hpp"

#include "shared/xrecorder/XDataRecorder.hpp"

#include <string>

namespace mixr {
namespace xrecorder {

base::IObject* factory(const std::string& name)
{
    base::IObject* obj{};

   if ( name == XDataRecorder::getFactoryName() ) {
      obj = new XDataRecorder();
   }

    return obj;
}

}
}
