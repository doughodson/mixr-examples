
#ifndef __oe_xbehaviors_factory_H__
#define __oe_xbehaviors_factory_H__

#include <string>

namespace mxrp {
namespace base { class Object; }
namespace xbehaviors {
base::Object* factory(const std::string& name);
}
}

#endif
