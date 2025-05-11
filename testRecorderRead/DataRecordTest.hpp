
#ifndef __DataRecordTest_HPP__
#define __DataRecordTest_HPP__

#include "mixr/base/IComponent.hpp"

namespace mixr {
namespace recorder {
namespace protobuf_v2 {
   class IInputHandler; class OutputHandler; }
}
}

//------------------------------------------------------------------------------
// Class: DataRecordTest
//------------------------------------------------------------------------------
class DataRecordTest final: public mixr::base::IComponent
{
   DECLARE_SUBCLASS(DataRecordTest, mixr::base::IComponent)

public:
   DataRecordTest();

   // main test
   void runTest();

private:
   mixr::base::safe_ptr<mixr::recorder::protobuf_v2::IInputHandler> inputHandler;
   mixr::base::safe_ptr<mixr::recorder::protobuf_v2::OutputHandler> outputHandler;

private:
   // slot table helper methods
   bool setSlotInputHandler(mixr::recorder::protobuf_v2::IInputHandler* const);
   bool setSlotOutputHandler(mixr::recorder::protobuf_v2::OutputHandler* const);
};

#endif
