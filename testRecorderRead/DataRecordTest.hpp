
#ifndef __DataRecordTest_H__
#define __DataRecordTest_H__

#include "mixr/base/Component.hpp"

namespace mixr {
namespace recorder { class InputHandler; class OutputHandler; }
}

//------------------------------------------------------------------------------
// Class: DataRecordTest
//------------------------------------------------------------------------------
class DataRecordTest : public mixr::base::Component
{
   DECLARE_SUBCLASS(DataRecordTest, mixr::base::Component)

public:
   DataRecordTest();

   // Main test
   void runTest();

protected:
   // Slot functions
   virtual bool setSlotInputHandler(mixr::recorder::InputHandler* const msg);
   virtual bool setSlotOutputHandler(mixr::recorder::OutputHandler* const msg);

private:
   void initData();

   mixr::base::safe_ptr<mixr::recorder::InputHandler> inputHandler;
   mixr::base::safe_ptr<mixr::recorder::OutputHandler> outputHandler;
};

#endif
