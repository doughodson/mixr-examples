
#ifndef __TestFtitDial_H__
#define __TestFtitDial_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestFtitDial
//
// Description: Example Analog Dial Page
// This page will supply test data to the fuel temperature internal dial
//
//------------------------------------------------------------------------------
class TestFtitDial final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestFtitDial, mixr::graphics::Page)

public:
    TestFtitDial();

    void updateData(const double dt = 0) final;

private:
    double ftitRotation{};      // our ftit position (0 - 1000)
    double ftitRate{100.0};     // rate which are going (up or down)
    SendData ftitRotationSD;
    SendData ftitRotationROSD;  // for our readout
};

#endif
