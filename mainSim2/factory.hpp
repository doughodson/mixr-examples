
#ifndef __factory_H__
#define __factory_H__

#include <string>

namespace mixr {
   namespace base { class Object; }
}

mixr::base::Object* factory(const std::string& name);

#endif
