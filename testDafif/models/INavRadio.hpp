
#ifndef __INavRadio_HPP__
#define __INavRadio_HPP__

#include "mixr/models/system/IRadio.hpp"

namespace mixr {
namespace dafif { class AirportLoader; class NavaidLoader; }
}

//------------------------------------------------------------------------------
// Class: INavRadio
// Description: Interface to navigation radio models
// The NAV radios are being updated and are not current fully functional!!!
// Factory name: INavRadio
//------------------------------------------------------------------------------
class INavRadio : public mixr::models::IRadio
{
   DECLARE_SUBCLASS(INavRadio, mixr::models::IRadio)

public:
   INavRadio();

protected:
   double getLatitude() const;
   double getLongitude() const;
   double getAltitude() const;

   mixr::dafif::NavaidLoader* getNavaidLoader();
   mixr::dafif::AirportLoader* getAirportLoader();

   // Slave our position to our ownship
   virtual bool setPosition();

   bool shutdownNotification() override;

private:
   mixr::base::safe_ptr<mixr::dafif::AirportLoader> apdb; // Pointer to Airport loader
   mixr::base::safe_ptr<mixr::dafif::NavaidLoader> nvdb;  // Pointer to Navaid loader

   double latitude{};           // Ownship Latitude
   double longitude{};          // Ownship Longitude
   double altitude{};           // Ownship altitude HAE (ft)
};

#endif
