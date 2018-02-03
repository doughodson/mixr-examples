
#include "Rng.hpp"

#include "mixr/base/numeric/Integer.hpp"

#include <iostream>
#include <random>

IMPLEMENT_SUBCLASS(Rng, "Rng")
EMPTY_DELETEDATA(Rng)

BEGIN_SLOTTABLE(Rng)
   "seed",
END_SLOTTABLE(Rng)

BEGIN_SLOT_MAP(Rng)
   ON_SLOT(1, setSlotSeed, mixr::base::Integer)
END_SLOT_MAP()

Rng::Rng()
{
   STANDARD_CONSTRUCTOR()
   std::cout << "Rng::Rng() called\n";
}

void Rng::copyData(const Rng& org, const bool)
{
   BaseClass::copyData(org);
   std::cout << "Rng::copyData() called\n";
}

double Rng::num()
{
   return dist(engine);
}

void Rng::setSeed(const int seed)
{
   engine.seed(seed);
}

bool Rng::setSlotSeed(const mixr::base::Integer* const seed)
{
   bool ok{};
   if (seed != nullptr) {
      setSeed(seed->asInt());
      ok = true;
   }
   return ok;
}

