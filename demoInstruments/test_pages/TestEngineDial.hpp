
#ifndef __TestEngineDial_H__
#define __TestEngineDial_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestEngineDial
//
// Description: Example Analog Dial Page
// This page will supply test data to the engine dial
//------------------------------------------------------------------------------
class TestEngineDial final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestEngineDial, mixr::graphics::Page)

public:
    TestEngineDial();

    void updateData(const double dt = 0) final;

private:
    double engineRotation{};        // our engine rpm position (1 - 100)
    double engineRate{10.0};        // rate which are going (up or down)
    SendData engineRotationSD;
    SendData engineReadoutSD;       // sends our readout data (to a numeric readout)
};

#endif
