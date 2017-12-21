
#include "TestIoHandler.hpp"
#include "SimStation.hpp"
#include "configs/linkage/channel_map.hpp"

#include "mixr/models/system/Autopilot.hpp"
#include "mixr/models/player/air/AirVehicle.hpp"
#include "mixr/models/navigation/Navigation.hpp"
#include "mixr/models/navigation/Route.hpp"

#include "mixr/simulation/Simulation.hpp"

#include "mixr/base/concepts/linkage/AbstractIoData.hpp"
#include "mixr/base/numeric/Boolean.hpp"
#include "mixr/base/util/math_utils.hpp"

IMPLEMENT_SUBCLASS(TestIoHandler, "TestIoHandler")
EMPTY_SLOTTABLE(TestIoHandler)
EMPTY_DELETEDATA(TestIoHandler)

TestIoHandler::TestIoHandler()
{
   STANDARD_CONSTRUCTOR()
}

void TestIoHandler::copyData(const TestIoHandler& org, const bool)
{
   BaseClass::copyData(org);

   rstSw1 = org.rstSw1;
   frzSw1 = org.frzSw1;
   wpnReloadSw1 = org.wpnReloadSw1;

   wpnRelSw1 = org.wpnRelSw1;
   trgSw1 = org.trgSw1;
   tgtStepSw1 = org.tgtStepSw1;
   tgtDesSw1 = org.tgtDesSw1;
   rtn2SrchSw1 = org.rtn2SrchSw1;

   autopilotSw1 = org.autopilotSw1;
   incStptSw1 = org.incStptSw1;
   decStptSw1 = org.decStptSw1;
}

