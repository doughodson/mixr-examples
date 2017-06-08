
#ifndef __TestStation_H__
#define __TestStation_H__

#include "mxrp/simulation/Station.hpp"

namespace mxrp {
   namespace graphics { class GlutDisplay; }
}

class Display;

//------------------------------------------------------------------------------
// Class: TestStation
//
// Description: Test station for the Ground mapping radar demo
//------------------------------------------------------------------------------
class TestStation : public mxrp::simulation::Station
{
    DECLARE_SUBCLASS(TestStation, mxrp::simulation::Station)

public:
    TestStation();

    virtual void updateTC(const double dt = 0.0) override;
    virtual void reset() override;

private:
    bool setDisplay(Display* const d);

    mxrp::base::safe_ptr<Display> display;
    bool displayInit {};
};

#endif
