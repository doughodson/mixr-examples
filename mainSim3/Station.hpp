
#ifndef __Station_H__
#define __Station_H__

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
class Station : public mixr::simulation::Station
{
    DECLARE_SUBCLASS(Station, mixr::simulation::Station)

public:
    Station();

    virtual void reset() override;

protected:
    // slot methods
    bool setSlotDisplay(mixr::glut::GlutDisplay*);

private:
    mixr::glut::GlutDisplay* display {}; // this is our main display that
    bool displayInit {};               // is our display created?
};

#endif
