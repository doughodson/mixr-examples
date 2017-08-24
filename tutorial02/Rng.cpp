
#include "Rng.hpp"

#include <iostream>
#include <random>

IMPLEMENT_SUBCLASS(Rng, "Rng")
EMPTY_SLOTTABLE(Rng)

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

void Rng::deleteData()
{
   std::cout << "Rng::deleteData() called\n";
}

double Rng::num()
{
   return dist(engine);
}

void Rng::setSeed(const unsigned int seed)
{
   engine.seed(seed);
}
