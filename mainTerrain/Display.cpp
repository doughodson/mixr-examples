
#include "Display.hpp"

#include "mixr/terrain/ITerrain.hpp"

#include "mixr/base/numeric/Boolean.hpp"
#include "mixr/base/numeric/Integer.hpp"

#include "mixr/base/colors/IColor.hpp"
#include "mixr/base/colors/Rgb.hpp"
#include "mixr/base/colors/Hsva.hpp"

#include "mixr/base/String.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"

#include "mixr/base/units/angles.hpp"
#include "mixr/base/units/lengths.hpp"

#include "mixr/base/util/nav_utils.hpp"
#include "mixr/base/util/system_utils.hpp"

#include <cmath>

using namespace mixr;

IMPLEMENT_SUBCLASS(Display, "TerrainDisplay")

BEGIN_SLOTTABLE(Display)
   "terrain",        //  1) Terrain database
   "minElevation",   //  2) Minimum elevation (Distance) (default: use database max value)
   "maxElevation",   //  3) Maximum elevation (Distance) (default: use database max value)
   "altitude",       //  4) Reference altitude (Distance) (default: 15000 feet)
   "lookAngle",      //  5) Antenna look angle (Angle) (default: 0 degrees)
   "beamWidth",      //  6) Antenna Beam Width (Angle) (default: 180 degrees)
   "colorDepth",     //  7) Color scale:  gray(0), color(1), green(2) (default: gray)
   "interpolate",    //  8) Interpolate flag (default: false)
   "shadows",        //  9) Shadow test enabled
   "aac",            // 10) Aspect Angle test enabled
   "earthCurvature", // 11) Earth curvature test enabled
   "textureTest",    // 12) Texture test enabled
END_SLOTTABLE(Display)

BEGIN_SLOT_MAP(Display)
   ON_SLOT( 1, setSlotTerrain,            terrain::ITerrain)
   ON_SLOT( 2, setSlotMinElevation,       base::Length)
   ON_SLOT( 3, setSlotMaxElevation,       base::Length)
   ON_SLOT( 4, setSlotAltitude,           base::Length)
   ON_SLOT( 5, setSlotLookAngle,          base::Angle)
   ON_SLOT( 6, setSlotBeamWidth,          base::Angle)
   ON_SLOT( 7, setSlotColorScale,         base::Integer)
   ON_SLOT( 8, setSlotInterpolate,        base::Boolean)
   ON_SLOT( 9, setSlotShadowsTest,        base::Boolean)
   ON_SLOT(10, setSlotAacTest,            base::Boolean)
   ON_SLOT(11, setSlotEarthCurvatureTest, base::Boolean)
   ON_SLOT(12, setSlotTextureTest,        base::Boolean)
END_SLOT_MAP()

Display::Display()
{
   STANDARD_CONSTRUCTOR()
}

void Display::copyData(const Display& org, const bool)
{
   BaseClass::copyData(org);

   if (org.terrain != nullptr)
      setSlotTerrain( org.terrain->clone() );
   else
      setSlotTerrain( nullptr );

   maxElev = org.maxElev;
   minElev = org.minElev;
   altitude = org.altitude;
   lookAngle = org.lookAngle;
   beamWidth = org.beamWidth;

   haveMaxElev = org.haveMaxElev;
   haveMinElev = org.haveMinElev;
   colorDepth = org.colorDepth;
   interpolate = org.interpolate;
   testShadows = org.testShadows;
   testAac = org.testAac;
   testEarthCurv = org.testEarthCurv;
   testTexture = org.testTexture;

   copyImageMemory(org);
}

void Display::deleteData()
{
   setSlotTerrain( nullptr );
   freeImageMemory();
}

void Display::reset()
{
   if (terrain != nullptr) terrain->reset();
   BaseClass::reset();
}

//------------------------------------------------------------------------------
// set functions
//------------------------------------------------------------------------------
bool Display::setMinElevation(const double elev)
{
   minElev = elev;
   haveMinElev = true;
   return true;
}

bool Display::clearMinElevation()
{
   minElev = 0;
   haveMinElev = false;
   return true;
}

bool Display::setMaxElevation(const double elev)
{
   maxElev = elev;
   haveMaxElev = true;
   return true;
}

bool Display::clearMaxElevation()
{
   maxElev = 0;
   haveMaxElev = false;
   return true;
}

