
#include "PrintMyData.hpp"

#include "xrecorder/protobuf/DataRecord.pb.h"
#include "xrecorder/dataRecorderTokens.hpp"
#include "mxrp/recorder/DataRecordHandle.hpp"

using namespace mxrp;

IMPLEMENT_SUBCLASS(PrintMyData, "PrintMyData")
EMPTY_SLOTTABLE(PrintMyData)
EMPTY_SERIALIZER(PrintMyData)
EMPTY_CONSTRUCTOR(PrintMyData)
EMPTY_COPYDATA(PrintMyData)
EMPTY_DELETEDATA(PrintMyData)

// print the data
void PrintMyData::processRecordImp(const mxrp::recorder::DataRecordHandle* const handle)
{
   if (handle == nullptr) return;  // cannot continue
   const mxrp::recorder::pb::DataRecord* dataRecord = handle->getRecord();
   if (dataRecord == nullptr) return;  // cannot continue

   // Get the time msg
   const mxrp::recorder::pb::Time* timeMsg = nullptr;
   if (dataRecord->has_time()) {
      timeMsg = &dataRecord->time();
   }

   // Get message id
   unsigned int messageId = dataRecord->id();
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

            const mxrp::recorder::pb::MarkerMsg* msg = &dataRecord->marker_msg();

            if (msg->has_id()) sout << "id= " << msg->id() << ";  ";
            if (msg->has_source_id()) sout << "source_id= " << msg->source_id() << ";  ";

            if (msg->HasExtension( mxrp::xrecorder::pb::foo )) sout << "foo= " << msg->GetExtension( mxrp::xrecorder::pb::foo ) << ";  ";

            printToOutput( sout.str().c_str() );
         }
         break;
      }

      // MyData message event
      case REID_MY_DATA_EVENT : {
         if (dataRecord->HasExtension( mxrp::xrecorder::pb::my_data_msg )) {
            std::stringstream sout;

            sout << "MY_DATA " << "   ";
            if (timeMsg != nullptr) {
               if (timeMsg->has_exec_time()) {
                  sout << timeMsg->exec_time() << ";  ";
               }
            }

            const mxrp::xrecorder::pb::MyDataMsg* msg = &dataRecord->GetExtension( mxrp::xrecorder::pb::my_data_msg );

            if (msg->has_fee()) sout << "fee= " << msg->fee() << ";  ";
            if (msg->has_fi()) sout << "fi= " << msg->fi() << ";  ";
            if (msg->has_fo()) sout << "fo= " << msg->fo() << ";  ";

            printToOutput( sout.str().c_str() );
         }
         break;
      }

   }

}
