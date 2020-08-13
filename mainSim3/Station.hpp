
#ifndef __Station_HPP__
#define __Station_HPP__

#include "mixr/simulation/Station.hpp"

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
class Station final: public mixr::simulation::Station
{
    DECLARE_SUBCLASS(Station, mixr::simulation::Station)

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
