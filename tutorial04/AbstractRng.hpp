
#ifndef __AbstractRng_H__
#define __AbstractRng_H__

#include "mixr/base/Object.hpp"

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

   // data access functions
   virtual int getNum() const = 0;
   bool setSeed(const unsigned int);

   // slot table functions
   bool setSlotSeed(const mixr::base::Number* const);

};

#endif
