
#include "Random.hpp"

#include "mixr/base/numbers/Number.hpp"
#include <cstdlib>
#include <iostream>

IMPLEMENT_SUBCLASS(Random, "Random")
EMPTY_DELETEDATA(Random)
EMPTY_SERIALIZER(Random)

BEGIN_SLOTTABLE(Random)
   "seed",
END_SLOTTABLE(Random)

BEGIN_SLOT_MAP(Random)
   ON_SLOT(1, setSlotSeed, mixr::base::Number)
END_SLOT_MAP()

Random::Random()
{
  STANDARD_CONSTRUCTOR()
  setSeed(50);  // default random number generator seed
}

void Random::copyData(const Random& org, const bool)
{
  BaseClass::copyData(org);
}

bool Random::setSeed(const unsigned int seed)
{
  std::srand(seed);
  return true;
}

int Random::getNum() const
{
  return std::rand();
}

bool Random::setSlotSeed(const mixr::base::Number* const seed)
{
  bool ok = false;
  if (seed != nullptr)
    ok = setSeed(seed->getInt());
  return ok;
}
