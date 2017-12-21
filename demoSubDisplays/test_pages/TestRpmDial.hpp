
#ifndef __TestRpmDial_H__
#define __TestRpmDial_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestRpmDial
//
// Description: Another example of using an analog dial.
//------------------------------------------------------------------------------
class TestRpmDial final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestRpmDial, mixr::graphics::Page)

public:
    TestRpmDial();

    void updateData(const double dt = 0) final;

private:
    double rpm{};
    double rpmRate{5.0};
    SendData rpmSD;
    SendData rpmROSD;       // sends our readout data (to a numeric readout)
};

#endif