//------------------------------------------------------------------------------
// Slot functions
//------------------------------------------------------------------------------
bool Display::setSlotTerrain(terrain::ITerrain* const msg)
{
   if (terrain != nullptr) terrain->unref();
   terrain = msg;
   if (terrain != nullptr) terrain->ref();
   return true;
}

// Set min elevation
bool Display::setSlotMinElevation(const base::Length* const x)
{
   bool ok{};
   if (x != nullptr) {
      ok = setMinElevation(x->getValueInMeters());
   }
   return ok;
}

// Set max elevation
bool Display::setSlotMaxElevation(const base::Length* const x)
{
   bool ok{};
   if (x != nullptr) {
      ok = setMaxElevation(x->getValueInMeters());
   }
   return ok;
}

// Set max elevation
bool Display::setSlotAltitude(const base::Length* const x)
{
   bool ok{};
   if (x != nullptr) {
      altitude = x->getValueInMeters();
      ok = true;
   }
   return ok;
}

// Set antenna look angle
bool Display::setSlotLookAngle(const base::Angle* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      lookAngle = msg->getValueInDegrees();
      ok = true;
   }
   return ok;
}

// Set beam width
bool Display::setSlotBeamWidth(const base::Angle* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      beamWidth = msg->getValueInDegrees();
      ok = true;
   }
   return ok;
}

// Set color scale flag
bool Display::setSlotColorScale(const base::Integer* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      const int s{msg->asInt()};
      if (s >= 0 && s <= 2) {
         colorDepth = static_cast<ColorDepth>(s);
         ok = true;
      }
   }
   return ok;
}

// Set interpolate flag
bool Display::setSlotInterpolate(const base::Boolean* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      interpolate = msg->asBool();
      ok = true;
   }
   return ok;
}

// Set shadow test flag
bool Display::setSlotShadowsTest(const base::Boolean* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      testShadows = msg->asBool();
      ok = true;
   }
   return ok;
}

// Set AAC test flag
bool Display::setSlotAacTest(const base::Boolean* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      testAac = msg->asBool();
      ok = true;
   }
   return ok;
}

// Set earth curvature test flag
bool Display::setSlotEarthCurvatureTest(const base::Boolean* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      testEarthCurv = msg->asBool();
      ok = true;
   }
   return ok;
}


// Set texture test flag
bool Display::setSlotTextureTest(const base::Boolean* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      testTexture = msg->asBool();
      ok = true;
   }
   return ok;
}


