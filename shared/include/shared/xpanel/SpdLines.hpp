
#ifndef __mixr_xpanel_SpdLines_HPP__
#define __mixr_xpanel_SpdLines_HPP__

#include "mixr/graphics/Graphic.hpp"

namespace mixr {
namespace base { class Boolean; }
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
    DECLARE_SUBCLASS(SpdLines, graphics::Graphic)

public:
    SpdLines();

    // set functions
    bool setIsAlt(const bool newIsAlt)      { isAlt = newIsAlt; return true; }

    // get functions
    bool isAltSelected()                    { return isAlt; }

    void drawFunc() final;
    bool event(const int event, base::IObject* const obj = nullptr) final;

protected:
    bool setSlotIsAlt(const base::Boolean*);

private:
    // event function
    bool onEventSetIsAltSpdLines(const base::Boolean* const);

    bool isAlt{};     // are we drawing the altitude lines instead?
};

}
}

#endif
