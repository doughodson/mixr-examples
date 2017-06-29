
#ifndef __Display_H__
#define __Display_H__

#include "mixr/gui/glut/GlutDisplay.hpp"

namespace mixr {
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
class Display : public mixr::glut::GlutDisplay
{
   DECLARE_SUBCLASS(Display, mixr::glut::GlutDisplay)

public:
   Display();

   mixr::models::Player* getOwnship();
   mixr::simulation::Simulation* getSimulation();
   mixr::simulation::Station* getStation();

   // Slot functions
   virtual bool setSlotTextureTest(const mixr::base::Number* const msg);

   virtual void configure() override;
   virtual void drawFunc() override;

private:
   mixr::base::safe_ptr<mixr::simulation::Station> myStation;

   bool   testTexture {};      // Texture image test
   GLuint texture {};          // Texture
};

#endif
