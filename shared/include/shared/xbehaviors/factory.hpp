
#ifndef __mixr_xbehaviors_factory_HPP__
#define __mixr_xbehaviors_factory_HPP__

#include <string>

namespace mixr {
namespace base { class IObject; }
namespace xbehaviors {
base::IObject* factory(const std::string& name);
}
}

#endif
