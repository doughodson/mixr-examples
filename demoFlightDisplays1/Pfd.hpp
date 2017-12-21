
#ifndef __Pfd_H__
#define __Pfd_H__

#include "mixr/graphics/Page.hpp"
#include "mixr/base/units/angle_utils.hpp"

//------------------------------------------------------------------------------
// Class: Pfd
//
// Description: Tests the pfd.
//------------------------------------------------------------------------------
class Pfd final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(Pfd, mixr::graphics::Page)

public:
   Pfd();

   // set functions
   bool setPitchDeg(const double);        // Sets pitch angle (degs)
   bool setPitchRad(const double);        // Sets pitch angle (rads)
   bool setRollDeg(const double);         // Sets roll angle (degs)
   bool setRollRad(const double);         // Sets roll angle (rads)
   bool setTrueHeading(const double);     // Sets true heading angle (degs)
   bool setCmdHdg(const double);          // Sets commanded heading (degs)
   bool setAirSpeedKts(const double);     // Sets airspeed (kts)
   bool setCmdAirSpdKts(const double);    // Sets commanded airspeed (kts)
   bool setAltitudeFt(const double);      // Sets pressure altitude (ft)
   bool setCmdAltFt(const double);        // Sets commanded altitude (ft)
   bool setGlideslope(const double);      // Sets glide slope deviation (dots)
   bool setLatDev(const double);          // Sets localizer deviation (dots)
   bool setVVI(const double);             // Sets vertical velocity (ft/min)
   bool setSideSlip(const double);        // Sets side slip (degs)
   bool setFltDirBankDeg(const double);   // Sets flight directory commanded bank (deg)
   bool setFltDirPitchDeg(const double);  // Sets flight director commanded pitch (deg)
   bool setFltDirBankRad(const double);   // Sets flight directory commanded bank (rad)
   bool setFltDirPitchRad(const double);  // Sets flight director commanded pitch (rad)
   bool setBaroPress(const double);       // Sets baro pressure (inches)
   bool setRefLat(const double);          // reference latitude
   bool setRefLon(const double);          // reference longitude
   bool setRange(const double);           // range
   bool setGLoad(const double);           // our G-load
   bool setMach(const double);            // machine speed

   // get functions
   double getPitchDeg()            { return pitch; }
   double getPitchRad()            { return static_cast<double>(pitch * mixr::base::angle::D2RCC); }
   double getRollDeg()             { return roll; }
   double getRollRad()             { return static_cast<double>(roll * mixr::base::angle::D2RCC); }
   double getTrueHdg()             { return trueHdg; }
   double getCmdHdg()              { return cmdHdg; }
   double getAirSpdKts()           { return airSpd; }
   double getCmdAirSpdKts()        { return cmdSpd; }
   double getAltFeet()             { return alt; }
   double getCmdAltFeet()          { return cmdAlt; }
   double getGlideSlope()          { return gSlope; }
   double getLatDev()              { return latDev; }
   double getVVI()                 { return vvi; }
   double getSideSlip()            { return slip; }
   double getFltDirBankDeg()       { return fDirBank; }
   double getFltDirBankRad()       { return static_cast<double>(fDirBank * mixr::base::angle::R2DCC); }
   double getFltDirPitchDeg()      { return fDirPitch; }
   double getFltDirPitchRad()      { return static_cast<double>(fDirPitch * mixr::base::angle::R2DCC); }
   double getBaroPressure()        { return baro; }
   double getRefLat()              { return refLat; }
   double getRefLon()              { return refLon; }
   double getRange()               { return range; }
   double getGLoad()               { return gLoad; }
   double getMach()                { return mach; }

   void updateData(const double dt = 0.0) final;

private:
   static const int NCHAR_NAV1_ID{3};
   static const int NCHAR_NAV2_ID{5};

   // pitch and roll
   double pitch{};           // Pitch angle (degs)
   SendData pitchSD;
   SendData hdgPitchSD;      // heading pitch for the heading tape
   double roll{};            // Roll angle (degs)
   SendData rollSD;

   // bank angle
   SendData baSD;
   SendData bascaleSD;

   // heading and nav stuff
   double trueHdg{};         // True heading (degs)
   SendData tHdgSD;

   double cmdHdg{};          // commanded heading (heading bug)
   SendData cmdHdgROSD;

   // airspeed
   double airSpd{100.0};     // Kts
   SendData airSpdTpSD;      // for the airspeed tape
   SendData onesSD;          // for the readout ones tape
   SendData spdRstSD;        // rest of the speed data

   // altitude
   double alt{1000.0};
   SendData alt1SD;
   SendData alt2SD;
   SendData alt3SD;
   SendData altTpSD;         // for the airspeed tape
   SendData altTensSD;
   SendData altSelectSD;     // to select the justification
   SendData altSD;           // for the actual altitude

   // side slip
   double slip{};            // Side slip angle (degs)
   SendData slipSD;

   // glideslope (in dots)
   double gSlope{};
   SendData gSlopeSD;

   // Lateral dev
   double latDev {};
   SendData latDevSD;

   // commanded speed
   double cmdSpd{};          // kts
   SendData aBugSD;
   SendData diffSD;

   // commanded alt
   double cmdAlt{5000.0};
   SendData altBugSD;
   SendData altDiffSD;

   // vvi
   double vvi{};             // ft/min
   SendData vviSD;
   SendData vviROSD;

   // flight director stuff (in inches)
   double fDirBank{};
   SendData fDirBankSD;
   double fDirPitch{};
   SendData fDirPitchSD;

   // barometric pressure
   double baro{};
   SendData baroSD;

   // Hsi send data
   SendData trueHdgSD;
   SendData hdgTapeSD;
   SendData cmdHdgSD;

   double refLat{};
   double refLon{};
   double range{};

   // Gs
   double gLoad{};

   // Mach
   double mach{};            // meter altitude
   SendData mAltSD;
   SendData cmdMAltSD;

   // ghost horizon
   SendData pitchGhostSD;
};

#endif
