
#ifndef __TestIoHandler_H___
#define __TestIoHandler_H___

#include "mixr/linkage/IoHandler.hpp"

//------------------------------------------------------------------------------
// Class: TestIoHandler
//
// Description:  Handles the flow of I/O data to and from the
//               stick and throttle hardware.
//------------------------------------------------------------------------------
class TestIoHandler : public mixr::linkage::IoHandler
{
   DECLARE_SUBCLASS(TestIoHandler, mixr::linkage::IoHandler)

public:
   TestIoHandler();

private:
   void inputDevicesImpl(const double dt) override;
   void outputDevicesImpl(const double dt) override    { writeDeviceOutputs(dt); }

private:
   bool rstSw1 {};
   bool frzSw1 {};
   bool wpnReloadSw1 {};

   bool wpnRelSw1 {};
   bool trgSw1 {};
   bool tgtStepSw1 {};
   bool tgtDesSw1 {};
   bool rtn2SrchSw1 {};

   bool autopilotSw1 {};
   bool incStptSw1 {};
   bool decStptSw1 {};
};

#endif
