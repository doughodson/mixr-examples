
#ifndef __SimPlayer_HPP__
#define __SimPlayer_HPP__

#include "mixr/models/player/air/IAircraft.hpp"

//------------------------------------------------------------------------------
// Class: SimPlayer
//
// Description: Simulation player
//------------------------------------------------------------------------------
class SimPlayer final: public mixr::models::IAircraft
{
    DECLARE_SUBCLASS(SimPlayer, mixr::models::IAircraft)

public:
    SimPlayer();

    void reset() final;
};

#endif
