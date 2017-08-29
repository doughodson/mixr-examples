
#ifndef __SpdLines_H__
#define __SpdLines_H__

#include "mixr/graphics/Graphic.hpp"

namespace mixr {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: SpdLines
//
// Description: Draws the lines for the airspeed graphic
// Inputs:
//      UPDATE_VALUE  -> altitude flag on or off
//------------------------------------------------------------------------------
class SpdLines : public mixr::graphics::Graphic
{
    DECLARE_SUBCLASS(SpdLines, mixr::graphics::Graphic)

public:
    SpdLines();

    virtual void drawFunc() override;
    virtual bool event(const int event, mixr::base::Object* const obj = nullptr) override;

    // set methods
    virtual bool setIsAlt(const bool newIsAlt)          { isAlt = newIsAlt; return true; }

    // get methods
    bool isAltSelected()                                { return isAlt; }

private:
    // event method
    bool onEventSetIsAltSpdLines(const mixr::base::Number* const x);

    bool isAlt {};     // are we drawing the altitude lines instead?

private:
    // slot table helper methods
    bool setSlotIsAlt(const mixr::base::Number*);

};

#endif
