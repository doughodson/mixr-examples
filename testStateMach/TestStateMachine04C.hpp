
#ifndef __TestStateMachine04C_H__
#define __TestStateMachine04C_H__

#include "mxrp/base/StateMachine.hpp"

//------------------------------------------------------------------------------
// Class: TestStateMachine04C
//
//------------------------------------------------------------------------------
class TestStateMachine04C : public mxrp::base::StateMachine
{
   DECLARE_SUBCLASS(TestStateMachine04C, mxrp::base::StateMachine)

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
