
#include "shared/xpanel/factory.hpp"

#include "mixr/base/Object.hpp"

#include "shared/xpanel/DspRadar.hpp"
#include "shared/xpanel/DspRwr.hpp"
#include "shared/xpanel/Hsi.hpp"
#include "shared/xpanel/TdAzPtr.hpp"
#include "shared/xpanel/TdElevPtr.hpp"
#include "shared/xpanel/Pfd.hpp"
#include "shared/xpanel/SpdLines.hpp"
#include <string>

namespace mixr {
namespace xpanel {

base::Object* factory(const std::string& name)
{
    base::Object* obj{};

    if ( name == DspRadar::getFactoryName() ) {
        obj = new DspRadar();
    }
    else if ( name == DspRwr::getFactoryName() ) {
        obj = new DspRwr();
    }
    else if ( name == TdAzPtr::getFactoryName() ) {
        obj = new TdAzPtr();
    }
    else if ( name == TdElevPtr::getFactoryName() ) {
        obj = new TdElevPtr();
    }

    // Pfd/Hsi
    else if ( name == Pfd::getFactoryName() ) {
        obj = new Pfd();
    }
    else if ( name == Hsi::getFactoryName() ) {
        obj = new Hsi();
    }
    else if ( name == SpdLines::getFactoryName() ) {
        obj = new SpdLines();
    }

    return obj;
}

}
}
