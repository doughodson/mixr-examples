
#ifndef __DataRecordTest_H__
#define __DataRecordTest_H__

#include "mixr/recorder/OutputHandler.hpp"

#include "mixr/recorder/PrintSelected.hpp"
#include <string>
#include <array>

namespace mixr {
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
class DataRecordTest final: public mixr::recorder::OutputHandler
{
   DECLARE_SUBCLASS(DataRecordTest, mixr::recorder::OutputHandler)

public:
   DataRecordTest();

   // Select one of these in main.cpp
   bool testEvents();      // switch to test each possible event message
   bool testSerialize();   // Test to serialize and parse a set of messages

protected:
   void eventTestMenu();
   void readSerialFromFile();

   // all messages:
   mixr::recorder::DataRecordHandle* testFileIdMsg(int run);
   mixr::recorder::DataRecordHandle* testNewPlayerEventMsg();
   mixr::recorder::DataRecordHandle* testPlayerRemovedEventMsg();
   mixr::recorder::DataRecordHandle* testPlayerDataMsg();
   mixr::recorder::DataRecordHandle* testPlayerDamagedEventMsg();
   mixr::recorder::DataRecordHandle* testPlayerCollisionEventMsg();
   mixr::recorder::DataRecordHandle* testPlayerCrashEventMsg();
   mixr::recorder::DataRecordHandle* testPlayerKilledEventMsg(unsigned int type);
   mixr::recorder::DataRecordHandle* testWeaponReleaseEventMsg(unsigned int side);
   mixr::recorder::DataRecordHandle* testWeaponHungEventMsg();
   mixr::recorder::DataRecordHandle* testWeaponDetonationEventMsg();
   mixr::recorder::DataRecordHandle* testGunFiredEventMsg();
   mixr::recorder::DataRecordHandle* testNewTrackEventMsg();
   mixr::recorder::DataRecordHandle* testTrackRemovedEventMsg();
   mixr::recorder::DataRecordHandle* testTrackDataMsg();

   mixr::recorder::DataRecordHandle* testLastMsg();

   // Recursive function to look at each embedded message
   bool processMessage(const google::protobuf::Message* const msg);

   // Set comparison criteria:
   bool setMsgToken(const unsigned int token);
   bool setFieldOfInterest(const std::string fieldName );
   bool setCompareToValue(const std::string strVal);
   bool setCompareToValue(const int numVal );
   bool setCompareToValue(const double dblVal );
   bool setCompareCondition(const mixr::recorder::PrintSelected::Condition cc);
   bool setTimeOnly(const bool flg );

   double getSimTime();
   double getExecTime();
   double getUtcTime();

private:
   std::string fileName;
   mixr::base::safe_ptr<mixr::recorder::PrintPlayer> myPrintPlayer;
   mixr::base::safe_ptr<mixr::recorder::PrintSelected> myPrintSelected;
   mixr::base::safe_ptr<mixr::recorder::PrintSelected> myPrintSelected2;
   mixr::base::safe_ptr<mixr::recorder::TabPrinter> myRecPrint;
   mixr::base::safe_ptr<mixr::recorder::FileWriter> myFileWrite;
   mixr::base::safe_ptr<mixr::recorder::FileReader> myFileRead;
   mixr::base::safe_ptr<mixr::recorder::DataRecorder> myDataRec;

   std::string fieldName;
   mixr::recorder::PrintSelected::Condition condition;
   int compareI{};
   std::string compareS;
   double compareD{};
   std::string fullFieldName;
   bool fieldSelected{};
   unsigned int timesCalled{};

   // Struct and array for saving multiple sets of selection criteria
   unsigned int selectionNum{};
   struct SelectionCriteria {
      unsigned int msgToken{};
      std::string fieldName = "";
      double compareValD{};
      std::string compareValS = "";
      int compareValI{};
      mixr::recorder::PrintSelected::Condition condition{mixr::recorder::PrintSelected::Condition::EQ};
      bool timeOnly{};
   };
   std::array<SelectionCriteria, 20> selection;

private:
   // slot table helper methods
   bool setSlotFileName(mixr::base::String* const);
   bool setSlotTabPrinter(mixr::recorder::TabPrinter*);
   bool setSlotFileWriter(mixr::recorder::FileWriter*);
   bool setSlotFileReader(mixr::recorder::FileReader*);
   bool setSlotRecordData(mixr::recorder::DataRecorder* const);
   bool setSlotPrintPlayer(mixr::recorder::PrintPlayer*);
   bool setSlotPrintSelected(mixr::recorder::PrintSelected*);
   bool setSlotPrintSelected2(mixr::recorder::PrintSelected*);
};

#endif
