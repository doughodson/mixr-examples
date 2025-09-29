
#ifndef __TestStation_HPP__
#define __TestStation_HPP__

#include "mixr/simulation/IStation.hpp"

namespace mixr {
   namespace graphics { class GlutDisplay; }
}

class Display;

//------------------------------------------------------------------------------
// Class: TestStation
//
// Description: Test station for the Ground mapping radar demo
//------------------------------------------------------------------------------
class TestStation final: public mixr::simulation::IStation
{
    DECLARE_SUBCLASS(TestStation, mixr::simulation::IStation)

public:
    TestStation();

    void updateTC(const double dt = 0.0) final;
    void reset() final;

private:
    mixr::base::safe_ptr<Display> display;
    bool displayInit {};

private:
    // slot table helper methods
    bool setSlotDisplay(Display* const);
};

#endif
