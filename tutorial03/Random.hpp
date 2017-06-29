
#ifndef __Random_H__
#define __Random_H__

#include "mixr/base/Object.hpp"

namespace mixr {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: Random
// Description: Generates random numbers
//------------------------------------------------------------------------------
class Random : public mixr::base::Object
{
   DECLARE_SUBCLASS(Random, mixr::base::Object)

public:
   Random();

   int getNum() const;
   bool setSeed(const unsigned int);

   // slot table functions
   bool setSlotSeed(const mixr::base::Number* const);
};

#endif
