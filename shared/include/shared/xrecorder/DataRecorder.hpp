
#ifndef __mixr_xrecorder_DataRecorder_HPP__
#define __mixr_xrecorder_DataRecorder_HPP__

#include "mixr/recorder/DataRecorder.hpp"

namespace mixr {
namespace xrecorder {

//------------------------------------------------------------------------------
// Class: DataRecorder
// Description: Example of an extended data recorder
//
// Factory name: XDataRecorder
//
// Recorder events handled ---
//
// -- new handlers --
//    REID_MY_DATA_EVENT      ! v[0] => fee;  v[1] => fi;  v[2] => fo
//
// -- Overloaded base class handler
//    REID_MARKER             ! v[0] => id;  v[1] => source id;  v[2] => foo
//
//------------------------------------------------------------------------------
class DataRecorder : public recorder::DataRecorder
{
   DECLARE_SUBCLASS(DataRecorder, recorder::DataRecorder)

public:
   DataRecorder();

protected:
   bool recordDataImp(
      const unsigned int id,              // Recorder event Id
      const base::IObject* pObjects[4],   // Sample objects
      const double values[4]              // Sample values
   ) override;

   // Recorder data event handlers
   virtual bool recordMyData(const base::IObject* objs[4], const double values[4]);

   bool recordMarker(const base::IObject* objs[4], const double values[4]) override;
};

}
}

#endif
