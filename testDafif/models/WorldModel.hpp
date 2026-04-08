
#ifndef __WorldModel_HPP__
#define __WorldModel_HPP__

#include "mixr/models/IWorldModel.hpp"

namespace mixr {
namespace dafif { class AirportLoader; class NavaidLoader; class WaypointLoader; }
}

//------------------------------------------------------------------------------
// Class: WorldModel
//
// Description: Extends model::WorldModel by adding DAFIF support.
//
// Slots --
//
//    airportLoader  <dafif::AirportLoader>   ! Airport database (default: nullptr)
//    navaidLoader   <dafif::NavaidLoader>    ! NAVAID database (default: nullptr)
//    waypointLoader <dafif::WaypointLoader>  ! Waypoint database (default: nullptr)
//
// Factory name: WorldModel
//------------------------------------------------------------------------------
class WorldModel final: public mixr::models::IWorldModel
{
   DECLARE_SUBCLASS(WorldModel, mixr::models::IWorldModel)

public:
   WorldModel();

   mixr::dafif::AirportLoader* getAirports();           // Returns the airport loader
   mixr::dafif::NavaidLoader* getNavaids();             // Returns the NAVAID loader
   mixr::dafif::WaypointLoader* getWaypoints();         // Returns the waypoint loader

   void updateData(const double dt = 0.0) override;

private:
   mixr::dafif::AirportLoader*  airports{};    // Airport loader
   mixr::dafif::NavaidLoader*   navaids{};     // NAVAID loader
   mixr::dafif::WaypointLoader* waypoints {};  // Waypoint loader

private:
   // slot table helper methods
   bool setSlotAirports(mixr::dafif::AirportLoader* const);   // Sets the airport loader
   bool setSlotNavaids(mixr::dafif::NavaidLoader* const);     // Sets the NAVAID loader
   bool setSlotWaypoints(mixr::dafif::WaypointLoader* const); // Sets the waypoint loader
};


#endif
