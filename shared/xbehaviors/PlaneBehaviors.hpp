//------------------------------------------------------------------------------
// Classes: PlaneBehaviorBase
//          PlaneBehaviorBase -> PlaneFire
//          PlaneBehaviorBase -> PlaneFlyStraight
//          PlaneBehaviorBase -> PlaneFollowEnemy
//          PlaneBehaviorBase -> PlaneTurn
//          PlaneBehaviorBase -> PlaneSlowTurn
//          PlaneBehaviorBase -> PlaneClimb
//          PlaneBehaviorBase -> PlaneDive
//          PlaneBehaviorBase -> PlaneTrim
//          PlaneBehaviorBase -> PlaneRoll
//          PlaneBehaviorBase -> PlaneBarrelRoll
//          PlaneBehaviorBase -> PlaneLoop
//------------------------------------------------------------------------------
#ifndef __mixr_xbehaviors_PlaneBehaviors_H__
#define __mixr_xbehaviors_PlaneBehaviors_H__

#include "mixr/base/ubf/AbstractBehavior.hpp"

namespace mixr {
namespace base { class Distance; class State; }
namespace base {
namespace ubf { class AbstractState; class AbstractAction; }
}
namespace xbehaviors {

//------------------------------------------------------------------------------
// Class: PlaneBehavior
// Description: Abstract base class for concrete plane behaviors
//------------------------------------------------------------------------------
class PlaneBehavior : public base::ubf::AbstractBehavior
{
  DECLARE_SUBCLASS(PlaneBehavior, base::ubf::AbstractBehavior)

public:
   PlaneBehavior();

protected:
   int voteOnIncomingMissile{};
   int voteOnCriticalAltitude{};
   double criticalAltitude{3500.0};

private:
   // slot table helper methods
   bool setSlotCriticalAltitude(const base::Distance* const);
   bool setSlotVoteOnCriticalAltitude(const base::Number* const);
   bool setSlotVoteOnIncomingMissile(const base::Number* const);
};

//------------------------------------------------------------------------------
// Class: PlaneFire
//
// Description: Behavior class that shoots missiles at enemy planes
//------------------------------------------------------------------------------
class PlaneFire final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneFire, PlaneBehavior)

public:
   PlaneFire();
   base::ubf::AbstractAction* genAction(const base::ubf::AbstractState* const state, const double dt) final;

private:
   double maxDistance{15500.0};

private:
   // slot table helper methods
   bool setSlotMaxDistance(const base::Distance* const);
};

class PlaneFlyStraight final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneFlyStraight, PlaneBehavior)

public:
   PlaneFlyStraight();
   base::ubf::AbstractAction* genAction(const base::ubf::AbstractState* const state, const double dt) final;

private:
   double holdingAltitude{4500.0};
};

class PlaneFollowEnemy final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneFollowEnemy, PlaneBehavior)

public:
   PlaneFollowEnemy();
   base::ubf::AbstractAction* genAction(const base::ubf::AbstractState* const state, const double dt) final;
};

class PlaneTurn final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneTurn, PlaneBehavior)

public:
   PlaneTurn();
   base::ubf::AbstractAction* genAction(const base::ubf::AbstractState* const state, const double dt) final;
};

class PlaneSlowTurn final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneSlowTurn, PlaneBehavior)

public:
   PlaneSlowTurn();
   base::ubf::AbstractAction* genAction(const base::ubf::AbstractState* const state, const double dt) final;
};

class PlaneClimb final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneClimb, PlaneBehavior)

public:
   PlaneClimb();
   base::ubf::AbstractAction* genAction(const base::ubf::AbstractState* const state, const double dt) final;
};

class PlaneDive final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneDive, PlaneBehavior)

public:
   PlaneDive();
   base::ubf::AbstractAction* genAction(const base::ubf::AbstractState* const state, const double dt) final;
};

class PlaneTrim final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneTrim, PlaneBehavior)

public:
   PlaneTrim();
   base::ubf::AbstractAction* genAction(const base::ubf::AbstractState* const state, const double dt) final;

private:
   double holdingAltitude{4500.0};
   int count{};
};

class PlaneRoll final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneRoll, PlaneBehavior)

public:
   PlaneRoll();
   base::ubf::AbstractAction* genAction(const base::ubf::AbstractState* const state, const double dt) final;
};

class PlaneBarrelRoll final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneBarrelRoll, PlaneBehavior)

public:
   PlaneBarrelRoll();
   base::ubf::AbstractAction* genAction(const base::ubf::AbstractState* const state, const double dt) final;
};

class PlaneLoop final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneLoop, PlaneBehavior)

public:
   PlaneLoop();
   base::ubf::AbstractAction* genAction(const base::ubf::AbstractState* const state, const double dt) final;

private:
   bool keepGoing{};
};

}
}

#endif
