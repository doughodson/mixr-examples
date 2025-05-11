
#include "XDataRecorder.hpp"

#include "proto/DataRecord.pb.h"
#include "dataRecorderTokens.hpp"

#include "mixr/base/util/math_utils.hpp"

namespace mixr {
namespace xrecorder {

IMPLEMENT_SUBCLASS(XDataRecorder, "XDataRecorder")
EMPTY_SLOTTABLE(XDataRecorder)
EMPTY_DELETEDATA(XDataRecorder)

//------------------------------------------------------------------------------
// DataRecorder dispatch table
//------------------------------------------------------------------------------
BEGIN_RECORDER_HANDLER_TABLE(XDataRecorder)
   ON_RECORDER_EVENT_ID( REID_MY_DATA_EVENT, recordMyData )
END_RECORDER_HANDLER_TABLE()

XDataRecorder::XDataRecorder()
{
   STANDARD_CONSTRUCTOR()
}

void XDataRecorder::copyData(const XDataRecorder& org, const bool)
{
   BaseClass::copyData(org);
}

//------------------------------------------------------------------------------
// My Data event handler
//    value[0] => fee
//    value[1] => fi
//    value[2] => fo
//------------------------------------------------------------------------------
bool XDataRecorder::recordMyData(const base::IObject* objs[4], const double values[4])
{
   //const auto player = dynamic_cast<const simulation::Player*>( objs[0] );
   const auto msg = new recorder::protobuf_v2::proto::DataRecord();

   // DataRecord header
   timeStamp(msg);
   msg->set_id( REID_MY_DATA_EVENT );

   // new Marker message
   proto::MyDataMsg* myDataMsg = msg->MutableExtension( proto::my_data_msg );
   myDataMsg->set_fee( static_cast<unsigned int>(base::nintd(values[0])) );
   myDataMsg->set_fi( static_cast<unsigned int>(base::nintd(values[1])) );
   myDataMsg->set_fo( static_cast<unsigned int>(base::nintd(values[2])) );

   // Send the message for processing
   sendDataRecord(msg);

   return true;
}

//------------------------------------------------------------------------------
// (Overloaded) Marker event handler
//    value[0] => marker ID
//    value[1] => marker source ID
//    value[2] => foo
//------------------------------------------------------------------------------
bool XDataRecorder::recordMarker(const base::IObject* objs[4], const double values[4])
{
   //const auto player = dynamic_cast<const simulation::Player*>( objs[0] );
   const auto msg = new recorder::protobuf_v2::proto::DataRecord();

   // DataRecord header
   timeStamp(msg);
   msg->set_id( REID_MARKER );

   // Marker message
   recorder::protobuf_v2::proto::MarkerMsg* markerMsg = msg->mutable_marker_msg();
   markerMsg->set_id( static_cast<unsigned int>(base::nintd(values[0])) );
   markerMsg->set_source_id( static_cast<unsigned int>(base::nintd(values[1])) );

   // Extended value: foo
   markerMsg->SetExtension( proto::foo, static_cast<unsigned int>(base::nintd(values[2])) ) ;

   // Send the message for processing
   sendDataRecord(msg);

   return true;
}

}
}
