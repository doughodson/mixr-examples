
#ifndef __mixr_xpanel_SpdLines_H__
#define __mixr_xpanel_SpdLines_H__

#include "mixr/graphics/Graphic.hpp"

namespace mixr {
namespace xpanel {

//------------------------------------------------------------------------------
// Class: SpdLines
//
// Description: Draws the lines for the airspeed graphic
// Inputs:
//      UPDATE_VALUE  -> altitude flag on or off
//------------------------------------------------------------------------------
class SpdLines final: public graphics::Graphic
{
    DECLARE_SUBCLASS(SpdLines,graphics::Graphic)

public:
    SpdLines();

    // set functions
    bool setIsAlt(const bool newIsAlt)      { isAlt = newIsAlt; return true; }

    // get functions
    bool isAltSelected()                    { return isAlt; }

    void drawFunc() final;
    bool event(const int event, base::Object* const obj = nullptr) final;

protected:
    bool setSlotIsAlt(const base::Number* newIsAlt);

private:
    // event function
    bool onEventSetIsAltSpdLines(const base::Number* const);

    bool isAlt{};     // are we drawing the altitude lines instead?
};

}
}

#endif
