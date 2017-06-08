
#ifndef __DataRecordTest_H__
#define __DataRecordTest_H__

#include "mxrp/recorder/OutputHandler.hpp"

#include "mxrp/recorder/PrintSelected.hpp"
#include <string>
#include <array>

namespace mxrp {
namespace base { class String; }
namespace recorder {
class TabPrinter;
class FileWriter;
class FileReader;
class DataRecorder;
class PrintPlayer;
class DataRecordHandle;
}
}

//------------------------------------------------------------------------------
// Class: DataRecordTest
//------------------------------------------------------------------------------
class DataRecordTest : public mxrp::recorder::OutputHandler
{
   DECLARE_SUBCLASS(DataRecordTest, mxrp::recorder::OutputHandler)

public:
   DataRecordTest();

   // Slot functions
   virtual bool setSlotFileName(mxrp::base::String* const msg);
   virtual bool setSlotTabPrinter(mxrp::recorder::TabPrinter* msg);
   virtual bool setSlotFileWriter(mxrp::recorder::FileWriter* msg);
   virtual bool setSlotFileReader(mxrp::recorder::FileReader* msg);
   virtual bool setSlotRecordData(mxrp::recorder::DataRecorder* const msg);
   virtual bool setSlotPrintPlayer(mxrp::recorder::PrintPlayer* msg);
   virtual bool setSlotPrintSelected(mxrp::recorder::PrintSelected* msg);
   virtual bool setSlotPrintSelected2(mxrp::recorder::PrintSelected* msg);

   // Select one of these in main.cpp
   bool testEvents();      // switch to test each possible event message
   bool testSerialize();   // Test to serialize and parse a set of messages

protected:
   void eventTestMenu();
   void readSerialFromFile();

   // all messages:
   mxrp::recorder::DataRecordHandle* testFileIdMsg(int run);
   mxrp::recorder::DataRecordHandle* testNewPlayerEventMsg();
   mxrp::recorder::DataRecordHandle* testPlayerRemovedEventMsg();
   mxrp::recorder::DataRecordHandle* testPlayerDataMsg();
   mxrp::recorder::DataRecordHandle* testPlayerDamagedEventMsg();
   mxrp::recorder::DataRecordHandle* testPlayerCollisionEventMsg();
   mxrp::recorder::DataRecordHandle* testPlayerCrashEventMsg();
   mxrp::recorder::DataRecordHandle* testPlayerKilledEventMsg(unsigned int type);
   mxrp::recorder::DataRecordHandle* testWeaponReleaseEventMsg(unsigned int side);
   mxrp::recorder::DataRecordHandle* testWeaponHungEventMsg();
   mxrp::recorder::DataRecordHandle* testWeaponDetonationEventMsg();
   mxrp::recorder::DataRecordHandle* testGunFiredEventMsg();
   mxrp::recorder::DataRecordHandle* testNewTrackEventMsg();
   mxrp::recorder::DataRecordHandle* testTrackRemovedEventMsg();
   mxrp::recorder::DataRecordHandle* testTrackDataMsg();

   mxrp::recorder::DataRecordHandle* testLastMsg();

   // Recursive function to look at each embedded message
   bool processMessage(const google::protobuf::Message* const msg);

   // Set comparison criteria:
   bool setMsgToken(const unsigned int token);
   bool setFieldOfInterest(const std::string fieldName );
   bool setCompareToValue(const std::string strVal);
   bool setCompareToValue(const int numVal );
   bool setCompareToValue(const double dblVal );
   bool setCompareCondition(const mxrp::recorder::PrintSelected::Condition cc);
   bool setTimeOnly(const bool flg );

   double getSimTime();
   double getExecTime();
   double getUtcTime();

private:
   std::string fileName;
   mxrp::base::safe_ptr<mxrp::recorder::PrintPlayer> myPrintPlayer;
   mxrp::base::safe_ptr<mxrp::recorder::PrintSelected> myPrintSelected;
   mxrp::base::safe_ptr<mxrp::recorder::PrintSelected> myPrintSelected2;
   mxrp::base::safe_ptr<mxrp::recorder::TabPrinter> myRecPrint;
   mxrp::base::safe_ptr<mxrp::recorder::FileWriter> myFileWrite;
   mxrp::base::safe_ptr<mxrp::recorder::FileReader> myFileRead;
   mxrp::base::safe_ptr<mxrp::recorder::DataRecorder> myDataRec;

   std::string fieldName;
   mxrp::recorder::PrintSelected::Condition condition;
   int compareI {};
   std::string compareS;
   double compareD {};
   std::string fullFieldName;
   bool fieldSelected {};
   unsigned int timesCalled {};

   // Struct and array for saving multiple sets of selection criteria
   unsigned int selectionNum {};
   struct SelectionCriteria {
      unsigned int msgToken {};
      std::string fieldName = "";
      double compareValD {};
      std::string compareValS = "";
      int compareValI {};
      mxrp::recorder::PrintSelected::Condition condition {mxrp::recorder::PrintSelected::Condition::EQ};
      bool timeOnly {};
   };
   std::array<SelectionCriteria, 20> selection;
};

#endif
