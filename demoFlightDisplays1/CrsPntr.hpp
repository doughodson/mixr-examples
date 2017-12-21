
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
class CrsPntr final: public mixr::graphics::Rotators
{
    DECLARE_SUBCLASS(CrsPntr, mixr::graphics::Rotators)

public:
    CrsPntr();

    // set functions
    bool setCdiDots(const double);    // Sets CDI deviation (dots)
    bool setToFrom(const double);     // Sets TO/FROM value [ to(1); from(0) ]
    bool setNumCdiDots(const int);    // Sets number of CDI dots
    bool setNumInches(const double);  // Sets number of inches for CDI
    bool setShowCdi(const bool);      // Show CDI flag
    bool setShowCrsPntr(const bool);  // Show CRS
    bool setShowToFrom(const bool);   // Show To/from flag

    // get functions
    double getCdiDots()     { return cdiDots; }
    double getToFrom()      { return toFrom; }
    int getNumCdiDots()     { return numDots; }
    double getNumInches()   { return inches; }
    bool isCdiOn()          { return showCdi; }
    bool isCrsPtrOn()       { return showCrsPtr; }
    bool isToFromOn()       { return showToFrom; }

    void drawFunc() final;
    void updateData(const double dt = 0.0) final;
    bool event(const int event, mixr::base::Object* const obj = nullptr) final;

private:
    // event functions
    bool onUpdateCdiDotsCrsPntr(const mixr::base::Number* const);
    bool onUpdateToFromCrsPntr(const mixr::base::Number* const);

    double toFrom{};          // to = 1; from = 0;  Somewhere in between is usually not visible, unless scaled to be visible
    double cdiDots{};         // course deviation dots
    int    numDots{4};        // how many dots are we using?
    double inchesPerDot{};    // how far to translate per dot
    double inches{1.76};
    bool showCdi{true};       // display the cdi?
    bool showCrsPtr{true};    // show the course pointer?
    bool showToFrom{true};    // show our to from arrow?

private:
    // slot table helper methods
    bool setSlotNumCdiDots(const mixr::base::Number* const);
    bool setSlotNumInches(const mixr::base::Number* const);
    bool setSlotShowCdi(const mixr::base::Number* const);
    bool setSlotShowCrsPntr(const mixr::base::Number* const);
    bool setSlotShowToFrom(const mixr::base::Number* const);
};

#endif
