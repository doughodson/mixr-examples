
#include "factory.hpp"

#include "mixr/base/Object.hpp"

#include "ZeroMQContext.hpp"
#include "ZeroMQHandler.hpp"

#include <string>

namespace mixr {
namespace xzmq {

base::Object* factory(const std::string& name)
{
    base::Object* obj{};

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

