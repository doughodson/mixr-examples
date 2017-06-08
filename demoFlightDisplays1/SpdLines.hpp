
#ifndef __SpdLines_H__
#define __SpdLines_H__

#include "mxrp/graphics/Graphic.hpp"

//------------------------------------------------------------------------------
// Class: SpdLines
//
// Description: Draws the lines for the airspeed graphic
// Inputs:  Slots only
//------------------------------------------------------------------------------
class SpdLines : public mxrp::graphics::Graphic
{
    DECLARE_SUBCLASS(SpdLines, mxrp::graphics::Graphic)

public:
    SpdLines();

    virtual void drawFunc() override;

    // set functions
    virtual bool setIsAlt(const bool newIsAlt);
    virtual bool setDrawBack(const bool newDB);

    // get functions
    bool isAltOn()          { return isAlt; }
    bool isBackgroundOn()   { return drawBack; }

protected:
    // slot functions
    bool setSlotIsAlt(const mxrp::base::Number* newIsAlt);
    bool setSlotDrawBack(const mxrp::base::Number* newDB);

private:
    bool isAlt {};     // are we drawing the altitude lines instead?
    bool drawBack {};  // draw the background (for transparency purposes)
};

#endif
