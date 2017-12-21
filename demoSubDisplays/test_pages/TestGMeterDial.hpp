
#ifndef __TestGMeterDial_H__
#define __TestGMeterDial_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestGMeterDial
//
// Description: This page will test the G meter, which is a dial showing
// the min and max Gs as well as the current Gs being pulled.
//------------------------------------------------------------------------------
class TestGMeterDial final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestGMeterDial, mixr::graphics::Page)

public:
    TestGMeterDial();

    void updateData(const double dt = 0) final;

private:
    double currGs{};        // current G's
    double gRate{2.0};
    SendData currGsSD;
    SendData currGsROSD;

    double timer{};         // our timer for resetting the g meter
    double timerRate{0.2};
};

#endif
