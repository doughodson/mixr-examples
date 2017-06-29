
#ifndef __mixr_xbehaviors_factory_H__
#define __mixr_xbehaviors_factory_H__

#include <string>

namespace mixr {
namespace base { class Object; }
namespace xbehaviors {
base::Object* factory(const std::string& name);
}
}

#endif
