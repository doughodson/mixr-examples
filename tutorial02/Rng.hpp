
#ifndef __Rng_H__
#define __Rng_H__

#include "mixr/base/Object.hpp"

#include <random>

//------------------------------------------------------------------------------
// Class: Rng
// Description: Generates random numbers
//------------------------------------------------------------------------------
class Rng final: public mixr::base::Object
{
   DECLARE_SUBCLASS(Rng, mixr::base::Object)

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
