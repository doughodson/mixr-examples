
#ifndef __TestStateMachine04C_H__
#define __TestStateMachine04C_H__

#include "mixr/base/StateMachine.hpp"

//------------------------------------------------------------------------------
// Class: TestStateMachine04C
//
//------------------------------------------------------------------------------
class TestStateMachine04C : public mixr::base::StateMachine
{
   DECLARE_SUBCLASS(TestStateMachine04C, mixr::base::StateMachine)

public:
   TestStateMachine04C();

protected:
   virtual void preStateProc(const double dt) override;
   virtual unsigned short stateTable(
         const unsigned short cstate,
         const StateTableCode code,
         const double dt=0
      ) override;

private:
   // State specific functions
   void stateFunc00(const double dt);
};

#endif
