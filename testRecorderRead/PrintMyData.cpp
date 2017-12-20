
#include "PrintMyData.hpp"

#include "xrecorder/protobuf/DataRecord.pb.h"
#include "xrecorder/dataRecorderTokens.hpp"
#include "mixr/recorder/DataRecordHandle.hpp"

using namespace mixr;

IMPLEMENT_SUBCLASS(PrintMyData, "PrintMyData")
EMPTY_SLOTTABLE(PrintMyData)
EMPTY_CONSTRUCTOR(PrintMyData)
EMPTY_COPYDATA(PrintMyData)
EMPTY_DELETEDATA(PrintMyData)

// print the data
void PrintMyData::processRecordImp(const mixr::recorder::DataRecordHandle* const handle)
{
   if (handle == nullptr) return;  // cannot continue
   const mixr::recorder::pb::DataRecord* dataRecord{handle->getRecord()};
   if (dataRecord == nullptr) return;  // cannot continue

   // Get the time msg
   const mixr::recorder::pb::Time* timeMsg{};
   if (dataRecord->has_time()) {
      timeMsg = &dataRecord->time();
   }

   // Get message id
   unsigned int messageId{dataRecord->id()};
   switch (messageId) {

      // Extended Marker event
      case REID_MARKER : {
         if (dataRecord->has_marker_msg()) {
            std::stringstream sout;

            sout << "MARKER " << "    ";
            if (timeMsg != nullptr) {
               if (timeMsg->has_exec_time()) {
                  sout << timeMsg->exec_time() << ";  ";
               }
            }

            const mixr::recorder::pb::MarkerMsg* msg{&dataRecord->marker_msg()};

            if (msg->has_id()) sout << "id= " << msg->id() << ";  ";
            if (msg->has_source_id()) sout << "source_id= " << msg->source_id() << ";  ";

            if (msg->HasExtension( mixr::xrecorder::pb::foo )) sout << "foo= " << msg->GetExtension( mixr::xrecorder::pb::foo ) << ";  ";

            printToOutput( sout.str().c_str() );
         }
         break;
      }

      // MyData message event
      case REID_MY_DATA_EVENT : {
         if (dataRecord->HasExtension( mixr::xrecorder::pb::my_data_msg )) {
            std::stringstream sout;

            sout << "MY_DATA " << "   ";
            if (timeMsg != nullptr) {
               if (timeMsg->has_exec_time()) {
                  sout << timeMsg->exec_time() << ";  ";
               }
            }

            const mixr::xrecorder::pb::MyDataMsg* msg = &dataRecord->GetExtension( mixr::xrecorder::pb::my_data_msg );

            if (msg->has_fee()) sout << "fee= " << msg->fee() << ";  ";
            if (msg->has_fi()) sout << "fi= " << msg->fi() << ";  ";
            if (msg->has_fo()) sout << "fo= " << msg->fo() << ";  ";

            printToOutput( sout.str().c_str() );
         }
         break;
      }

   }

}
