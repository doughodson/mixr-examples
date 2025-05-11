
#ifndef __mixr_xzmq_factory_HPP__
#define __mixr_xzmq_factory_HPP__

#include <string>

namespace mixr {
namespace base { class IObject; }
namespace xzmq {

base::IObject* factory(const std::string& name);

}
}

#endif
