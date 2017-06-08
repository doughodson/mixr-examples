
#ifndef __DataRecordTest_H__
#define __DataRecordTest_H__

#include "mxrp/base/Component.hpp"

namespace mxrp {
namespace recorder { class InputHandler; class OutputHandler; }
}

//------------------------------------------------------------------------------
// Class: DataRecordTest
//------------------------------------------------------------------------------
class DataRecordTest : public mxrp::base::Component
{
   DECLARE_SUBCLASS(DataRecordTest, mxrp::base::Component)

public:
   DataRecordTest();

   // Main test
   void runTest();

protected:
   // Slot functions
   virtual bool setSlotInputHandler(mxrp::recorder::InputHandler* const msg);
   virtual bool setSlotOutputHandler(mxrp::recorder::OutputHandler* const msg);

private:
   void initData();

   mxrp::base::safe_ptr<mxrp::recorder::InputHandler> inputHandler;
   mxrp::base::safe_ptr<mxrp::recorder::OutputHandler> outputHandler;
};

#endif
