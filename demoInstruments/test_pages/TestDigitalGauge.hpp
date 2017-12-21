
#ifndef __TestDigitalGauge_H__
#define __TestDigitalGauge_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestDigitalGauge
//
// Description: Example Digital AOA Gauge Page
// This page will show an analog F16-like aoa gauge beside a digital aoa gauge
//
//------------------------------------------------------------------------------
class TestDigitalGauge final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestDigitalGauge, mixr::graphics::Page)

public:
   TestDigitalGauge();

   void updateData(const double dt = 0) final;

private:
    double aoa{};
    double aoaRate{2.0};    // rate which are going (up or down)
    SendData aoaSD;
    SendData aoaROSD;       // aoa readout
    SendData aoaASD;        // analog readout
};

#endif
