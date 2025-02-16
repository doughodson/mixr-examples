
#ifndef __TestStateMachine04B_HPP__
#define __TestStateMachine04B_HPP__

#include "mixr/base/IStateMachine.hpp"

//------------------------------------------------------------------------------
// Class: TestStateMachine04B
//
//------------------------------------------------------------------------------
class TestStateMachine04B final: public mixr::base::IStateMachine
{
   DECLARE_SUBCLASS(TestStateMachine04B, mixr::base::IStateMachine)

public:
   TestStateMachine04B();

protected:
   void preStateProc(const double dt) final;
   unsigned short stateTable(
         const unsigned short cstate,
         const StateTableCode code,
         const double dt=0
      ) final;

private:
   // State specific functions
   void stateFunc00(const double dt);
   void stateFunc01(const double dt);
   void stateFunc02(const double dt);
};

#endif
