
#ifndef __mixr_xrecorder_factory_HPP__
#define __mixr_xrecorder_factory_HPP__

#include <string>

namespace mixr {
namespace base { class IObject; }
namespace xrecorder {

base::IObject* factory(const std::string& name);

}
}

#endif
