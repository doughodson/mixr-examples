
#ifndef __Rng_HPP__
#define __Rng_HPP__

#include "mixr/base/IObject.hpp"

#include <random>

//------------------------------------------------------------------------------
// Class: Rng
// Description: Generates random numbers
//------------------------------------------------------------------------------
class Rng final: public mixr::base::IObject
{
   DECLARE_SUBCLASS(Rng, mixr::base::IObject)

public:
   Rng();

   double num();

   void setSeed(const unsigned int);

private:
   // mersenne twister algoithm used to produce random integer
   // values, uniformly distributed from [min(), max()]
   std::mt19937 engine;
   std::uniform_real_distribution<> dist;
};

#endif
