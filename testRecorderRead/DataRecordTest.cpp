
#include "DataRecordTest.hpp"

#include "mixr/recorder/InputHandler.hpp"
#include "mixr/recorder/OutputHandler.hpp"
#include "mixr/recorder/DataRecordHandle.hpp"

#include "xrecorder/protobuf/DataRecord.pb.h"
#include <iostream>

using namespace mixr;

IMPLEMENT_SUBCLASS(DataRecordTest, "DataRecordTest")

BEGIN_SLOTTABLE(DataRecordTest)
   "inputHandler",
   "outputHandler",
END_SLOTTABLE(DataRecordTest)

BEGIN_SLOT_MAP(DataRecordTest)
   ON_SLOT(1, setSlotInputHandler, mixr::recorder::InputHandler)
   ON_SLOT(2, setSlotOutputHandler, mixr::recorder::OutputHandler)
END_SLOT_MAP()

DataRecordTest::DataRecordTest()
{
   STANDARD_CONSTRUCTOR()
}

void DataRecordTest::copyData(const DataRecordTest& org, const bool)
{
   BaseClass::copyData(org);

   {  // Clone input handler
      mixr::recorder::InputHandler* clone{};
      if (org.inputHandler != nullptr) clone = org.inputHandler->clone();
      setSlotInputHandler(clone);
      if (clone != nullptr) clone->unref();
   }

   {  // Clone output handler
      mixr::recorder::OutputHandler* clone{};
      if (org.outputHandler != nullptr) clone = org.outputHandler->clone();
      setSlotOutputHandler(clone);
      if (clone != nullptr) clone->unref();
   }
}

void DataRecordTest::deleteData()
{
   setSlotInputHandler(nullptr);
   setSlotOutputHandler(nullptr);
}

// Main test
void DataRecordTest::runTest()
{
   if (inputHandler == nullptr) {
      std::cerr << "runTest() -- missing input handler!" << std::endl;
      return;
   }

   if (outputHandler == nullptr) {
      std::cerr << "runTest() -- missing output handler!" << std::endl;
      return;
   }

   bool finished{};
   while (!finished) {
      const mixr::recorder::DataRecordHandle* p{inputHandler->readRecord()};
      if (p != nullptr) {
         outputHandler->processRecord(p);
      }
      finished = (p == nullptr) || (p->getRecord()->id() == REID_END_OF_DATA);
   }
}

bool DataRecordTest::setSlotInputHandler(mixr::recorder::InputHandler* const msg)
{
   inputHandler = msg;
   if (inputHandler != nullptr) inputHandler->container(this);
   return true;
}

bool DataRecordTest::setSlotOutputHandler(mixr::recorder::OutputHandler* const msg)
{
   outputHandler = msg;
   if (outputHandler != nullptr) outputHandler->container(this);
   return true;
}

