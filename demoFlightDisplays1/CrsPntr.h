//------------------------------------------------------------------------------
// Class: CrsPntr
//
// Description: Handles the course pointer, cdi, and to from arrow graphic.
// Inputs:
//      UPDATE_VALUE 1 and 2 (from rotators) rotate the pointer
//      UPDATE_VALUE3  -> cdi dots
//      UPDATE_VALUE4 -> to from
//------------------------------------------------------------------------------
#ifndef __oe_demo_CrsPntr_H__
#define __oe_demo_CrsPntr_H__

#include "openeaagles/basicGL/Rotators.h"

namespace oe {
namespace demo {

class CrsPntr : public BasicGL::Rotators
{
    DECLARE_SUBCLASS(CrsPntr,BasicGL::Rotators)

public:
    CrsPntr();

    // set functions
    virtual bool setCdiDots(const LCreal newCDD);   // Sets CDI deviation (dots)
    virtual bool setToFrom(const LCreal newTF);     // Sets TO/FROM value [ to(1); from(0) ]
    virtual bool setNumCdiDots(const int newNCD);   // Sets number of CDI dots
    virtual bool setNumInches(const LCreal newNI);  // Sets number of inches for CDI
    virtual bool setShowCdi(const bool newSCDI);    // Show CDI flag
    virtual bool setShowCrsPntr(const bool newSCP); // Show CRS
    virtual bool setShowToFrom(const bool newTF);   // Show To/from flag

    // get functions
    LCreal getCdiDots()     { return cdiDots; }
    LCreal getToFrom()      { return toFrom; }
    int getNumCdiDots()     { return numDots; }
    LCreal getNumInches()   { return inches; }
    bool isCdiOn()          { return showCdi; }
    bool isCrsPtrOn()       { return showCrsPtr; }
    bool isToFromOn()       { return showToFrom; }

    void drawFunc() override;

    void updateData(const LCreal dt = 0.0) override;
    bool event(const int event, basic::Object* const obj = nullptr) override;

protected:
    // slot functions
    bool setSlotNumCdiDots(const basic::Number* const newCDI);
    bool setSlotNumInches(const basic::Number* const newNI);
    bool setSlotShowCdi(const basic::Number* const newSCDI);
    bool setSlotShowCrsPntr(const basic::Number* const newSCP);
    bool setSlotShowToFrom(const basic::Number* const newTF);

private:
    // event functions
    bool onUpdateCdiDotsCrsPntr(const basic::Number* const x);
    bool onUpdateToFromCrsPntr(const basic::Number* const x);

    LCreal toFrom;          // to = 1; from = 0;  Somewhere in between is usually not visible, unless scaled to be visible
    LCreal cdiDots;         // course deviation dots
    int    numDots;         // how many dots are we using?
    LCreal inchesPerDot;    // how far to translate per dot
    LCreal inches;
    bool showCdi;           // display the cdi?
    bool showCrsPtr;        // show the course pointer?
    bool showToFrom;        // show our to from arrow?
};

}; // end of Instruments namespace
}; // end of oe namespace

#endif

