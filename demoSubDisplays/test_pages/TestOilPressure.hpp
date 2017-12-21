
#ifndef __TestOilPressure_H__
#define __TestOilPressure_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestOilPressure
//
// Description: Another example of using an analog dial.  This one is an F-16
// like oil pressure gauge
//------------------------------------------------------------------------------
class TestOilPressure final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestOilPressure, mixr::graphics::Page)

public:
    TestOilPressure();

    void updateData(const double dt = 0) final;

private:
    double oilPressure{};
    double oilRate{10.0};
    SendData oilPressureSD;
    SendData oilPressureROSD;       // sends our readout data (to a numeric readout)
};

#endif
