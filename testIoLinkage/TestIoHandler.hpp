
#ifndef __TestIoHandler_H__
#define __TestIoHandler_H__

#include "mixr/iolinkage/IoHandler.hpp"

//------------------------------------------------------------------------------
// Class:  TestIoHandler
//
// Description: Handles the flow of I/O data to and from devices
//------------------------------------------------------------------------------
class TestIoHandler : public mixr::iolinkage::IoHandler
{
   DECLARE_SUBCLASS(TestIoHandler, mixr::iolinkage::IoHandler)

public:
   TestIoHandler();

private:
   void inputDevicesImpl(const double dt) override   { readDeviceInputs(dt);   }
   void outputDevicesImpl(const double dt) override  { writeDeviceOutputs(dt); }
};

#endif
