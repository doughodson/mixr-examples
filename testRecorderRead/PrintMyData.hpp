
#ifndef __PrintMyData_HPP__
#define __PrintMyData_HPP__

#include "mixr/recorder/protobuf_v2/IPrintHandler.hpp"

//------------------------------------------------------------------------------
// Class: PrintMyData
// Description: Print my extended recorder data
//
// Factory name: PrintMyData
//------------------------------------------------------------------------------
class PrintMyData final: public mixr::recorder::protobuf_v2::IPrintHandler
{
   DECLARE_SUBCLASS(PrintMyData, mixr::recorder::protobuf_v2::IPrintHandler)

public:
   PrintMyData();

protected:
   void processRecordImp(const mixr::recorder::protobuf_v2::DataRecordHandle* const handle) final;
};

#endif
