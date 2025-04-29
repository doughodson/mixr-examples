
#ifndef __PrintMyData_HPP__
#define __PrintMyData_HPP__

#include "mixr/recorder/protobuf_v2/PrintHandler.hpp"

//------------------------------------------------------------------------------
// Class: PrintMyData
// Description: Print my extended recorder data
//
// Factory name: PrintMyData
//------------------------------------------------------------------------------
class PrintMyData final: public mixr::recorder::PrintHandler
{
   DECLARE_SUBCLASS(PrintMyData, mixr::recorder::PrintHandler)

public:
   PrintMyData();

protected:
   void processRecordImp(const mixr::recorder::DataRecordHandle* const handle) final;
};

#endif
