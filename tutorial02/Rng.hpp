
#ifndef __Rng_H__
#define __Rng_H__

#include "mixr/base/Object.hpp"

//------------------------------------------------------------------------------
// Class: Rng
// Description: Generates random numbers
//------------------------------------------------------------------------------
class Rng : public mixr::base::Object
{
   DECLARE_SUBCLASS(Rng, mixr::base::Object)

public:
   Rng();

   int getNum() const;
   void setSeed(const unsigned int);
};

#endif
