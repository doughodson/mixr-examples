
#include "AbstractRng.hpp"

#include "mixr/base/numeric/Integer.hpp"

#include <iostream>
#include <random>

IMPLEMENT_ABSTRACT_SUBCLASS(AbstractRng, "AbstractRng")
EMPTY_DELETEDATA(AbstractRng)
EMPTY_COPYDATA(AbstractRng)

BEGIN_SLOTTABLE(AbstractRng)
   "seed",
END_SLOTTABLE(AbstractRng)

BEGIN_SLOT_MAP(AbstractRng)
   ON_SLOT(1, setSlotSeed, mixr::base::Integer)
END_SLOT_MAP()

AbstractRng::AbstractRng()
{
   STANDARD_CONSTRUCTOR()
}

void AbstractRng::setSeed(const int seed)
{
   engine.seed(seed);
}

bool AbstractRng::setSlotSeed(const mixr::base::Integer* const seed)
{
   bool ok = false;
   if (seed != nullptr) {
      setSeed(seed->asInt());
      ok = true;
   }
   return ok;
}

