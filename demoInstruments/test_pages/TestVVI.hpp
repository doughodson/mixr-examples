
#ifndef __TestVVI_H__
#define __TestVVI_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestVVI
//
// Description: Test the gauge slider
// This page will supply test data to a generic analog tape gauge
//
//------------------------------------------------------------------------------
class TestVVI final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestVVI, mixr::graphics::Page)

public:
   TestVVI();

   void updateData(const double dt = 0) final;

private:
   double gaugePosition{};       // our gauge position (inches)
   double gaugeRate{500.0};      // rate which are going (up or down)
   SendData gaugePositionSD;
   SendData gaugePositionROSD;
};

#endif
