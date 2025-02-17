
#ifndef __DataRecordTest_HPP__
#define __DataRecordTest_HPP__

#include "mixr/base/IComponent.hpp"

namespace mixr {
namespace recorder { class IInputHandler; class OutputHandler; }
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
   mixr::base::safe_ptr<mixr::recorder::IInputHandler> inputHandler;
   mixr::base::safe_ptr<mixr::recorder::OutputHandler> outputHandler;

private:
   // slot table helper methods
   bool setSlotInputHandler(mixr::recorder::IInputHandler* const);
   bool setSlotOutputHandler(mixr::recorder::OutputHandler* const);
};

#endif
