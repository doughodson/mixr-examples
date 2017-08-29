
#ifndef __TestStation_H__
#define __TestStation_H__

#include "mixr/simulation/Station.hpp"

namespace mixr {
   namespace graphics { class GlutDisplay; }
}

class Display;

//------------------------------------------------------------------------------
// Class: TestStation
//
// Description: Test station for the Ground mapping radar demo
//------------------------------------------------------------------------------
class TestStation : public mixr::simulation::Station
{
    DECLARE_SUBCLASS(TestStation, mixr::simulation::Station)

public:
    TestStation();

    virtual void updateTC(const double dt = 0.0) override;
    virtual void reset() override;

private:
    mixr::base::safe_ptr<Display> display;
    bool displayInit {};

private:
    // slot table helper methods
    bool setSlotDisplay(Display* const);
};

#endif
