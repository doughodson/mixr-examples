
#ifndef __TestButtons_H__
#define __TestButtons_H__

#include "mxrp/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestButtons
//
// Description: Simply tests our buttons and prints out which one we hit
//------------------------------------------------------------------------------
class TestButtons : public mxrp::graphics::Page
{
   DECLARE_SUBCLASS(TestButtons, mxrp::graphics::Page)

public:
   TestButtons();

   enum { REGULAR = 0, PUSH_MAINTAINED, PUSH_MOMENTARY, ROTARY, KNOB, SOLENOID };

   virtual void updateData(const double dt = 0.0) override;
   virtual bool event(const int event, mxrp::base::Object* const obj = nullptr) override;

private:
    bool regularButton();
    bool pushButtonMaintained();
    bool pushButtonMomentary();
    bool rotarySwitch();
    bool knobMoved();
    bool resetSolenoid();
    bool solenoidUp();
    bool solenoidDown();

    int whichButton {-1};
    double value {};

    SendData whichButtonSD;
    SendData valueSD;
    SendData latchedSD;
};

#endif
