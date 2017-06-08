
#ifndef __SpdLines_H__
#define __SpdLines_H__

#include "mxrp/graphics/Graphic.hpp"

namespace mxrp {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: SpdLines
//
// Description: Draws the lines for the airspeed graphic
// Inputs:
//      UPDATE_VALUE  -> altitude flag on or off
//------------------------------------------------------------------------------
class SpdLines : public mxrp::graphics::Graphic
{
    DECLARE_SUBCLASS(SpdLines, mxrp::graphics::Graphic)

public:
    SpdLines();

    virtual void drawFunc() override;
    virtual bool event(const int event, mxrp::base::Object* const obj = nullptr) override;

    // set methods
    virtual bool setIsAlt(const bool newIsAlt)          { isAlt = newIsAlt; return true; }

    // get methods
    bool isAltSelected()                                { return isAlt; }

protected:
    bool setSlotIsAlt(const mxrp::base::Number* newIsAlt);

private:
    // event method
    bool onEventSetIsAltSpdLines(const mxrp::base::Number* const x);

    bool isAlt {};     // are we drawing the altitude lines instead?
};

#endif
