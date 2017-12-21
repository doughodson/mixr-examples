
#ifndef __TestNozzle_H__
#define __TestNozzle_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestNozzle
//
// Description: Another example of using an analog dial.
//------------------------------------------------------------------------------
class TestNozzle final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestNozzle, mixr::graphics::Page)

public:
    TestNozzle();

    void updateData(const double dt = 0) final;

private:
    double nozPos{};
    double nozRate{5.0};
    SendData nozPosSD;
    SendData nozPosROSD;       // sends our readout data (to a numeric readout)
};

#endif
