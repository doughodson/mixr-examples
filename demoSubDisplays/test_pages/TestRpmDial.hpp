
#ifndef __TestRpmDial_H__
#define __TestRpmDial_H__

#include "mxrp/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestRpmDial
//
// Description: Another example of using an analog dial.
//------------------------------------------------------------------------------
class TestRpmDial : public mxrp::graphics::Page
{
   DECLARE_SUBCLASS(TestRpmDial, mxrp::graphics::Page)

public:
    TestRpmDial();

    virtual void updateData(const double dt = 0) override;

private:
    double rpm {};
    double rpmRate {5.0};
    SendData rpmSD;
    SendData rpmROSD;       // sends our readout data (to a numeric readout)
};

#endif
