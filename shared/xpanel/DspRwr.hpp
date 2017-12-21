
#ifndef __mixr_xpanel_DspRwr_H__
#define __mixr_xpanel_DspRwr_H__

#include "mixr/graphics/Graphic.hpp"

namespace mixr {
namespace models { class Rwr; }
namespace xpanel {

//------------------------------------------------------------------------------
// Class: DspRwr
// Description: Simple Radar Warning Receiver (RWR) display.  Displays received
//              R/F signal as a ray, with power as length, in the direction of
//              the angle of arrival.
// Factory name: DspRwr
//------------------------------------------------------------------------------
class DspRwr final: public graphics::Graphic
{
    DECLARE_SUBCLASS(DspRwr, graphics::Graphic)

public:
    DspRwr();

    models::Rwr* getRwr()             { return rwr; }
    const models::Rwr* getRwr() const { return rwr; }
    void setRwr(models::Rwr* s)       { rwr = s; }

    void drawFunc() final;
    void updateData(const double dt = 0.0) final;

private:
    models::Rwr* rwr{};     // The test RWR sensor
};

}
}

#endif
