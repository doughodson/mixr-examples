
#ifndef __SimPlayer_H__
#define __SimPlayer_H__

#include "mixr/models/player/AirVehicle.hpp"

//------------------------------------------------------------------------------
// Class: SimPlayer
//
// Description: Simulation player
//------------------------------------------------------------------------------
class SimPlayer : public mixr::models::Aircraft
{
    DECLARE_SUBCLASS(SimPlayer, mixr::models::Aircraft)

public:
    SimPlayer();

    virtual void reset() override;
};

#endif
