
#ifndef __SimIoHandler_H__
#define __SimIoHandler_H__

#include "mixr/linkage/IoHandler.hpp"

//------------------------------------------------------------------------------
// Class:  SimIoHandler
//
// Description:  Handles the flow of I/O data to and from the
//               stick and throttle hardware.
//------------------------------------------------------------------------------
class SimIoHandler final: public mixr::linkage::IoHandler
{
   DECLARE_SUBCLASS(SimIoHandler, mixr::linkage::IoHandler)

public:
   SimIoHandler();

private:
   void inputDevicesImpl(const double dt) final;
   void outputDevicesImpl(const double dt) final   { writeDeviceOutputs(dt); }

private:
   bool rstSw1{};
   bool frzSw1{};
   bool wpnReloadSw1{};

   bool wpnRelSw1{};
   bool trgSw1{};
   bool tgtStepSw1{};
   bool tgtDesSw1{};
   bool rtn2SrchSw1{};

   bool autopilotSw1{};
   bool incStptSw1{};
   bool decStptSw1{};
};

#endif
