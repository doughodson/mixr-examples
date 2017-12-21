
#ifndef __TestSpeedBrake_H__
#define __TestSpeedBrake_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestSpeedBrake
//
// Description: Example Analog Dial Page
// This page will supply test data to the speed brake (generic)
//
//------------------------------------------------------------------------------
class TestSpeedBrake final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestSpeedBrake, mixr::graphics::Page)

public:
    TestSpeedBrake();

    void updateData(const double dt = 0) final;

private:
    double sbrakePosition{};          // our speed brake position (1 - 100)
    double sbrakeRate{3.0};           // rate which are going (up or down)
    SendData sbrakePositionSD;
    SendData sbrakePositionROSD;
};

#endif
