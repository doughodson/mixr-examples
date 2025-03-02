
#ifndef __mixr_xpanel_factory_HPP__
#define __mixr_xpanel_factory_HPP__

#include <string>

namespace mixr {
namespace base { class IObject; }
namespace xpanel {
base::IObject* factory(const std::string& name);
}
}

#endif
