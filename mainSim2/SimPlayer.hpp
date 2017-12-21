
#ifndef __SimPlayer_H__
#define __SimPlayer_H__

#include "mixr/models/player/air/Aircraft.hpp"

//------------------------------------------------------------------------------
// Class: SimPlayer
//
// Description: Simulation player
//------------------------------------------------------------------------------
class SimPlayer final: public mixr::models::Aircraft
{
    DECLARE_SUBCLASS(SimPlayer, mixr::models::Aircraft)

public:
    SimPlayer();

    void reset() final;
};

#endif
