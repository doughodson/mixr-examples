
#ifndef __SpdLines_HPP__
#define __SpdLines_HPP__

#include "mixr/graphics/Graphic.hpp"

namespace mixr {
namespace base { class Boolean; }
}

//------------------------------------------------------------------------------
// Class: SpdLines
//
// Description: Draws the lines for the airspeed graphic
// Inputs:
//      UPDATE_VALUE  -> altitude flag on or off
//------------------------------------------------------------------------------
class SpdLines final: public mixr::graphics::Graphic
{
    DECLARE_SUBCLASS(SpdLines, mixr::graphics::Graphic)

public:
    SpdLines();

    void drawFunc() final;
    bool event(const int event, mixr::base::Object* const obj = nullptr) final;

    // set methods
    bool setIsAlt(const bool newIsAlt)          { isAlt = newIsAlt; return true; }

    // get methods
    bool isAltSelected()                        { return isAlt; }

private:
    // event method
    bool onEventSetIsAltSpdLines(const mixr::base::Boolean* const);

    bool isAlt{};     // are we drawing the altitude lines instead?

private:
    // slot table helper methods
    bool setSlotIsAlt(const mixr::base::Boolean*);
};

#endif
