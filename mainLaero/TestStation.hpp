
#ifndef __TestStation_H__
#define __TestStation_H__

#include "mxrp/simulation/Station.hpp"

namespace mxrp {
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
class TestStation : public mxrp::simulation::Station
{
   DECLARE_SUBCLASS(TestStation, mxrp::simulation::Station)

public:
   TestStation();

   virtual void updateTC(const double dt = 0.0) override;
   virtual void updateData(const double dt = 0.0) override;
   virtual void reset() override;

private:
   bool setSlotGlutDisplay(mxrp::glut::GlutDisplay* const msg);
   bool setSlotMapDisplay(mxrp::glut::GlutDisplay* const msg);

   mxrp::base::safe_ptr<mxrp::glut::GlutDisplay> glutDisplay;
   mxrp::base::safe_ptr<mxrp::glut::GlutDisplay> mapDisplay;
   bool glutDisplayInit {};
   bool mapDisplayInit {};
};

#endif
