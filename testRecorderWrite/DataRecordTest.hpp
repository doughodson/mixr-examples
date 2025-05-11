
#ifndef __DataRecordTest_HPP__
#define __DataRecordTest_HPP__

#include "mixr/recorder/protobuf_v2/OutputHandler.hpp"

#include "mixr/recorder/protobuf_v2/PrintSelected.hpp"
#include <string>
#include <array>

namespace mixr {
namespace base { class String; }
namespace recorder {
namespace protobuf_v2 {
class TabPrinter;
class FileWriter;
class FileReader;
class DataRecorder;
class PrintPlayer;
class DataRecordHandle;
}
}
}

//------------------------------------------------------------------------------
// Class: DataRecordTest
//------------------------------------------------------------------------------
class DataRecordTest final: public mixr::recorder::protobuf_v2::OutputHandler
{
   DECLARE_SUBCLASS(DataRecordTest, mixr::recorder::protobuf_v2::OutputHandler)

public:
   DataRecordTest();

   // Select one of these in main.cpp
   bool testEvents();      // switch to test each possible event message
   bool testSerialize();   // Test to serialize and parse a set of messages

protected:
   void eventTestMenu();
   void readSerialFromFile();

   // all messages:
   mixr::recorder::protobuf_v2::DataRecordHandle* testFileIdMsg(int run);
   mixr::recorder::protobuf_v2::DataRecordHandle* testNewPlayerEventMsg();
   mixr::recorder::protobuf_v2::DataRecordHandle* testPlayerRemovedEventMsg();
   mixr::recorder::protobuf_v2::DataRecordHandle* testPlayerDataMsg();
   mixr::recorder::protobuf_v2::DataRecordHandle* testPlayerDamagedEventMsg();
   mixr::recorder::protobuf_v2::DataRecordHandle* testPlayerCollisionEventMsg();
   mixr::recorder::protobuf_v2::DataRecordHandle* testPlayerCrashEventMsg();
   mixr::recorder::protobuf_v2::DataRecordHandle* testPlayerKilledEventMsg(unsigned int type);
   mixr::recorder::protobuf_v2::DataRecordHandle* testWeaponReleaseEventMsg(unsigned int side);
   mixr::recorder::protobuf_v2::DataRecordHandle* testWeaponHungEventMsg();
   mixr::recorder::protobuf_v2::DataRecordHandle* testWeaponDetonationEventMsg();
   mixr::recorder::protobuf_v2::DataRecordHandle* testGunFiredEventMsg();
   mixr::recorder::protobuf_v2::DataRecordHandle* testNewTrackEventMsg();
   mixr::recorder::protobuf_v2::DataRecordHandle* testTrackRemovedEventMsg();
   mixr::recorder::protobuf_v2::DataRecordHandle* testTrackDataMsg();

   mixr::recorder::protobuf_v2::DataRecordHandle* testLastMsg();

   // Recursive function to look at each embedded message
   bool processMessage(const google::protobuf::Message* const msg);

   // Set comparison criteria:
   bool setMsgToken(const unsigned int token);
   bool setFieldOfInterest(const std::string fieldName );
   bool setCompareToValue(const std::string strVal);
   bool setCompareToValue(const int numVal );
   bool setCompareToValue(const double dblVal );
   bool setCompareCondition(const mixr::recorder::protobuf_v2::PrintSelected::Condition cc);
   bool setTimeOnly(const bool flg );

   double getSimTime();
   double getExecTime();
   double getUtcTime();

private:
   std::string fileName;
   mixr::base::safe_ptr<mixr::recorder::protobuf_v2::PrintPlayer> myPrintPlayer;
   mixr::base::safe_ptr<mixr::recorder::protobuf_v2::PrintSelected> myPrintSelected;
   mixr::base::safe_ptr<mixr::recorder::protobuf_v2::PrintSelected> myPrintSelected2;
   mixr::base::safe_ptr<mixr::recorder::protobuf_v2::TabPrinter> myRecPrint;
   mixr::base::safe_ptr<mixr::recorder::protobuf_v2::FileWriter> myFileWrite;
   mixr::base::safe_ptr<mixr::recorder::protobuf_v2::FileReader> myFileRead;
   mixr::base::safe_ptr<mixr::recorder::protobuf_v2::DataRecorder> myDataRec;

   std::string fieldName;
   mixr::recorder::protobuf_v2::PrintSelected::Condition condition;
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
      std::string fieldName;
      double compareValD{};
      std::string compareValS;
      int compareValI{};
      mixr::recorder::protobuf_v2::PrintSelected::Condition condition{mixr::recorder::protobuf_v2::PrintSelected::Condition::EQ};
      bool timeOnly{};
   };
   std::array<SelectionCriteria, 20> selection;

private:
   // slot table helper methods
   bool setSlotFileName(mixr::base::String* const);
   bool setSlotTabPrinter(mixr::recorder::protobuf_v2::TabPrinter*);
   bool setSlotFileWriter(mixr::recorder::protobuf_v2::FileWriter*);
   bool setSlotFileReader(mixr::recorder::protobuf_v2::FileReader*);
   bool setSlotRecordData(mixr::recorder::protobuf_v2::DataRecorder* const);
   bool setSlotPrintPlayer(mixr::recorder::protobuf_v2::PrintPlayer*);
   bool setSlotPrintSelected(mixr::recorder::protobuf_v2::PrintSelected*);
   bool setSlotPrintSelected2(mixr::recorder::protobuf_v2::PrintSelected*);
};

#endif
