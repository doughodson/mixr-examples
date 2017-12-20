
#ifndef __TestIoHandler_H__
#define __TestIoHandler_H__

#include "mixr/linkage/IoHandler.hpp"

//------------------------------------------------------------------------------
// Class:  TestIoHandler
//
// Description: Handles the flow of I/O data to and from devices
//------------------------------------------------------------------------------
class TestIoHandler final: public mixr::linkage::IoHandler
{
   DECLARE_SUBCLASS(TestIoHandler, mixr::linkage::IoHandler)

public:
   TestIoHandler();

private:
   void inputDevicesImpl(const double dt) override   { readDeviceInputs(dt);   }
   void outputDevicesImpl(const double dt) override  { writeDeviceOutputs(dt); }
};

#endif
