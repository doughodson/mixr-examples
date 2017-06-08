
#ifndef __Display_H__
#define __Display_H__

#include "mxrp/gui/glut/GlutDisplay.hpp"

namespace mxrp {
namespace base { class Number; }
namespace models { class Player; }
namespace simulation { class Simulation; class Station; }
}

// ----------------------------------------------------------------------------
// Class: Display
//
// Description: Displays an image of a radar beam return
//
// Factory name: RbrDisplay
//
// Slots:
//    textureTest <Boolean>   Texture test enabled
// ----------------------------------------------------------------------------
class Display : public mxrp::glut::GlutDisplay
{
   DECLARE_SUBCLASS(Display, mxrp::glut::GlutDisplay)

public:
   Display();

   mxrp::models::Player* getOwnship();
   mxrp::simulation::Simulation* getSimulation();
   mxrp::simulation::Station* getStation();

   // Slot functions
   virtual bool setSlotTextureTest(const mxrp::base::Number* const msg);

   virtual void configure() override;
   virtual void drawFunc() override;

private:
   mxrp::base::safe_ptr<mxrp::simulation::Station> myStation;

   bool   testTexture {};      // Texture image test
   GLuint texture {};          // Texture
};

#endif
