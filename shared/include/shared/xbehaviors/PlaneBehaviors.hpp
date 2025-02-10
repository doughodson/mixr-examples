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
#ifndef __mixr_xbehaviors_PlaneBehaviors_HPP__
#define __mixr_xbehaviors_PlaneBehaviors_HPP__

#include "mixr/base/ubf/IBehavior.hpp"

namespace mixr {
namespace base { class Integer; class Length; class State; }
namespace base {
namespace ubf { class IState; class IAction; }
}
namespace xbehaviors {

//------------------------------------------------------------------------------
// Class: PlaneBehavior
// Description: Base class for concrete plane behaviors
//------------------------------------------------------------------------------
class PlaneBehavior : public base::ubf::IBehavior
{
  DECLARE_SUBCLASS(PlaneBehavior, base::ubf::IBehavior)

public:
   PlaneBehavior();

protected:
   int voteOnIncomingMissile{};
   int voteOnCriticalAltitude{};
   double criticalAltitude{3500.0};

private:
   // slot table helper methods
   bool setSlotCriticalAltitude(const base::Length* const);
   bool setSlotVoteOnCriticalAltitude(const base::Integer* const);
   bool setSlotVoteOnIncomingMissile(const base::Integer* const);
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
   base::ubf::IAction* genAction(const base::ubf::IState* const state, const double dt) final;

private:
   double maxDistance{15500.0};

private:
   // slot table helper methods
   bool setSlotMaxDistance(const base::Length* const);
};

class PlaneFlyStraight final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneFlyStraight, PlaneBehavior)

public:
   PlaneFlyStraight();
   base::ubf::IAction* genAction(const base::ubf::IState* const state, const double dt) final;

private:
   double holdingAltitude{4500.0};
};

class PlaneFollowEnemy final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneFollowEnemy, PlaneBehavior)

public:
   PlaneFollowEnemy();
   base::ubf::IAction* genAction(const base::ubf::IState* const state, const double dt) final;
};

class PlaneTurn final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneTurn, PlaneBehavior)

public:
   PlaneTurn();
   base::ubf::IAction* genAction(const base::ubf::IState* const state, const double dt) final;
};

class PlaneSlowTurn final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneSlowTurn, PlaneBehavior)

public:
   PlaneSlowTurn();
   base::ubf::IAction* genAction(const base::ubf::IState* const state, const double dt) final;
};

class PlaneClimb final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneClimb, PlaneBehavior)

public:
   PlaneClimb();
   base::ubf::IAction* genAction(const base::ubf::IState* const state, const double dt) final;
};

class PlaneDive final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneDive, PlaneBehavior)

public:
   PlaneDive();
   base::ubf::IAction* genAction(const base::ubf::IState* const state, const double dt) final;
};

class PlaneTrim final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneTrim, PlaneBehavior)

public:
   PlaneTrim();
   base::ubf::IAction* genAction(const base::ubf::IState* const state, const double dt) final;

private:
   double holdingAltitude{4500.0};
   int count{};
};

class PlaneRoll final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneRoll, PlaneBehavior)

public:
   PlaneRoll();
   base::ubf::IAction* genAction(const base::ubf::IState* const state, const double dt) final;
};

class PlaneBarrelRoll final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneBarrelRoll, PlaneBehavior)

public:
   PlaneBarrelRoll();
   base::ubf::IAction* genAction(const base::ubf::IState* const state, const double dt) final;
};

class PlaneLoop final: public PlaneBehavior
{
   DECLARE_SUBCLASS(PlaneLoop, PlaneBehavior)

public:
   PlaneLoop();
   base::ubf::IAction* genAction(const base::ubf::IState* const state, const double dt) final;

private:
   bool keepGoing{};
};

}
}

#endif
