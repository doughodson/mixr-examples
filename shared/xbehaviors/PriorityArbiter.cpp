
#include "PriorityArbiter.hpp"

#include "mixr/base/List.hpp"

#include "PlaneAction.hpp"
#include <iostream>

namespace mixr {
namespace xbehaviors {

IMPLEMENT_SUBCLASS(PriorityArbiter, "PriorityArbiter")
EMPTY_SLOTTABLE(PriorityArbiter)
EMPTY_CONSTRUCTOR(PriorityArbiter)
EMPTY_COPYDATA(PriorityArbiter)
EMPTY_DELETEDATA(PriorityArbiter)

base::ubf::AbstractAction* PriorityArbiter::genComplexAction(base::List* const actionSet)
{
   const auto complexAction = new PlaneAction;

   int maxPitchVote{};
   int maxRollVote{};
   int maxHeadingVote{};
   int maxFireVote{};
   int maxThrottleVote{};
   int maxPitchTrimVote{};

   // process entire action set
   const base::List::Item* item{actionSet->getFirstItem()};
   while (item != nullptr) {
      const auto action = dynamic_cast<const PlaneAction*>(item->getValue());
      if (action!=nullptr) {
         if (action->isHeadingChanged() && action->getVote() > maxHeadingVote) {
            complexAction->setHeading(action->getHeading());
            maxHeadingVote = action->getVote();
         }

         if (action->isPitchChanged() && action->getVote() > maxPitchVote) {
            complexAction->setPitch(action->getPitch());
            maxPitchVote = action->getVote();
         }

         if (action->isRollChanged() && action->getVote() > maxRollVote) {
            complexAction->setRoll(action->getRoll());
            maxRollVote = action->getVote();
         }

         if (action->isFireMissileChanged() && action->getVote() > maxFireVote) {
            complexAction->setFireMissile(action->getFireMissile());
            maxFireVote = action->getVote();
         }

         if (action->isThrottleChanged() && action->getVote() > maxThrottleVote) {
            complexAction->setThrottle(action->getThrottle());
            maxThrottleVote = action->getVote();
         }

         if (action->isPitchTrimChanged() && action->getVote() > maxPitchTrimVote) {
            complexAction->setPitchTrim(action->getPitchTrim());
            maxPitchTrimVote = action->getVote();
         }
      } else {
         std::cout << "Action NOT a PlaneAction\n";
      }

      // next action
      item = item->getNext();
   }

   //
   trimChangeValidation(complexAction);

   return complexAction;
}

void PriorityArbiter::trimChangeValidation(base::ubf::AbstractAction* const complexAction)
{
   const auto action = static_cast<PlaneAction*>(complexAction);

   if ( action->isPitchChanged() && action->isPitchTrimChanged() ) {
      //ignore pitch trim ONLY if the change goes against the action we want to
      //take with the control stick.
      if ( action->getPitch()>0 ) {
         //std::cout<<"Pitch: "<<action->getPitch();
         if ( action->getPitchTrim()<0 ) {
            //std::cout<<" Trim: "<<action->getPitchTrim();
            action->setPitchTrim(0);
         }
      } else {
         //std::cout<<"Pitch: "<<action->getPitch();
         if ( action->getPitchTrim()>0 ) {
            //std::cout<<" Trim: "<<action->getPitchTrim();
            action->setPitchTrim(0);
         }
      }
      //std::cout<<" "<<endl;
   }
   return;
}

}
}


