
#ifndef __mixr_xrecorder_factory_H__
#define __mixr_xrecorder_factory_H__

#include <string>

namespace mixr {
namespace base { class Object; }
namespace xrecorder {

base::Object* factory(const std::string& name);

}
}

#endif
