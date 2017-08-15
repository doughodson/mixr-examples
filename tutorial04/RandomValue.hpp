
#ifndef __RandomValue_H__
#define __RandomValue_H__

#include "mixr/base/Object.hpp"

namespace mixr {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: RandomValue
// Description: Generates random values to feed to a particular distribution
//------------------------------------------------------------------------------
class RandomValue : public mixr::base::Object
{
   DECLARE_SUBCLASS(RandomValue, mixr::base::Object)

public:
   RandomValue();

   // data access functions
   virtual int getNum() const = 0;
   bool setSeed(const unsigned int);

   // slot table functions
   bool setSlotSeed(const mixr::base::Number* const);

};

#endif
