
#ifndef __DspRwr_H__
#define __DspRwr_H__

#include "mixr/graphics/Graphic.hpp"

namespace mixr {
namespace models { class Rwr; }
}

//------------------------------------------------------------------------------
// Class: DspRwr
// Description: Simple Radar Warning Receiver (RWR) display.  Displays received
//              R/F signal as a ray, with power as length, in the direction of
//              the angle of arrival.
// Factory name: DspRwr
//------------------------------------------------------------------------------
class DspRwr final: public mixr::graphics::Graphic
{
    DECLARE_SUBCLASS(DspRwr, mixr::graphics::Graphic)

public:
    DspRwr();

    mixr::models::Rwr* getRwr()               { return rwr; }
    const mixr::models::Rwr* getRwr() const   { return rwr; }
    void setRwr(mixr::models::Rwr* s)         { rwr = s; }

    void drawFunc() final;

    void updateData(const double dt = 0.0) final;

private:
    mixr::models::Rwr* rwr{};     // The test RWR sensor
};

#endif
