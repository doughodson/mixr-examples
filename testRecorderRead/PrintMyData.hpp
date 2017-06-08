
#ifndef __PrintMyData_H__
#define __PrintMyData_H__

#include "mxrp/recorder/PrintHandler.hpp"

//------------------------------------------------------------------------------
// Class: PrintMyData
// Description: Print my extended recorder data
//
// Factory name: PrintMyData
//------------------------------------------------------------------------------
class PrintMyData : public mxrp::recorder::PrintHandler
{
   DECLARE_SUBCLASS(PrintMyData, mxrp::recorder::PrintHandler)

public:
   PrintMyData();

protected:
   virtual void processRecordImp(const mxrp::recorder::DataRecordHandle* const handle) override;
};

#endif
