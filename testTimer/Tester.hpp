
#ifndef __Tester_HPP__
#define __Tester_HPP__

#include "mixr/base/IComponent.hpp"

namespace mixr {
namespace base { class IPairStream; }
}

//------------------------------------------------------------------------------
// Class: Tester
// Description: Container class for the interval timers being tested
//
// Factory name: Tester
// Slots:
//    timers   <IPairStream>   ! List of timers to be tested
//------------------------------------------------------------------------------
class Tester final: public mixr::base::IComponent
{
   DECLARE_SUBCLASS(Tester, mixr::base::IComponent)

public:
   Tester();

   bool areAllActiveTimerAlarmsOn() const;

   void printTimers() const;

   // Restart all of the timers -- they're left in an active state
   void restartAllTimers();

   void reset() final;

private:
   mixr::base::IPairStream* timers{};    // List of timers

private:
   // slot table helper methods
   bool setSlotTimers(const mixr::base::IPairStream* const);
};

#endif
