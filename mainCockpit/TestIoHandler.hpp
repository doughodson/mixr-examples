
#ifndef __TestIoHandler_H__
#define __TestIoHandler_H__

#include "mixr/iolinkage/IoHandler.hpp"

//------------------------------------------------------------------------------
// Class:  TestIoHandler
//
// Description: Handles the flow of I/O data to and from the
//              stick and throttle hardware.
//------------------------------------------------------------------------------
class TestIoHandler : public mixr::iolinkage::IoHandler
{
   DECLARE_SUBCLASS(TestIoHandler, mixr::iolinkage::IoHandler)

public:
   TestIoHandler();

private:
   void inputDevicesImpl(const double dt) override;
   void outputDevicesImpl(const double dt) override  { writeDeviceOutputs(dt); }

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
