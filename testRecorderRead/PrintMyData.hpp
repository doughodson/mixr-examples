
#ifndef __PrintMyData_H__
#define __PrintMyData_H__

#include "mixr/recorder/PrintHandler.hpp"

//------------------------------------------------------------------------------
// Class: PrintMyData
// Description: Print my extended recorder data
//
// Factory name: PrintMyData
//------------------------------------------------------------------------------
class PrintMyData : public mixr::recorder::PrintHandler
{
   DECLARE_SUBCLASS(PrintMyData, mixr::recorder::PrintHandler)

public:
   PrintMyData();

protected:
   virtual void processRecordImp(const mixr::recorder::DataRecordHandle* const handle) override;
};

#endif