//------------------------------------------------------------------------------
// updateData() -- update background data here
//------------------------------------------------------------------------------
void Display::updateData(const double dt)
{
   // Get Viewport width and height
   GLsizei vpWidth{};
   GLsizei vpHeight{};
   getViewportSize(&vpWidth, &vpHeight);

   // Generate an image when we have the terrain, a view port and we don't have an image
   if ( terrain != nullptr && terrain->isDataLoaded() &&
        vpWidth > 0 && vpHeight > 0 &&
        image == nullptr) {

      GLsizei vpWidth{1024}; // default is texture sizes
      GLsizei vpHeight{1024};
      if (!testTexture) {
         // When not using textures, get the viewport parameters

         // Get the maximum number of points
         GLint vpX{}, vpY{};
         getViewport(&vpX, &vpY, &vpWidth, &vpHeight);

         // Make sure width is correct for a 4 byte alignment
         GLsizei w0{(vpWidth * PIXEL_SIZE)};
         GLsizei w4{(w0 / 4) * 4};  // Truncate to 4 bytes
         vpWidth = w4 / PIXEL_SIZE;
      }

      // Allocate the image memory
      bool ok{initImageMemory(vpWidth, vpHeight)};
      if (ok) {

         const int NUM_COLUMNS{imgWidth};
         const int NUM_ROWS{imgHeight};

         // Allocating space for 'multi-point' tests
         double* elevations{};
         double* aacData{};
         bool* validFlgs{};
         bool* maskFlgs{};
         if (testShadows || testAac || testEarthCurv) {
            elevations = new double[NUM_ROWS];
            aacData = new double[NUM_ROWS];
            validFlgs = new bool[NUM_ROWS];
            maskFlgs = new bool[NUM_ROWS];
         }

         // Max elevation (Z) value (meters)
         double maxz{terrain->getMaxElevation()};
         if (isMaxElevValid()) maxz = getMaxElevation();

         // Min elevation (Z) value (meters)
         double minz{terrain->getMinElevation()};
         if (isMinElevValid()) minz = getMinElevation();

         // Delta altitude (meters)
//         double deltaElev = maxz - minz + 1;

         // Compute delta (range of) latitude and longitude
         const double deltaLat{terrain->getLatitudeNE()  - terrain->getLatitudeSW()};
         const double deltaLon{terrain->getLongitudeNE() - terrain->getLongitudeSW()};

         // Compute center position (degs)
         const double cLat{terrain->getLatitudeSW()  + deltaLat / 2.0};
         const double cLon{terrain->getLongitudeSW() + deltaLon / 2.0};

         // Compute distance between points with zoom factor (degs)
         const double spacingLat{deltaLat / NUM_ROWS};
         const double spacingLon{deltaLon / NUM_COLUMNS};

         // Generate the earth's curvature effect
         double* curvature{};
         if (testEarthCurv) {
            curvature = new double[NUM_ROWS];
            const auto radius = static_cast<double>(base::nav::ERAD60 * base::length::NM2M);
            const auto maxRng = static_cast<double>(deltaLat * 60.0f * base::length::NM2M);
            for (int irow = 0; irow < NUM_ROWS; irow++) {
               const double curRng{maxRng * static_cast<double>(irow)/static_cast<double>(NUM_ROWS)};
               const double arc{curRng / radius};
               double cs{1.0};
               const double c0{std::cos(arc)};
               if (c0 != 0) cs = 1.0/c0;
               curvature[irow] = radius * (cs  - 1.0f);
            }
         }

         const base::Hsva* grayTable[2]{};
         //                              hue     sat  value  alpha
         grayTable[0] = new base::Hsva(  120.0,  0.0,  0.0,  1.0 );  // black0
         grayTable[1] = new base::Hsva(  120.0,  0.0,  1.0,  1.0 );  // white0

         const base::Hsva* colorTable[7]{};
         //                              hue     sat  value  alpha
         colorTable[0] = new base::Hsva( 240.0,  1.0,  1.0,  1.0 );  // blue
         colorTable[1] = new base::Hsva( 180.0,  1.0,  1.0,  1.0 );  // cyan
         colorTable[2] = new base::Hsva( 120.0,  1.0,  1.0,  1.0 );  // green
         colorTable[3] = new base::Hsva(  60.0,  1.0,  1.0,  1.0 );  // yellow
         colorTable[4] = new base::Hsva(   0.0,  1.0,  1.0,  1.0 );  // red
         colorTable[5] = new base::Hsva( 300.0,  1.0,  1.0,  1.0 );  // magenta
         colorTable[6] = new base::Hsva( 300.0,  0.05, 1.0,  1.0 );  // white0


         const base::Hsva* greenTable[19]{};
         //                               hue     sat  value    alpha
         greenTable[0]  = new base::Hsva( 120.0,  1.0,  0.0,     1.0 );
         greenTable[1]  = new base::Hsva( 120.0,  1.0,  0.0872,  1.0 );
         greenTable[2]  = new base::Hsva( 120.0,  1.0,  0.1736,  1.0 );
         greenTable[3]  = new base::Hsva( 120.0,  1.0,  0.2588,  1.0 );
         greenTable[4]  = new base::Hsva( 120.0,  1.0,  0.3420,  1.0 );
         greenTable[5]  = new base::Hsva( 120.0,  1.0,  0.4226,  1.0 );
         greenTable[6]  = new base::Hsva( 120.0,  1.0,  0.5000,  1.0 );
         greenTable[7]  = new base::Hsva( 120.0,  1.0,  0.5736,  1.0 );
         greenTable[8]  = new base::Hsva( 120.0,  1.0,  0.6428,  1.0 );
         greenTable[9]  = new base::Hsva( 120.0,  1.0,  0.7071,  1.0 );
         greenTable[10] = new base::Hsva( 120.0,  1.0,  0.7660,  1.0 );
         greenTable[11] = new base::Hsva( 120.0,  1.0,  0.8192,  1.0 );
         greenTable[12] = new base::Hsva( 120.0,  1.0,  0.8660,  1.0 );
         greenTable[13] = new base::Hsva( 120.0,  1.0,  0.9063,  1.0 );
         greenTable[14] = new base::Hsva( 120.0,  1.0,  0.9397,  1.0 );
         greenTable[15] = new base::Hsva( 120.0,  1.0,  0.9659,  1.0 );
         greenTable[16] = new base::Hsva( 120.0,  1.0,  0.9848,  1.0 );
         greenTable[17] = new base::Hsva( 120.0,  1.0,  0.9962,  1.0 );
         greenTable[18] = new base::Hsva( 120.0,  1.0,  1.0,     1.0 );

         std::cout << "start image generation" << std::endl;
         const double start{base::getComputerTime()};

         for (int icol = 0; icol < NUM_COLUMNS; icol++) {

//            int halfway = NUM_COLUMNS / 2;

            // the Lat/long of the southern most point
            const double longitude{cLon + (icol - NUM_COLUMNS/2) * spacingLon};

            if (testShadows || testAac || testEarthCurv) {

               for (int irow = 0; irow < NUM_ROWS; irow++) {
                  elevations[irow] = 0;
                  aacData[irow] = 1.0f;
                  validFlgs[irow] = false;
                  maskFlgs[irow] = false;
               }

               // the Lat/long of the southern most point
               const double latitude{cLat + (0 - NUM_ROWS/2) * spacingLat};
               const double maxRng{static_cast<double>(deltaLat * 60.0f * base::length::NM2M)};

               // Direction
               //double direction = 30.0f * static_cast<double>(icol - NUM_COLUMNS/2)/static_cast<double>(NUM_COLUMNS/2);
               double direction{};

               // get a strip of elevations from south to north
               /*unsigned int num = */ terrain->getElevations(elevations, validFlgs, NUM_ROWS, latitude, longitude, direction, maxRng, interpolate);

               // Apply earth curvature effects to terrain elevations
               if (testEarthCurv) {
                  for (int irow = 0; irow < NUM_ROWS; irow++) {
                     elevations[irow] -= curvature[irow];
                  }
               }

               // Generate Masks
               if (testShadows) {
                  terrain::ITerrain::vbwShadowChecker(maskFlgs, elevations, validFlgs, NUM_ROWS, maxRng, altitude, lookAngle, beamWidth);
               }

               // Compute AAC data
               if (testAac) {
                  //simulation::Terrain::aac(aacData, elevations, maskFlgs, NUM_ROWS, maxRng, altitude);
                  const auto angle = static_cast<double>(-10.0f * base::angle::D2RCC);
                  base::Vec2d vec(std::cos(angle),std::sin(angle));
                  terrain::ITerrain::cLight(aacData, elevations, maskFlgs, NUM_ROWS, maxRng, vec);
               }

            }

            // Draw a line along the Y points (moving from south to north along the latitude lines)
            for (int irow = 0; irow < NUM_ROWS; irow++) {

               base::Vec3d color(0,0,0);
               double elev{};
               bool valid{};

              if (testShadows || testAac || testEarthCurv) {
                  // multi-point test: get the elevation from the array
                  if (validFlgs[irow]) {
                     elev = elevations[irow];
                     valid = true;
                  }
               } else {
                  // Single point test: compute the latitude of this point and get the elevation
                  double latitude{cLat + (irow - NUM_ROWS/2) * spacingLat};
                  valid = terrain->getElevation(&elev, latitude, longitude, interpolate);
               }

               // If valid and not masked, convert the elevation to a color (or gray) value
               if (valid && !(testShadows && maskFlgs[irow])) {
                  if (colorDepth == ColorDepth::GRAY)
                     terrain::ITerrain::getElevationColor(elev, minz, maxz, grayTable,  2, color);
                  else if (colorDepth == ColorDepth::COLOR)
                     terrain::ITerrain::getElevationColor(elev, minz, maxz, colorTable, 7, color);
                  else if (colorDepth == ColorDepth::GREEN)
                     terrain::ITerrain::getElevationColor(elev, minz, maxz, greenTable,  19, color);
               }

               // Apply AAC data
               if (valid && testAac) {
                  color = color * aacData[irow];
               }

               //if (icol == 100) {
               //   std::cout << icol << ", " << irow << " = " << elev << " [ " << color.x() << ", " << color.y() << ", " << color.z() << " ]" << std::endl;
               //}

               // store this color
               GLsizei idx{irow*imgWidth*PIXEL_SIZE + icol*PIXEL_SIZE};
               image[idx+0] = GLubyte( 255.0 * color[0] );
               image[idx+1] = GLubyte( 255.0 * color[1] );
               image[idx+2] = GLubyte( 255.0 * color[2] );
            }
         }

         const double end{base::getComputerTime()};
         const double dtime{(end - start)};
         std::cout << "Image finished: time(s) = " << dtime << ", per line(us) = "
                   << (dtime/static_cast<double>(NUM_COLUMNS))*1000000.0 << std::endl;

      }

   }

   BaseClass::updateData(dt);
}

