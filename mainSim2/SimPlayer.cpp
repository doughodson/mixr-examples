
#include "SimPlayer.hpp"
#include "mixr/base/List.hpp"
#include "mixr/base/units/Angles.hpp"

IMPLEMENT_SUBCLASS(SimPlayer, "SimPlayer")
EMPTY_DELETEDATA(SimPlayer)
EMPTY_COPYDATA(SimPlayer)
EMPTY_SLOTTABLE(SimPlayer)

SimPlayer::SimPlayer()
{
    STANDARD_CONSTRUCTOR()

    static mixr::base::String generic("Sim");
    setType(&generic);
}

void SimPlayer::reset()
{
    BaseClass::reset();
}