// handle input devices
void TestIoHandler::inputDevicesImpl(const double dt)
{
   readDeviceInputs(dt);

   // ---
   // get the Input data buffer
   // ---
   const mixr::base::AbstractIoData* const inData{getInputData()};

   // ---
   // get the Station, Simulation and our ownship player
   // ---
   const auto sta = static_cast<SimStation*>( findContainerByType(typeid(SimStation)) );

   mixr::simulation::Simulation* sim{};
   mixr::models::AirVehicle* av{};

   if (sta != nullptr) {
      sim = sta->getSimulation();
      av = dynamic_cast<mixr::models::AirVehicle*>(sta->getOwnship());
   }

   // ---
   // If we have everything we need ....
   // ---
   if (av != nullptr && sim != nullptr && inData != nullptr) {

      // find the (optional) autopilot
      mixr::models::Autopilot* ap{};
      {
         mixr::base::Pair* p{av->getPilotByType( typeid(mixr::models::Autopilot) )};
         if (p != nullptr) ap = static_cast<mixr::models::Autopilot*>( p->object() );
      }

      // ------------------------------------------------------------
      // Simulation Control Inputs
      // ------------------------------------------------------------

      {
         bool enabled{};
         inData->getDiscreteInput(CTL_ENABLE_SW, &enabled);

         {  // Toggle simulation freeze
            bool sw{};
            inData->getDiscreteInput(FREEZE_SW, &sw);
            const bool frzSw{sw && enabled};
            if (frzSw && !frzSw1) {
               mixr::base::Boolean newFrz( !sim->isFrozen() );
               sim->event(FREEZE_EVENT, &newFrz);
            }
            frzSw1 = frzSw;
         }

         {  // Send a reset pulse to the station
            bool sw{};
            inData->getDiscreteInput(RESET_SW, &sw);
            const bool rstSw{sw && enabled};
            if (rstSw && !rstSw1) {
               sta->event(RESET_EVENT);
            }
            rstSw1 = rstSw;
         }

         {  // Send a weapons reload pulse to the station
            bool sw{};
            inData->getDiscreteInput(RELOAD_SW, &sw);
            const bool wpnReloadSw{sw && enabled};
            if (wpnReloadSw && !wpnReloadSw1) {
               sta->event(WPN_RELOAD);
            }
            wpnReloadSw1 = wpnReloadSw;
         }

      }

      // ------------------------------------------------------------
      // Flight Control Inputs
      // ------------------------------------------------------------

      {  // Process Roll Input
         double ai{};
         inData->getAnalogInput(ROLL_AI, &ai);
         const double aiLim{mixr::base::alim(ai, 1.0)};
         if (ap != nullptr)   { ap->setControlStickRollInput(aiLim);  }
         else                 { av->setControlStickRollInput(aiLim);  }
      }

      {  // Process Pitch Input
         double ai{};
         inData->getAnalogInput(PITCH_AI, &ai);
         const double aiLim{mixr::base::alim(ai, 1.0)};
         if (ap != nullptr)   { ap->setControlStickPitchInput(aiLim); }
         else                 { av->setControlStickPitchInput(aiLim); }
      }

      {  // Process Rudder Input
         double ai{};
         inData->getAnalogInput(RUDDER_AI, &ai);
         const double aiLim{mixr::base::alim(ai, 1.0)};
         av->setRudderPedalInput(aiLim);
      }

      {  // Process Throttle Input
         double value{};
         inData->getAnalogInput(THROTTLE_AI, &value);

         if (value < 0.0)         { value = 0.0; }
         else if (value > 2.0)    { value = 2.0; }

         if (ap != nullptr)        { ap->setThrottles(&value,1); }
         else                      { av->setThrottles(&value,1); }
      }

      { // Weapons Release
         bool sw{};
         inData->getDiscreteInput(PICKLE_SW, &sw);
         if (sw != wpnRelSw1) {
            mixr::base::Boolean sw1(sw);
            av->event(WPN_REL_EVENT, &sw1);
         }
         wpnRelSw1 = sw;
      }

      { // Trigger switch
         bool sw{};
         inData->getDiscreteInput(TRIGGER_SW2, &sw);
         if (sw != trgSw1) {
            mixr::base::Boolean sw1(sw);
            av->event(TRIGGER_SW_EVENT, &sw1);
         }
         trgSw1 = sw;
      }

      { // Target Step (reject)
         bool sw{};
         inData->getDiscreteInput(TMS_RIGHT_SW, &sw);
         if (sw && !tgtStepSw1) {
            av->event(TGT_STEP_EVENT);
         }
         tgtStepSw1 = sw;
      }

      { // Target Designate
         bool sw{};
         inData->getDiscreteInput(TMS_UP_SW, &sw);
         if (sw && !tgtDesSw1) {
            av->event(TGT_DESIGNATE);
         }
         tgtDesSw1 = sw;
      }

      { // Return-To-Search
         bool sw{};
         inData->getDiscreteInput(TMS_DOWN_SW, &sw);
         if (sw && !rtn2SrchSw1) {
            av->event(SENSOR_RTS);
         }
         rtn2SrchSw1 = sw;
      }

      { // Autopilot disengage
         bool autopilotSw{};
         inData->getDiscreteInput(PADDLE_SW, &autopilotSw);
         if (autopilotSw && !autopilotSw1) {
            const auto ap = dynamic_cast<mixr::models::Autopilot*>(av->getPilot());
            if (ap != nullptr) {
               ap->setHeadingHoldMode(false);
               ap->setAltitudeHoldMode(false);
               ap->setVelocityHoldMode(false);
               ap->setLoiterMode(false);
               ap->setNavMode(false);
            }
         }
         autopilotSw1 = autopilotSw;
      }

      { // Speedbrake switch
         bool sbExtSw{};
         bool sbRetSw{};
         inData->getDiscreteInput(SB_EXT_SW, &sbExtSw);
         inData->getDiscreteInput(SB_RET_SW, &sbRetSw);

         double sb{};
         if(sbExtSw) sb = -1.0;
         if(sbRetSw) sb =  1.0;
         av->setSpeedBrakesSwitch(sb);
      }

      { // Steerpoint increment
         bool incStptSw{};
         inData->getDiscreteInput(DMS_UP_SW, &incStptSw);
         if(incStptSw && !incStptSw1) {
            // find our route and increment the steerpoint
            mixr::models::Navigation* myNav{av->getNavigation()};
            if (myNav != nullptr) {
               myNav->ref();
               mixr::models::Route* myRoute{myNav->getPriRoute()};
               if (myRoute != nullptr) {
                  myRoute->ref();
                  myRoute->incStpt();
                  myRoute->unref();
               }
            }
         }
         incStptSw1 = incStptSw;
      }

      { // Steerpoint decrement
         bool decStptSw{};
         inData->getDiscreteInput(DMS_DOWN_SW, &decStptSw);
         if (decStptSw && !decStptSw1) {
            // find our route and increment the steerpoint
            mixr::models::Navigation* myNav{av->getNavigation()};
            if (myNav != nullptr) {
               myNav->ref();
               mixr::models::Route* myRoute{myNav->getPriRoute()};
               if (myRoute != nullptr) {
                  myRoute->ref();
                  myRoute->decStpt();
                  myRoute->unref();
               }
            }
         }
         decStptSw1 = decStptSw;
      }
   }
}
