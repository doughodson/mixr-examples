
#ifndef __Rng_H__
#define __Rng_H__

#include "mixr/base/Object.hpp"

namespace mixr {
namespace base { class Number; }
}

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
   bool setSeed(const unsigned int);

   // slot table functions
   bool setSlotSeed(const mixr::base::Number* const);
};

#endif
