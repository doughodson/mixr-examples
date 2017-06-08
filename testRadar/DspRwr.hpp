
#ifndef __DspRwr_H__
#define __DspRwr_H__

#include "mxrp/graphics/Graphic.hpp"

namespace mxrp {
namespace models { class Rwr; }
}

//------------------------------------------------------------------------------
// Class: DspRwr
// Description: Simple Radar Warning Receiver (RWR) display.  Displays received
//              R/F signal as a ray, with power as length, in the direction of
//              the angle of arrival.
// Factory name: DspRwr
//------------------------------------------------------------------------------
class DspRwr : public mxrp::graphics::Graphic
{
    DECLARE_SUBCLASS(DspRwr, mxrp::graphics::Graphic)

public:
    DspRwr();

    mxrp::models::Rwr* getRwr()               { return rwr; }
    const mxrp::models::Rwr* getRwr() const   { return rwr; }
    void setRwr(mxrp::models::Rwr* s)         { rwr = s; }

    virtual void drawFunc() override;

    virtual void updateData(const double dt = 0.0) override;

private:
    mxrp::models::Rwr* rwr {};     // The test RWR sensor
};

#endif
