
#ifndef __TestStation_H__
#define __TestStation_H__

#include "mixr/simulation/Station.hpp"

namespace mixr {
namespace base { class Number; }
namespace glut { class GlutDisplay; }
}

//------------------------------------------------------------------------------
// Class: TestStation
// Description: Test station class that adds our graphics, which is managed by
//              a GlutDisplay, adds processing of the Hands On Throttle And Stick
//              (HOTAS) device, which is usually just a joystick, and adds stepping
//              of our ownship to the next local, air vehicle player.
//
// Factory name: TestStation
// Slots:
//   glutDisplay  <graphics::GlutDisplay>  ! All of our display components
//------------------------------------------------------------------------------
class TestStation final: public mixr::simulation::Station
{
   DECLARE_SUBCLASS(TestStation, mixr::simulation::Station)

public:
   TestStation();

   void updateTC(const double dt = 0.0) final;
   void updateData(const double dt = 0.0) final;
   void reset() final;

private:
   mixr::base::safe_ptr<mixr::glut::GlutDisplay> glutDisplay;
   mixr::base::safe_ptr<mixr::glut::GlutDisplay> mapDisplay;
   bool glutDisplayInit{};
   bool mapDisplayInit{};

private:
   // slot table helper methods
   bool setSlotGlutDisplay(mixr::glut::GlutDisplay* const);
   bool setSlotMapDisplay(mixr::glut::GlutDisplay* const);
};

#endif
