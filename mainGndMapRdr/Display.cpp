
#include "Display.hpp"
#include "RealBeamRadar.hpp"

#include "mixr/models/player/Player.hpp"

#include "mixr/simulation/Simulation.hpp"
#include "mixr/simulation/Station.hpp"

#include "mixr/base/numeric/Number.hpp"

#include "mixr/base/colors/Color.hpp"
#include "mixr/base/colors/Rgb.hpp"
#include "mixr/base/colors/Hsva.hpp"

#include "mixr/base/units/Angles.hpp"
#include "mixr/base/units/Distances.hpp"

#include "mixr/base/String.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"

using namespace mixr;

IMPLEMENT_SUBCLASS(Display, "RbrDisplay")

BEGIN_SLOTTABLE(Display)
   "textureTest",    //  1: Texture test enabled
END_SLOTTABLE(Display)

BEGIN_SLOT_MAP(Display)
   ON_SLOT( 1, setSlotTextureTest, base::Number)
END_SLOT_MAP()

Display::Display()
{
   STANDARD_CONSTRUCTOR()
}

void Display::copyData(const Display& org, const bool)
{
   BaseClass::copyData(org);
}

void Display::deleteData()
{
   // Free the texture
   if (texture != 0) {
      glDeleteTextures(1, &texture);
      texture = 0;
   }
}

//------------------------------------------------------------------------------
// Simulation access functions
//------------------------------------------------------------------------------
models::Player* Display::getOwnship()
{
    models::Player* p{};
    simulation::Station* sta{getStation()};
    if (sta != nullptr) {
        p = dynamic_cast<models::Player*>(sta->getOwnship());
    }
    return p;
}

simulation::Simulation* Display::getSimulation()
{
    simulation::Simulation* s{};
    simulation::Station* sta{getStation()};
    if (sta != nullptr) s = sta->getSimulation();
    return s;
}

simulation::Station* Display::getStation()
{
    if (myStation == nullptr) {
        const auto s = dynamic_cast<simulation::Station*>( findContainerByType(typeid(simulation::Station)) );
        if (s != nullptr) myStation = s;
    }
    return myStation;
}

// Set texture test flag
bool Display::setSlotTextureTest(const base::Number* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      testTexture = msg->getBoolean();
      ok = true;
   }
   return ok;
}

void Display::drawFunc()
{
   const auto own = dynamic_cast<models::Player*>(getOwnship());

   const base::Pair* pair{};
   if (own != nullptr) pair = own->getSensorByType(typeid(RealBeamRadar));

   const RealBeamRadar* rdr{};
   if (pair != nullptr) rdr = static_cast<const RealBeamRadar*>( pair->object() );

   const GLubyte* image{};     // The image pixels
   if (rdr != nullptr) image = rdr->getImage();

   if (image != nullptr) {

      // Image width  (number of columns)
      GLsizei imgWidth{rdr->getImageWidth()};

      // Image height (number of rows)
      GLsizei imgHeight{rdr->getImageHeight()};

      GLint pixelSize{rdr->getPixelSize()};
      GLenum format{GL_RGB};
      if (pixelSize == 4) format = GL_RGBA;

      if (testTexture) {
         // ---
         // Draw using texture map
         // ---

         glEnable(GL_TEXTURE_2D);
         glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

         if (texture == 0) {
            glGenTextures(1, &texture);
         }

         glBindTexture(GL_TEXTURE_2D, texture);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
         glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

//         double start = getComputerTime();

         glTexImage2D(GL_TEXTURE_2D, 0, pixelSize, imgWidth, imgHeight, 0, format, GL_UNSIGNED_BYTE, image);

         // B SCAN
         glBegin(GL_POLYGON);

            glTexCoord2f( 1.0f, 1.0f );
            glVertex2f(  1.0f,  1.0f );

            glTexCoord2f( 0.0f, 1.0f );
            glVertex2f( 0.0f, 1.0f );

            glTexCoord2f( 0.0f, 0.0f );
            glVertex2f(  0.0f, 0.0f );

            glTexCoord2f( 1.0f, 0.0f );
            glVertex2f( 1.0f, 0.0f );

         glEnd();

         glDisable(GL_TEXTURE_2D);
//         double end = getComputerTime();
//         double dtime = (end - start);
         //std::cout << "glTexImage2D() dtime = " << dtime << std::endl;
      } else {
         // ---
         // Draw using glDrawPixels()
         // ---

         glRasterPos2f(0.0, 0.0);

         //double start = getComputerTime();

         glDrawPixels(imgWidth, imgHeight, format, GL_UNSIGNED_BYTE, image);

         //double end = getComputerTime();
         //double dtime = (end - start);
         //std::cout << "glDrawPixels() dtime = " << dtime << std::endl;
      }
   }
}

void Display::configure()
{
   BaseClass::configure();

   // Turn off anti-aliasing
   glDisable(GL_POINT_SMOOTH);
   glDisable(GL_LINE_SMOOTH);
   glDisable(GL_POLYGON_SMOOTH);
   glDisable(GL_BLEND);
   glBlendFunc(GL_ONE, GL_ZERO);
}

