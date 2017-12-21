
#ifndef __mixr_xpanel_Hsi_H__
#define __mixr_xpanel_Hsi_H__

#include "mixr/graphics/Rotators.hpp"

namespace mixr {
namespace xpanel {

//------------------------------------------------------------------------------
// Class: Hsi
//
// Description: simple Hsi that will rotate the compass and display readouts
// Inputs:
//      UPDATE_VALUE 1 and 2 (from rotators) -> true heading
//      UPDATE_VALUE3 -> selected heading
//      UPDATE_VALUE4 -> selected course
//      UPDATE_VALUE5 -> nav 1 bearing
//      UPDATE_VALUE6 -> nav 2 bearing
//      UPDATE_VALUE7 -> cdi dots
//      UPDATE_VALUE8 -> to from
//------------------------------------------------------------------------------
class Hsi final: public graphics::Rotators
{
    DECLARE_SUBCLASS(Hsi,graphics::Rotators)

public:
    Hsi();

    // set functions
    bool setSelectedHeading(const double newSH);    // Sets selected heading (degs)
    bool setSelectedCourse(const double newC);      // Selected course (degs)
    bool setNav1Brg(const double newB);             // Sets Navaid 1 bearing (degs)
    bool setNav2Brg(const double newB);             // Sets Navaid 2 bearing (degs)
    bool setCdiDots(const double newCDI);           // Sets CDI deflection (dots)
    bool setToFrom(const double newTF);             // Sets TO/FROM value [ to(1); from(0) ]

    // get functions
    double getSelHdg()    { return selHdg; }
    double getSelCrs()    { return selCrs; }
    double getNav1Brg()   { return nav1Brg; }
    double getNav2Brg()   { return nav2Brg; }
    double getCdiDots()   { return cdiDots; }
    double getToFrom()    { return toFrom; }

    void updateData(const double dt = 0.0) final;
    bool event(const int event, base::Object* const obj = nullptr) final;

private:
    // event functions
    bool onUpdateSelHdgHsi(const base::Number* const);
    bool onUpdateSelCrsHsi(const base::Number* const);
    bool onUpdateNav1BrgHsi(const base::Number* const);
    bool onUpdateNav2BrgHsi(const base::Number* const);
    bool onUpdateCdiDotsHsi(const base::Number* const);
    bool onUpdateToFromHsi(const base::Number* const);

    double selHdg{};      // selected heading (degs)
    SendData selHdgSD;
    double selCrs{};      // selected course (degs)
    SendData selCrsSD;
    double cdiDots{};     // course deviation (dots)
    SendData cdiDotsSD;
    double toFrom{-1.0};  // our to from indicator ( 1 == to; 0 == from )
    SendData toFromSD;
    double nav1Brg{};     // our navaid 1 bearing (degs)
    double nav2Brg{};     // our navaid 2 bearing (degs)
    SendData nav1BrgSD;
    SendData nav2BrgSD;
    SendData selHdgROSD;
};

}
}

#endif
