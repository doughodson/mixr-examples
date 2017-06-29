
#ifndef __mixr_xbehaviors_PriorityArbiter_H__
#define __mixr_xbehaviors_PriorityArbiter_H__

#include "mixr/base/ubf/Arbiter.hpp"

namespace mixr {
namespace base { class List; class AbstractAction; }
namespace xbehaviors {

//------------------------------------------------------------------------------
// Class: PriorityArbiter
//
// Description: Example fusion arbiter for a plane
//------------------------------------------------------------------------------
class PriorityArbiter : public base::ubf::Arbiter
{
   DECLARE_SUBCLASS(PriorityArbiter, base::ubf::Arbiter)

public:
   PriorityArbiter();

   virtual base::ubf::AbstractAction* genComplexAction(base::List* const actionSet) override;

private:

   // Trim change might not be valid if the plane is in the middle of a maneuver
   // and the change would go against the intended control stick action.  If so,
   // invalidate the trim change.
   // Returns nothing, but modifies what the action object points to
   void trimChangeValidation(base::ubf::AbstractAction* const);
};

}
}

#endif
