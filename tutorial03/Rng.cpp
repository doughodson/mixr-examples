
#include "Rng.hpp"

#include "mixr/base/numbers/Number.hpp"
#include <cstdlib>
#include <iostream>

IMPLEMENT_SUBCLASS(Rng, "Rng")
EMPTY_DELETEDATA(Rng)
EMPTY_SERIALIZER(Rng)

BEGIN_SLOTTABLE(Rng)
   "seed",
END_SLOTTABLE(Rng)

BEGIN_SLOT_MAP(Rng)
   ON_SLOT(1, setSlotSeed, mixr::base::Number)
END_SLOT_MAP()

Rng::Rng()
{
  STANDARD_CONSTRUCTOR()
  setSeed(50);  // default random number generator seed
}

void Rng::copyData(const Rng& org, const bool)
{
  BaseClass::copyData(org);
}

bool Rng::setSeed(const unsigned int seed)
{
  std::srand(seed);
  return true;
}

int Rng::getNum() const
{
  return std::rand();
}

bool Rng::setSlotSeed(const mixr::base::Number* const seed)
{
  bool ok = false;
  if (seed != nullptr)
    ok = setSeed(seed->getInt());
  return ok;
}
