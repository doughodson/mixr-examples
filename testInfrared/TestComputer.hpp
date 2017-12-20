
#ifndef __TestComputer_H__
#define __TestComputer_H__

#include "mixr/models/system/OnboardComputer.hpp"

//------------------------------------------------------------------------------
// Class: TestComputer
//
// Description:
//    Onboard computer for IrMissile, provides basic functionality
//    Controls a TrackManager, IrSensor, & IrSeeker.
//    Updates gimbal to point at predicted az/el of strongest signal in IFOV
//    Provides these methods in public i/f mainly for IrMissile
//       haveTgt()   true if computer/seeker currently tracking a target
//
//------------------------------------------------------------------------------
class TestComputer final: public mixr::models::OnboardComputer
{
    DECLARE_SUBCLASS(TestComputer, mixr::models::OnboardComputer)

public:
   TestComputer();
   bool haveTgt() const { return haveTarget; }

   void updateShootList(const bool step = false) final;      // Updates the shoot list

   void updateTC(const double dt = 0.0) final;

   void reset() final;

protected:
   // process() subfunction, tells computer if we are tracking a target or not
   bool processIr();

   void process(const double dt) final;

private:
   bool uncaged{};      // flag that indicates whether gimbal is free to track target
   bool haveTarget{};   // flag indicating if we have a target track
};

#endif
