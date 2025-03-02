
#include "shared/xzmq/factory.hpp"

#include "mixr/base/IObject.hpp"

#include "shared/xzmq/ZeroMQContext.hpp"
#include "shared/xzmq/ZeroMQHandler.hpp"

#include <string>

namespace mixr {
namespace xzmq {

base::IObject* factory(const std::string& name)
{
    base::IObject* obj{};

    if ( name == ZeroMQContext::getFactoryName() ) {
        obj = new ZeroMQContext;
    }
    else if ( name == ZeroMQHandler::getFactoryName() ) {
        obj = new ZeroMQHandler;
    }

    return obj;
}

}
}

