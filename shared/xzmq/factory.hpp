
#ifndef __mixr_xzmq_factory_H__
#define __mixr_xzmq_factory_H__

#include <string>

namespace mixr {
namespace base { class Object; }
namespace xzmq {

base::Object* factory(const std::string& name);

}
}

#endif
