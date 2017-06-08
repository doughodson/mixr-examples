
#ifndef __factory_H__
#define __factory_H__

#include <string>

namespace mxrp {
namespace base { class Object; }
}

mxrp::base::Object* factory(const std::string& name);

#endif
