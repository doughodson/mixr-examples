
#ifndef __factory_HPP__
#define __factory_HPP__

#include <string>

namespace mixr {
namespace base { class IObject; }
}

mixr::base::IObject* factory(const std::string& name);


#endif
