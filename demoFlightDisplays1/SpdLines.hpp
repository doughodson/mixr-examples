
#ifndef __SpdLines_H__
#define __SpdLines_H__

#include "mixr/graphics/Graphic.hpp"

//------------------------------------------------------------------------------
// Class: SpdLines
//
// Description: Draws the lines for the airspeed graphic
// Inputs:  Slots only
//------------------------------------------------------------------------------
class SpdLines : public mixr::graphics::Graphic
{
    DECLARE_SUBCLASS(SpdLines, mixr::graphics::Graphic)

public:
    SpdLines();

    virtual void drawFunc() override;

    // set functions
    virtual bool setIsAlt(const bool newIsAlt);
    virtual bool setDrawBack(const bool newDB);

    // get functions
    bool isAltOn()          { return isAlt; }
    bool isBackgroundOn()   { return drawBack; }

private:
    bool isAlt {};     // are we drawing the altitude lines instead?
    bool drawBack {};  // draw the background (for transparency purposes)

private:
    // slot table helper methods
    bool setSlotIsAlt(const mixr::base::Number*);
    bool setSlotDrawBack(const mixr::base::Number*);
};

#endif