//------------------------------------------------------------------------------
// drawFunc()
//------------------------------------------------------------------------------
void Display::drawFunc()
{
   if (image != nullptr) {
      if (testTexture) {
         // ---
         // Draw using texture map
         // ---

         // enable textures, if we need to
         glEnable(GL_TEXTURE_2D);
         if (texture == 0) {
            glGenTextures(1,&texture);
         }

         // set our texture environment
         glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

         glBindTexture(GL_TEXTURE_2D, texture);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
         glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

         double start{base::getComputerTime()};

         glTexImage2D(GL_TEXTURE_2D, 0, PIXEL_SIZE, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

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

         double end{base::getComputerTime()};
         double dtime{end - start};
         std::cout << "glTexImage2D() dtime = " << dtime << std::endl;
         glDisable(GL_TEXTURE_2D);
      } else {
         // ---
         // Draw using glDrawPixels()
         // ---

         glRasterPos2f(0.0, 0.0);

         double start{base::getComputerTime()};

         glDrawPixels(imgWidth, imgHeight, GL_RGB, GL_UNSIGNED_BYTE, image);

         double end{base::getComputerTime()};
         double dtime{end - start};
         std::cout << "glDrawPixels() dtime = " << dtime << std::endl;
      }
   }
}

//-----------------------------------------------------------------------------
// configure() -- function to configure the display
//-----------------------------------------------------------------------------
void Display::configure()
{
   BaseClass::configure();

   // Turn off anti-aliasing
   glDisable(GL_POINT_SMOOTH);
   glDisable(GL_LINE_SMOOTH);
   glDisable(GL_POLYGON_SMOOTH);
   glDisable(GL_BLEND);
   glBlendFunc(GL_ONE,  GL_ZERO);
}

//------------------------------------------------------------------------------
// copy the image memory from another object
//------------------------------------------------------------------------------
bool Display::copyImageMemory(const Display& org)
{
   // First free our old memory
   freeImageMemory();

   // Now allocate the new memory (if needed)
   bool ok{initImageMemory(org.imgWidth, org.imgHeight)};
   if (ok) {
      for (GLsizei irow = 0; irow < imgHeight; irow++) {
         for (GLsizei icol = 0; icol < imgWidth; icol++) {
            GLsizei idx{irow*imgWidth*PIXEL_SIZE + icol*PIXEL_SIZE};
            image[idx+0] = org.image[idx+0];
            image[idx+1] = org.image[idx+1];
            image[idx+2] = org.image[idx+2];
         }
      }
   }
   return true;
}


//------------------------------------------------------------------------------
// allocate and init image memory
//------------------------------------------------------------------------------
bool Display::initImageMemory(const GLsizei width, const GLsizei height)
{
   bool ok{};
   if (width > 0  && width <= MAX_IMAGE_WIDTH &&
      height > 0 && height <= MAX_IMAGE_HEIGHT) {

      // allocate space for the image
      GLubyte* tmpImage{new GLubyte[width*height*PIXEL_SIZE]};
      if (tmpImage != nullptr) {

         // and set our member variables
         image = tmpImage;
         imgWidth = width;
         imgHeight = height;
         ok = true;

      }
   }
   return ok;
}

//------------------------------------------------------------------------------
// free the image memory
//------------------------------------------------------------------------------
void Display::freeImageMemory()
{
   // temp pointer
   GLubyte* tmpImage{image};

   // Clear the member variables
   image = nullptr;
   imgWidth = 0;
   imgHeight = 0;

   // Free the memory
   if (tmpImage != nullptr) delete[] tmpImage;

   // Free the texture
   if (texture != 0) {
      glDeleteTextures(1,&texture);
      texture = 0;
   }
}

