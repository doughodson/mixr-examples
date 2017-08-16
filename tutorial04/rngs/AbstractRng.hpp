
#ifndef __AbstractRng_H__
#define __AbstractRng_H__

#include "mixr/base/Object.hpp"

#include <random>

namespace mixr {
   namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: AbstractRng
// Description: Provides base functionality to generate random values
//              for a specific distribution
//------------------------------------------------------------------------------
class AbstractRng : public mixr::base::Object
{
   DECLARE_SUBCLASS(AbstractRng, mixr::base::Object)

public:
   AbstractRng();

   virtual unsigned num() = 0;

   void setSeed(const unsigned int);

protected:
   // mersenne twister algoithm
   std::mt19937 engine;

   // slot table functions
   bool setSlotSeed(const mixr::base::Number* const);
};

#endif
