
#include "PlaneAction.hpp"

#include "mixr/models/player/AirVehicle.hpp"
#include "mixr/models/system/StoresMgr.hpp"

namespace mixr {
namespace xbehaviors {

IMPLEMENT_SUBCLASS(PlaneAction, "PlaneAction")
EMPTY_SLOTTABLE(PlaneAction)
EMPTY_DELETEDATA(PlaneAction)
EMPTY_SERIALIZER(PlaneAction)

PlaneAction::PlaneAction()
{
   STANDARD_CONSTRUCTOR()
}

void PlaneAction::copyData(const PlaneAction& org, const bool cc)
{
   BaseClass::copyData(org);
   heading = org.heading;
   headingChanged = org.headingChanged;

   pitch = org.pitch;
   pitchChanged = org.pitchChanged;

   roll = org.roll;
   rollChanged = org.rollChanged;

   fireMissile = org.fireMissile;
   fireMissileChanged = org.fireMissileChanged;

   throttle = org.throttle;
   throttleChanged = org.throttleChanged;

   pitchTrim = org.pitchTrim;
   pitchTrimChanged = org.pitchTrimChanged;
}

void PlaneAction::setPitch(const double x)
{
   pitch = x;
   pitchChanged = true;
}

void PlaneAction::setRoll(const double x)
{
   roll = x;
   rollChanged = true;
}

void PlaneAction::setHeading(const double x)
{
   heading = x;
   headingChanged = true;
}

void PlaneAction::setThrottle(const double x)
{
   throttle = x;
   throttleChanged = true;
}

void PlaneAction::setFireMissile(const bool x)
{
   fireMissile = x;
   fireMissileChanged = true;
}

void PlaneAction::setPitchTrim(const double x)
{
   pitchTrim = x;
   pitchTrimChanged = true;
}

bool PlaneAction::execute(base::Component* actor)
{
   const auto airVehicle = dynamic_cast<models::AirVehicle*>(actor);
   if (airVehicle != nullptr) {
      airVehicle->setControlStick(static_cast<double>(getRoll()), static_cast<double>(getPitch()));

      // set throttle to engines(assuming there are 8 or less)
      double throttles[8];
      for(int i = 0 ; i < airVehicle->getNumberOfEngines() ; i++) {
         throttles[i] = static_cast<double>(getThrottle());
      }
      if (isThrottleChanged()) {
         airVehicle->setThrottles(throttles,2);
      }
      if(isPitchTrimChanged()) {
         airVehicle->setTrimSwitch(0, static_cast<double>(getPitchTrim()));
      }
      //airVehicle->setRudderPedalInput(planeAction->getHeading());
      //airVehicle->setVelocity(0, 0, 0);

      if (getFireMissile()) {
         // this should be an action generated by a behavior
         // Set weapons to anti-aircraft mode.
         models::StoresMgr* sms = airVehicle->getStoresManagement();
         if (sms != nullptr) {
            sms->setWeaponDeliveryMode(models::StoresMgr::A2A);
            std::cout << "Set A/A Weapon Mode!" << std::endl;

            airVehicle->event(base::Component::WPN_REL_EVENT);
            //WPN_REL_EVENT         = 1405,  // Passes requested switch state as Boolean
                                          // or no argument for one-shot event
            std::cout << "Launched A/A Weapon !" << std::endl;
         }
      }
      return true;
   }
   return false;
}

}
}

