
#ifndef __SimStation_HPP__
#define __SimStation_HPP__

#include "mixr/simulation/IStation.hpp"

namespace mixr {
   namespace base { class Table1; }
   namespace glut  { class GlutDisplay; }
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
//      display          <graphics::GlutDisplay> ! Main graphics display
//      autoResetTimer   <ITime>                 ! Auto RESET timer value (base::Time); default: 0
//------------------------------------------------------------------------------
class SimStation final: public mixr::simulation::IStation
{
    DECLARE_SUBCLASS(SimStation, mixr::simulation::IStation)

public:
    SimStation();

   // Step our "ownship" to the next local air vehicle
   void stepOwnshipPlayer();

   void updateTC(const double dt = 0.0) final;
   void updateData(const double dt = 0.0) final;
   void reset() final;

private:
   // Main Display
   mixr::base::safe_ptr<mixr::glut::GlutDisplay> mainDisplay;
   bool displayInit{};

   // Auto reset timer
   double autoResetTimer{};                   // Auto RESET timer (sends a RESET_EVENT after timeout)
   const mixr::base::ITime* autoResetTimer0{};   // Init value of the Auto RESET timer

private:
   // slot table helper methods
   bool setSlotMainDisplay(mixr::glut::GlutDisplay* const);
   bool setSlotAutoResetTime(const mixr::base::ITime* const);     // Sets the auto RESET timer
};

#endif
