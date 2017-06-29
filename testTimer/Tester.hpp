
#ifndef __Tester_H__
#define __Tester_H__

#include "mixr/base/Component.hpp"

namespace mixr {
namespace base { class PairStream; }
}

//------------------------------------------------------------------------------
// Class: Tester
// Description: Container class for the interval timers being tested
//
// Factory name: Tester
// Slots:
//    timers   <PairStream>   ! List of timers to be tested
//------------------------------------------------------------------------------
class Tester : public mixr::base::Component
{
   DECLARE_SUBCLASS(Tester, mixr::base::Component)

public:
   Tester();

   bool areAllActiveTimerAlarmsOn() const;

   void printTimers() const;

   // Restart all of the timers -- they're left in an active state
   void restartAllTimers();

   virtual void reset() override;

protected:
   bool setSlotTimers(const mixr::base::PairStream* const msg);

private:
   mixr::base::PairStream* timers {};    // List of timers
};

#endif
