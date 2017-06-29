
#ifndef __WorldModel_H__
#define __WOrldModel_H__

#include "mixr/models/WorldModel.hpp"

namespace mixr {
namespace dafif { class AirportLoader; class NavaidLoader; class WaypointLoader; }
}

//------------------------------------------------------------------------------
// Class: WorldModel
//
// Description: Class to manage the reference position, and other common
//              simulation support components (ground truths, terrain elevation
//              database, etc)
//
// Slots --
//
//    airportLoader  <dafif::AirportLoader>   ! Airport database (default: nullptr)
//    navaidLoader   <dafif::NavaidLoader>    ! NAVAID database (default: nullptr)
//    waypointLoader <dafif::WaypointLoader>  ! Waypoint database (default: nullptr)
//
//
// Environments:
//
//    Current simulation environments include terrain elevation posts, getTerrain(),
//    atmosphere model, getAtmosphere(), and DAFIF navigational aids,
//    getNavaids(), getAirports() and getWaypoints().
//
// Shutdown:
//
//    At shutdown, the parent object must send a SHUTDOWN_EVENT event to
//    this object, environments and other components.
//
// Factory name: Simulation
//------------------------------------------------------------------------------
class WorldModel : public mixr::models::WorldModel
{
    DECLARE_SUBCLASS(WorldModel, mixr::models::WorldModel)

public:
    WorldModel();

    mixr::dafif::AirportLoader* getAirports();           // Returns the airport loader
    mixr::dafif::NavaidLoader* getNavaids();             // Returns the NAVAID loader
    mixr::dafif::WaypointLoader* getWaypoints();         // Returns the waypoint loader

    virtual bool setAirports(mixr::dafif::AirportLoader* const p);   // Sets the airport loader
    virtual bool setNavaids(mixr::dafif::NavaidLoader* const p);     // Sets the NAVAID loader
    virtual bool setWaypoints(mixr::dafif::WaypointLoader* const p); // Sets the waypoint loader

    virtual void updateData(const double dt = 0.0) override;

private:
   mixr::dafif::AirportLoader*  airports {};   // Airport loader
   mixr::dafif::NavaidLoader*   navaids {};    // NAVAID loader
   mixr::dafif::WaypointLoader* waypoints {};  // Waypoint loader

};


#endif
