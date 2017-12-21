
#ifndef __InstrumentPanel_H__
#define __InstrumentPanel_H__

#include "mixr/ui/glut/GlutDisplay.hpp"

namespace mixr {
namespace models { class Player; }
namespace simulation { class Simulation; class Station; }
}
class DedDisplay;
class MfdDisplay;

//------------------------------------------------------------------------------
// Class:  InstrumentPanel
//
// Description: Sim3 Main Instrument Panel
//
// Events: (all keyboard events)
//   'r' or 'R'   -- Reset simulation
//   'f' or 'F'   -- Toggle simulation freeze
//   '+'          -- Ownship step (to next local air vehicle)
//------------------------------------------------------------------------------
class InstrumentPanel final: public mixr::glut::GlutDisplay
{
   DECLARE_SUBCLASS(InstrumentPanel, mixr::glut::GlutDisplay)

public:
   InstrumentPanel();

   mixr::models::Player* getOwnship();
   mixr::simulation::Simulation* getSimulation();
   mixr::simulation::Station* getStation();

   bool event(const int event, mixr::base::Object* const obj = nullptr) final;
   void updateData(const double dt = 0.0) final;

protected:
   // Key event handlers
   bool onResetKey();
   bool onFreezeKey();
   bool onStepOwnshipKey();

private:
   mixr::base::safe_ptr<mixr::simulation::Station> myStation;

   // ALT Stuff
   double altitude{};         // our current altitude
   SendData altitudeSD;

   // VVI Stuff
   mixr::base::Vec3d vvi;     // velocity vector
   SendData vviSD;
   double pastVvi{};          // our past vvi value (to create a linear filter)

   // AOA Stuff
   double aoa{};              // angle of attack
   SendData aoaSD;
   SendData aoaDigSD;         // angle of attack (digital)

   // HSI Stuff - sends this to our Sim3Hsi class
   double heading{};          // our heading (in degrees)
   SendData headingSD;
   double bpAngle{};          // our bearing pointer angle (degrees)
   SendData bpAngleSD;
   double dme{};              // dme (miles)
   SendData dmeSD;

   // CAS Stuff
   double airSpeed{};         // our air speed (in knots)
   SendData airSpeedSD;

   // G Stuff
   double gForce{};           // g's we are pulling
   SendData gForceSD;
   SendData gForce2SD;        // this is for the analog meter

   // ADI
   double pitch{};            // pitch (degrees)
   SendData pitchSD;
   double roll{};             // roll (degrees)
   SendData rollSD;
   double slip{};             // slip (degrees)
   SendData slipSD;

   // Mach
   double mach{};             // mach number
   SendData machSD;

   // G
   double gload{};            // G
   SendData gloadSD;
};

#endif
