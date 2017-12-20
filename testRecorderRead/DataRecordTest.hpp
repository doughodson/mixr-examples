
#ifndef __DataRecordTest_H__
#define __DataRecordTest_H__

#include "mixr/base/Component.hpp"

namespace mixr {
namespace recorder { class InputHandler; class OutputHandler; }
}

//------------------------------------------------------------------------------
// Class: DataRecordTest
//------------------------------------------------------------------------------
class DataRecordTest final: public mixr::base::Component
{
   DECLARE_SUBCLASS(DataRecordTest, mixr::base::Component)

public:
   DataRecordTest();

   // main test
   void runTest();

private:
   mixr::base::safe_ptr<mixr::recorder::InputHandler> inputHandler;
   mixr::base::safe_ptr<mixr::recorder::OutputHandler> outputHandler;

private:
   // slot table helper methods
   bool setSlotInputHandler(mixr::recorder::InputHandler* const);
   bool setSlotOutputHandler(mixr::recorder::OutputHandler* const);
};

#endif
