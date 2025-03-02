
#ifndef __RdrAlt_HPP__
#define __RdrAlt_HPP__

#include "mixr/graphics/Graphic.hpp"

namespace mixr {
namespace base { class INumber; }
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
class RdrAlt final: public mixr::graphics::Graphic
{
    DECLARE_SUBCLASS(RdrAlt, mixr::graphics::Graphic)

public:
    RdrAlt();

    // set functions
    bool setRAlt(const double newRA);       // Sets RADAR altitude (ft)
    bool setRAltMin(const double newRM);    // Sets RADAR altitude minimum (ft)

    // get functions
    double getRadarAltFt()  { return rAlt; }
    double getRdrMinAltFt() { return rAltMin; }

    void updateData(const double dt = 0.0) final;
    bool event(const int event, mixr::base::IObject* const obj = nullptr) final;

private:
    // event functions
    bool onEventSetRAltRdrAlt(const mixr::base::INumber* const);
    bool onEventSetRAltMinRdrAlt(const mixr::base::INumber* const);

    double rAlt{};        // ft -- our actual radar alt
    SendData rAltSD;

    double rAltMin{};     // ft -- our minimum radar altitude setting
    SendData rAltMinSD;
};

#endif
