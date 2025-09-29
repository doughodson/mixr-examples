
#ifndef __Display_HPP__
#define __Display_HPP__

#include "mixr/ui/glut/GlutDisplay.hpp"

namespace mixr {
namespace base { class Boolean; }
namespace models { class IPlayer; }
namespace simulation { class ISimulation; class Station; }
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
class Display final: public mixr::glut::GlutDisplay
{
   DECLARE_SUBCLASS(Display, mixr::glut::GlutDisplay)

public:
   Display();

   mixr::models::IPlayer* getOwnship();
   mixr::simulation::ISimulation* getSimulation();
   mixr::simulation::IStation* getStation();

   void configure() final;
   void drawFunc() final;

private:
   mixr::base::safe_ptr<mixr::simulation::IStation> myStation;

   bool testTexture{};      // Texture image test
   GLuint texture{};        // Texture

private:
   // slot table helper methods
   bool setSlotTextureTest(const mixr::base::Boolean* const);
};

#endif
