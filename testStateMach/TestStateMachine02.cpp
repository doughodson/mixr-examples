
#include "TestStateMachine02.h"

#include "openeaagles/basic/Integer.h"
#include "openeaagles/basic/Boolean.h"

namespace oe {
namespace test {

IMPLEMENT_SUBCLASS(TestStateMachine02,"TestStateMachine02")
EMPTY_SLOTTABLE(TestStateMachine02)
EMPTY_CONSTRUCTOR(TestStateMachine02)
EMPTY_COPYDATA(TestStateMachine02)
EMPTY_DELETEDATA(TestStateMachine02)
EMPTY_SERIALIZER(TestStateMachine02)

// State dispatch table
BEGIN_STATE_TABLE(TestStateMachine02)
   STATE_FUNC( INIT_STATE, stateFunc00)
   STATE_FUNC( 1, stateFunc01)
   STATE_FUNC( 2, stateFunc02)
   STATE_FUNC( 3, stateFunc03)
   STATE_FUNC( 4, stateFunc04)
   STATE_FUNC( 5, stateFunc05)
   STATE_FUNC(11, stateFunc11)
   STATE_FUNC(12, stateFunc12)
   STATE_FUNC(13, stateFunc13)
   STATE_FUNC(14, stateFunc14)
   STATE_FUNC(15, stateFunc15)
   STATE_FUNC(21, stateFunc21)
   STATE_FUNC(22, stateFunc22)
   STATE_FUNC(23, stateFunc23)
   STATE_FUNC(99, stateFunc99)
END_STATE_TABLE()

//------------------------------------------------------------------------------
// Pre/Post functions
//------------------------------------------------------------------------------

void TestStateMachine02::preStateProc(const LCreal)
{
   // Start line
   std::cout << "Test #2 State(" << getState() << "): ";
}

void TestStateMachine02::postStateProc(const LCreal)
{
   // End the line
   std::cout << std::endl;
}

//------------------------------------------------------------------------------
// State functions
//------------------------------------------------------------------------------
void TestStateMachine02::stateFunc00(const LCreal)
{
   std::cout << "next()";
   next();
}

void TestStateMachine02::stateFunc01(const LCreal)
{
   std::cout << "next()";
   next();
}

void TestStateMachine02::stateFunc02(const LCreal)
{
   std::cout << "goTo(4)";
   goTo(4);
}

void TestStateMachine02::stateFunc03(const LCreal)
{
   std::cout << "Should NOT be here!";
}

void TestStateMachine02::stateFunc04(const LCreal)
{
   if (getMode() != RTN_STATE) {
      std::cout << "call(CALL_01)";
      call(CALL_01);
   }
   else {
      std::cout << "Returned from call(); next()";
      next();
   }
}

void TestStateMachine02::stateFunc05(const LCreal)
{
   std::cout << "goTo(99)";
   goTo(99);
}

void TestStateMachine02::stateFunc11(const LCreal)
{
   std::cout << "next()";
   next();
}

void TestStateMachine02::stateFunc12(const LCreal)
{
   std::cout << "next()";
   next();
}

void TestStateMachine02::stateFunc13(const LCreal)
{
   if (getMode() != RTN_STATE) {
      std::cout << "call(CALL_02,arg=13)";
      basic::Number* arg = new basic::Integer(13);
      call(CALL_02, arg);
      arg->unref();
   }
   else {
      std::cout << "Returned from call; ";
      const basic::Boolean* arg = dynamic_cast<const basic::Boolean*>( getArgument() );
      if (arg != nullptr) {
         std::cout << "arg(" << arg->getBoolean() << "); ";
      }
      std::cout << "next()";
      next();
   }
}

void TestStateMachine02::stateFunc14(const LCreal)
{
   std::cout << "next()";
   next();
}

void TestStateMachine02::stateFunc15(const LCreal)
{
   std::cout << "rtn()";
   rtn();
}

void TestStateMachine02::stateFunc21(const LCreal)
{
   const basic::Number* arg = dynamic_cast<const basic::Number*>( getArgument() );
   if (arg != nullptr) {
      std::cout << "arg(" << arg->getReal() << "); ";
   }

   std::cout << "next()";
   next();
}

void TestStateMachine02::stateFunc22(const LCreal)
{
   std::cout << "next()";
   next();
}

void TestStateMachine02::stateFunc23(const LCreal)
{
   std::cout << "rtn(arg=1)";
   basic::Boolean* arg = new basic::Boolean(1);
   rtn(arg);
   arg->unref();
}

void TestStateMachine02::stateFunc99(const LCreal)
{
   if (getMode() == NEW_STATE) {
      std::cout << "Finished;";
   }
}

} // End test namespace
} // End oe namespace
