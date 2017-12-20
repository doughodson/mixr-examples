
#include "Tester.hpp"

#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"
#include "mixr/base/Timers.hpp"

#include <cstdio>

IMPLEMENT_SUBCLASS(Tester, "Tester")

BEGIN_SLOTTABLE(Tester)
   "timers"            // 1: List of up/down timers to be tested
END_SLOTTABLE(Tester)

BEGIN_SLOT_MAP(Tester)
   ON_SLOT(1, setSlotTimers, mixr::base::PairStream)
END_SLOT_MAP()

Tester::Tester()
{
   STANDARD_CONSTRUCTOR()
}

void Tester::copyData(const Tester& org, const bool)
{
   BaseClass::copyData(org);

   setSlotTimers(org.timers);
}

void Tester::deleteData()
{
   setSlotTimers(nullptr);
}

//------------------------------------------------------------------------------
// Return true if all alarms are set
//------------------------------------------------------------------------------
bool Tester::areAllActiveTimerAlarmsOn() const
{
   bool on{true};

   if (timers != nullptr) {

      const mixr::base::List::Item* item{timers->getFirstItem()};
      while (item != nullptr && on) {
         const auto pair = static_cast<const mixr::base::Pair*>(item->getValue());
         const auto timer = static_cast<const mixr::base::Timer*>(pair->object());
         on = timer->alarm() || timer->isNotRunning();
         item = item->getNext();
      }

   }
   return on;
}

//------------------------------------------------------------------------------
// Print the alarm status
//------------------------------------------------------------------------------
void Tester::printTimers() const
{
   if (timers != nullptr) {

      const mixr::base::List::Item* item{timers->getFirstItem()};
      while (item != nullptr) {
         const auto pair = static_cast<const mixr::base::Pair*>(item->getValue());
         const auto timer = static_cast<const mixr::base::Timer*>(pair->object());

         std::printf("  timer(%s)", pair->slot()->getString());
         std::printf(" = %4.1f", timer->getCurrentTime());

         if (timer->getType() == mixr::base::Timer::Type::UP) std::printf(", up");
         else std::printf(", down");

         if (timer->isRunning()) std::printf(", active");
         else std::printf(", inactive");

         std::printf(", alarm(%4.1f", timer->getAlarmTime());
         if (timer->alarm()) std::printf(", ON)");
         std::printf(", OFF);");

         std::printf("\n");

         item = item->getNext();
      }
   }
}

//------------------------------------------------------------------------------
// Restart all of the timers -- they're left in an active state
//------------------------------------------------------------------------------
void Tester::restartAllTimers()
{
   if (timers != nullptr) {

      mixr::base::List::Item* item{timers->getFirstItem()};
      while (item != nullptr) {
         const auto pair = static_cast<mixr::base::Pair*>(item->getValue());
         const auto timer = static_cast<mixr::base::Timer*>(pair->object());
         timer->restart();
         item = item->getNext();
      }
   }
}

void Tester::reset()
{
   BaseClass::reset();

   if (timers != nullptr) {
      mixr::base::List::Item* item{timers->getFirstItem()};
      while (item != nullptr) {
         const auto pair = static_cast<mixr::base::Pair*>(item->getValue());
         const auto timer = static_cast<mixr::base::Timer*>(pair->object());
         timer->reset();
         item = item->getNext();
      }

   }
}

bool Tester::setSlotTimers(const mixr::base::PairStream* const msg)
{
   // Clear the old timer list
   if (timers != nullptr) timers->unref();
   timers = nullptr;

   // Copy the new timer list, and make sure we have only Timers
   if (msg != nullptr) {

      const auto newList = new mixr::base::PairStream();

      unsigned int n{};
      const mixr::base::List::Item* item{msg->getFirstItem()};
      while (item != nullptr) {
         n++;
         const auto pair = static_cast<const mixr::base::Pair*>(item->getValue());
         const auto timer = dynamic_cast<const mixr::base::Timer*>(pair->object());
         if (timer != nullptr) {
            mixr::base::Pair* newPair{pair->clone()};
            newList->put(newPair);
         } else {
            std::cerr << "Tester::setSlotTimers() rejecting item# " << n << "; not a valid Timer object" << std::endl;
         }
         item = item->getNext();
      }

      if (newList->entries() > 0) {
         timers = newList;
         timers->ref();
      }
      newList->unref();
   }
   return true;
}

