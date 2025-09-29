
#ifndef __Station_HPP__
#define __Station_HPP__

#include "mixr/simulation/IStation.hpp"

namespace mixr {
   namespace glut { class GlutDisplay; }
}

// -------------------------------------------------------------------------------
// Class: Station
//
// Description:
//      Derived Station that will know it has a display and can be accessed through
//      it.  This also runs the simulation, and acts as the interface between the
//      graphics and simulation.
// -------------------------------------------------------------------------------
class Station final: public mixr::simulation::IStation
{
    DECLARE_SUBCLASS(Station, mixr::simulation::IStation)

public:
    Station();

    void reset() final;

private:
    mixr::base::safe_ptr<mixr::glut::GlutDisplay> display;  // main display
    bool displayInit{};                                     // display created?

private:
    // slot table helper methods
    bool setSlotDisplay(mixr::glut::GlutDisplay*);
};

#endif
