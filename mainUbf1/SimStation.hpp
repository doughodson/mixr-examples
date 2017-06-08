
#ifndef __SimStation_H__
#define __SimStation_H__

//#include "agent/AgentStation.h"
#include "mxrp/simulation/Station.hpp"

namespace mxrp {
namespace base { class Table1; class PairStream; }
namespace glut { class GlutDisplay; }
}

//------------------------------------------------------------------------------
// Class: SimStation
//
// Description: Example station class that adds our graphics, which is managed by
//              a GlutDisplay, adds processing of the Hands On Throttle And Stick
//              (HOTAS) device, which is usually just a joystick, and adds stepping
//              of our ownship to the next local, air vehicle player.
//
// Factory name: SimStation
// Slots:
//      display       <graphics::GlutDisplay>  ! Main graphics display
//
//------------------------------------------------------------------------------
class SimStation : public mxrp::simulation::Station
{
   DECLARE_SUBCLASS(SimStation, mxrp::simulation::Station)

public:
    SimStation();

   // Step our "ownship" to the next local air vehicle
   void stepOwnshipPlayer();

   // Slot functions
   virtual bool setSlotMainDisplay(mxrp::glut::GlutDisplay* const d);

   virtual void updateTC(const double dt = 0.0) override;
   virtual void reset() override;

private:

    // Main Display
    mxrp::base::safe_ptr<mxrp::glut::GlutDisplay> mainDisplay;
    bool displayInit {};

};

#endif
