
#ifndef __AbstractRng_HPP__
#define __AbstractRng_HPP__

#include "mixr/base/IObject.hpp"

#include <random>

namespace mixr {
   namespace base { class Integer; }
}

//------------------------------------------------------------------------------
// Class: AbstractRng
// Description: Provides base functionality to generate random values
//              for a specific distribution
//------------------------------------------------------------------------------
class AbstractRng : public mixr::base::IObject
{
   DECLARE_SUBCLASS(AbstractRng, mixr::base::IObject)

public:
   AbstractRng();

   virtual double num() =0;

   void setSeed(const int);

protected:
   // mersenne twister algoithm
   std::mt19937 engine;

private:
   // slot table helper methods
   bool setSlotSeed(const mixr::base::Integer* const);
};

#endif
