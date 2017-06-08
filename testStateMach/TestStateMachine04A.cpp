
#include "TestStateMachine04A.hpp"

#include "mxrp/base/Integer.hpp"
#include "mxrp/base/Boolean.hpp"

using namespace mxrp;

IMPLEMENT_SUBCLASS(TestStateMachine04A, "TestStateMachine04A")
EMPTY_SLOTTABLE(TestStateMachine04A)
EMPTY_CONSTRUCTOR(TestStateMachine04A)
EMPTY_COPYDATA(TestStateMachine04A)
EMPTY_DELETEDATA(TestStateMachine04A)
EMPTY_SERIALIZER(TestStateMachine04A)

// State dispatch table
BEGIN_STATE_TABLE(TestStateMachine04A)
   STATE_FUNC( INIT_STATE, stateFunc00)
   STATE_FUNC( 1, stateFunc01)
   STATE_FUNC( 2, stateFunc02)
   STATE_FUNC( 3, stateFunc03)
   STATE_FUNC( 4, stateFunc04)
END_STATE_TABLE()

//------------------------------------------------------------------------------
// Pre/Post functions
//------------------------------------------------------------------------------

void TestStateMachine04A::preStateProc(const double)
{
   std::cout << "SM(#4A)(" << getState() << "," << getSubstate() << "): ";
}

//------------------------------------------------------------------------------
// State functions
//------------------------------------------------------------------------------
void TestStateMachine04A::stateFunc00(const double)
{
   std::cout << "next()";
   next();
}

void TestStateMachine04A::stateFunc01(const double)
{
   std::cout << "goTo(3)";
   goTo(3);
}

void TestStateMachine04A::stateFunc02(const double)
{
   std::cout << "Should NOT be here!";
}

void TestStateMachine04A::stateFunc03(const double)
{
   std::cout << "next()";
   next();
}

void TestStateMachine04A::stateFunc04(const double)
{
   std::cout << "nextState()";
   nextState();
}
