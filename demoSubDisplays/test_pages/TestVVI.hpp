
#ifndef __TestVVI_H__
#define __TestVVI_H__

#include "mxrp/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestVVI
//
// Description: Test the gauge slider
// This page will supply test data to a generic analog tape gauge
//
//------------------------------------------------------------------------------
class TestVVI : public mxrp::graphics::Page
{
   DECLARE_SUBCLASS(TestVVI, mxrp::graphics::Page)

public:
   TestVVI();

   virtual void updateData(const double dt = 0) override;

private:
   double gaugePosition {};       // our gauge position (inches)
   double gaugeRate {500.0};      // rate which are going (up or down)
   SendData gaugePositionSD;
   SendData gaugePositionROSD;
};

#endif
