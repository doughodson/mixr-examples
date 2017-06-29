
#ifndef __TestLandingGear_H__
#define __TestLandingGear_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestLandingGear
//
// Description: Tests our generic landing gear and lights
//------------------------------------------------------------------------------
class TestLandingGear : public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestLandingGear, mixr::graphics::Page)

public:
   TestLandingGear();

   virtual bool event(const int event, mixr::base::Object* const obj = nullptr) override;
   virtual void updateData(const double dt = 0.0) override;

private:
    // event functions
    bool onUpdateLandingGearTestLandingGear();

    double gearPosition {};       // our landing gear position (0 is down, 1 is up)
    double gearRate {0.3};        // rate which are going (up or down)
    SendData gearPositionSD;
    SendData gearPositionROSD;
};

#endif
