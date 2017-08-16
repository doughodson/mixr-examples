
#include "Rng.hpp"

#include <cstdlib>
#include <iostream>

IMPLEMENT_SUBCLASS(Rng, "Rng")
EMPTY_SLOTTABLE(Rng)
EMPTY_SERIALIZER(Rng)

Rng::Rng()
{
   STANDARD_CONSTRUCTOR()

   // seed the random number generator
   setSeed(100);

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

int Rng::getNum() const
{
   return std::rand();
}

void Rng::setSeed(const unsigned int seed)
{
   std::srand(seed);
}
