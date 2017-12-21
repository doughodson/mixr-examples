
#ifndef __AdiDisplay_H__
#define __AdiDisplay_H__

#include "mixr/ui/glut/GlutDisplay.hpp"

namespace mixr {
namespace models { class Aircraft; }
namespace simulation { class Station; }
}

//------------------------------------------------------------------------------
// Class: AdiDisplay
//------------------------------------------------------------------------------
class AdiDisplay final: public mixr::glut::GlutDisplay
{
   DECLARE_SUBCLASS(AdiDisplay, mixr::glut::GlutDisplay)

public:
   AdiDisplay();

   void updateData(const double dt = 0.0) final;

private:
   mixr::models::Aircraft* getOwnship();
   mixr::simulation::Station* getStation();

   mixr::base::safe_ptr<mixr::simulation::Station> myStation;

   //-----------------------------
   double psiRO{};     // [deg]
   double thtRO{};     // [deg]
   double phiRO{};     // [deg]
   double velRO{};     // [kts]
   double altRO{};     // [ft]

   double pRO{};       // [deg/sec]
   double qRO{};       // [deg/sec]
   double rRO{};       // [deg/sec]

   double bankADI{};   // [deg]
   double pitchADI{};  // [deg]

   //-----------------------------
   SendData psiRO_SD;
   SendData thtRO_SD;
   SendData phiRO_SD;
   SendData velRO_SD;
   SendData altRO_SD;

   SendData pRO_SD;
   SendData qRO_SD;
   SendData rRO_SD;

   SendData bankADI_SD;
   SendData pitchADI_SD;
};

#endif
