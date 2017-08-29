
#ifndef __CrsPntr_H__
#define __CrsPntr_H__

#include "mixr/graphics/Rotators.hpp"

//------------------------------------------------------------------------------
// Class: CrsPntr
//
// Description: Handles the course pointer, cdi, and to from arrow graphic.
// Inputs:
//      UPDATE_VALUE 1 and 2 (from rotators) rotate the pointer
//      UPDATE_VALUE3 -> cdi dots
//      UPDATE_VALUE4 -> to from
//------------------------------------------------------------------------------
class CrsPntr : public mixr::graphics::Rotators
{
    DECLARE_SUBCLASS(CrsPntr, mixr::graphics::Rotators)

public:
    CrsPntr();

    // set functions
    virtual bool setCdiDots(const double);    // Sets CDI deviation (dots)
    virtual bool setToFrom(const double);     // Sets TO/FROM value [ to(1); from(0) ]
    virtual bool setNumCdiDots(const int);    // Sets number of CDI dots
    virtual bool setNumInches(const double);  // Sets number of inches for CDI
    virtual bool setShowCdi(const bool);      // Show CDI flag
    virtual bool setShowCrsPntr(const bool);  // Show CRS
    virtual bool setShowToFrom(const bool);   // Show To/from flag

    // get functions
    double getCdiDots()     { return cdiDots; }
    double getToFrom()      { return toFrom; }
    int getNumCdiDots()     { return numDots; }
    double getNumInches()   { return inches; }
    bool isCdiOn()          { return showCdi; }
    bool isCrsPtrOn()       { return showCrsPtr; }
    bool isToFromOn()       { return showToFrom; }

    virtual void drawFunc() override;

    virtual void updateData(const double dt = 0.0) override;
    virtual bool event(const int event, mixr::base::Object* const obj = nullptr) override;

private:
    // event functions
    bool onUpdateCdiDotsCrsPntr(const mixr::base::Number* const);
    bool onUpdateToFromCrsPntr(const mixr::base::Number* const);

    double toFrom {};          // to = 1; from = 0;  Somewhere in between is usually not visible, unless scaled to be visible
    double cdiDots {};         // course deviation dots
    int    numDots {4};        // how many dots are we using?
    double inchesPerDot {};    // how far to translate per dot
    double inches {1.76};
    bool showCdi {true};       // display the cdi?
    bool showCrsPtr {true};    // show the course pointer?
    bool showToFrom {true};    // show our to from arrow?

private:
    // slot table helper methods
    bool setSlotNumCdiDots(const mixr::base::Number* const);
    bool setSlotNumInches(const mixr::base::Number* const);
    bool setSlotShowCdi(const mixr::base::Number* const);
    bool setSlotShowCrsPntr(const mixr::base::Number* const);
    bool setSlotShowToFrom(const mixr::base::Number* const);
};

#endif
