//------------------------------------------------------------------------------
// Class: SimStation
//------------------------------------------------------------------------------
#ifndef __oe_example_SimStation_H__
#define __oe_example_SimStation_H__

//#include "agent/AgentStation.h"
#include "openeaagles/simulation/Station.h"

namespace oe {

namespace basic { class Table1; class PairStream; }
namespace Glut { class GlutDisplay; }
namespace Simulation { class AirVehicle; }

namespace example {

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
//      display       <BasicGL::GlutDisplay>  ! Main graphics display
//
//------------------------------------------------------------------------------
class SimStation : public Simulation::Station
{
   DECLARE_SUBCLASS(SimStation, Simulation::Station)

public:
    SimStation();

   // Step our "ownship" to the next local air vehicle
   void stepOwnshipPlayer();

   // Slot functions
   virtual bool setSlotMainDisplay(Glut::GlutDisplay* const d);

   void updateTC(const LCreal dt = 0.0) override;
   void reset() override;

private:

    // Main Display
    basic::safe_ptr<Glut::GlutDisplay> mainDisplay;
    bool displayInit;

};

} // End example namespace
} // End oe namespace

#endif
