
#include "INavRadio.hpp"

#include "mixr/models/player/IPlayer.hpp"

#include "mixr/dafif/loaders/AirportLoader.hpp"
#include "mixr/dafif/loaders/NavaidLoader.hpp"

#include "WorldModel.hpp"

#include "mixr/base/units/lengths.hpp"
#include "mixr/base/util/nav_utils.hpp"

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(INavRadio, "INavRadio")
EMPTY_DELETEDATA(INavRadio)

INavRadio::INavRadio()
{
   STANDARD_CONSTRUCTOR()
}

void INavRadio::copyData(const INavRadio& org, const bool)
{
   BaseClass::copyData(org);

   latitude = org.latitude;
   longitude = org.longitude;
   altitude = org.altitude;

   apdb = nullptr;
   nvdb = nullptr;
}

//------------------------------------------------------------------------------
// shutdownNotification() -- We're shutting down
//------------------------------------------------------------------------------
bool INavRadio::shutdownNotification()
{
   apdb = nullptr;
   nvdb = nullptr;

   return BaseClass::shutdownNotification();
}

//------------------------------------------------------------------------------
// Get functions
//------------------------------------------------------------------------------

double INavRadio::getLatitude() const
{
   return latitude;
}

double INavRadio::getLongitude() const
{
   return longitude;
}

double INavRadio::getAltitude() const
{
   return altitude;
}

mixr::dafif::NavaidLoader* INavRadio::getNavaidLoader()
{
   // If we don't have a NAVAID loader, try to get one from our simulation
   if (nvdb == nullptr) {
      WorldModel* sim{dynamic_cast<WorldModel*>(getWorldModel())};
      if (sim != nullptr) {
         mixr::dafif::NavaidLoader* p{sim->getNavaids()};
         if (p != nullptr && p->isDbLoader()) {
            nvdb = p;
         }
      }
   }
   return nvdb;
}

mixr::dafif::AirportLoader* INavRadio::getAirportLoader()
{
   // If we don't have an airport loader, try to get one from our simulation
   if (apdb == nullptr) {
      WorldModel* sim{dynamic_cast<WorldModel*>(getWorldModel())};
      if (sim != nullptr) {
         mixr::dafif::AirportLoader* p{sim->getAirports()};
         if (p != nullptr && p->isDbLoader()) {
            apdb = p;
         }
      }
   }
   return apdb;
}

//------------------------------------------------------------------------------
// set the position to that of our ownship vehicle
//------------------------------------------------------------------------------
bool INavRadio::setPosition()
{
   bool ok{};

   const mixr::models::IPlayer* p{getOwnship()};
   if (p != nullptr) {
      latitude = p->getLatitude();
      longitude = p->getLongitude();
      altitude = p->getAltitudeFt();
      ok = true;
   }

   return ok;
}


