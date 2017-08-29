
#include "AbstractRng.hpp"

#include "mixr/base/numeric/Number.hpp"

#include <iostream>
#include <random>

IMPLEMENT_ABSTRACT_SUBCLASS(AbstractRng, "AbstractRng")
EMPTY_DELETEDATA(AbstractRng)
EMPTY_COPYDATA(AbstractRng)

BEGIN_SLOTTABLE(AbstractRng)
   "seed",
END_SLOTTABLE(AbstractRng)

BEGIN_SLOT_MAP(AbstractRng)
   ON_SLOT(1, setSlotSeed, mixr::base::Number)
END_SLOT_MAP()

AbstractRng::AbstractRng()
{
   STANDARD_CONSTRUCTOR()
}

void AbstractRng::setSeed(const unsigned int seed)
{
   engine.seed(seed);
}

bool AbstractRng::setSlotSeed(const mixr::base::Number* const seed)
{
   bool ok = false;
   if (seed != nullptr) {
      setSeed(seed->getInt());
      ok = true;
   }
   return ok;
}

