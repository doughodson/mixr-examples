
#ifndef __factory_HPP__
#define __factory_HPP__

#include <string>

namespace mixr {
   namespace base { class Object; }
}

mixr::base::Object* factory(const std::string& name);

#endif
