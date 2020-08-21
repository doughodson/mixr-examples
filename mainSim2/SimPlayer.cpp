
#include "SimPlayer.hpp"

IMPLEMENT_SUBCLASS(SimPlayer, "SimPlayer")
EMPTY_DELETEDATA(SimPlayer)
EMPTY_COPYDATA(SimPlayer)
EMPTY_SLOTTABLE(SimPlayer)

SimPlayer::SimPlayer()
{
    STANDARD_CONSTRUCTOR()
    setType("Sim");
}

void SimPlayer::reset()
{
    BaseClass::reset();
}

