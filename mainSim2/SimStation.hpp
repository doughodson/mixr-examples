
#ifndef __SimStation_HPP__
#define __SimStation_HPP__

#include "mixr/simulation/IStation.hpp"

namespace mixr {
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
//      display                 <glut::GlutDisplay>  ! Main graphics display
//      autoResetTimer          <ITime>              ! Auto RESET timer value (base::Time); default: 0
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
    // main Display
    mixr::base::safe_ptr<mixr::glut::GlutDisplay> display;  // main display
    bool displayInit{};                                     // display created?

    // auto reset timer
    double autoResetTimer{};                                   // auto RESET timer (sends a RESET_EVENT after timeout)
    mixr::base::safe_ptr<mixr::base::ITime> autoResetTimer0{};  // init value of the auto RESET timer

private:
    // slot table helper methods
    bool setSlotDisplay(mixr::glut::GlutDisplay* const);
    bool setSlotAutoResetTime(mixr::base::ITime* const);
};

#endif
