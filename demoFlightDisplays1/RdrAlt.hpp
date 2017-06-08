
#ifndef __RdrAlt_H__
#define __RdrAlt_H__

#include "mxrp/graphics/Graphic.hpp"

namespace mxrp {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: RdrAlt
//
// Description: radar altitude display and minimums.  It take the min value
// of the radar, and will compare it to our current alt, and determine the color
// and visibility based on that value
// Inputs:
//      UPDATE_VALUE  -> actual radar alt
//      UPDATE_VALUE2 -> minimum radar alt
//------------------------------------------------------------------------------
class RdrAlt : public mxrp::graphics::Graphic
{
    DECLARE_SUBCLASS(RdrAlt, mxrp::graphics::Graphic)

public:
    RdrAlt();

    // set functions
    virtual bool setRAlt(const double newRA);       // Sets RADAR altitude (ft)
    virtual bool setRAltMin(const double newRM);    // Sets RADAR altitude minimum (ft)

    // get functions
    double getRadarAltFt()  { return rAlt; }
    double getRdrMinAltFt() { return rAltMin; }

    virtual void updateData(const double dt = 0.0) override;
    virtual bool event(const int event, mxrp::base::Object* const obj = nullptr) override;

private:
    // event functions
    bool onEventSetRAltRdrAlt(const mxrp::base::Number* const x);
    bool onEventSetRAltMinRdrAlt(const mxrp::base::Number* const x);

    double rAlt {};        // ft -- our actual radar alt
    SendData rAltSD;

    double rAltMin {};     // ft -- our minimum radar altitude setting
    SendData rAltMinSD;
};

#endif
