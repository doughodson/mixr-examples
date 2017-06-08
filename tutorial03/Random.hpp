
#ifndef __Random_H__
#define __Random_H__

#include "mxrp/base/Object.hpp"

namespace mxrp {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: Random
// Description: Generates random numbers
//------------------------------------------------------------------------------
class Random : public mxrp::base::Object
{
   DECLARE_SUBCLASS(Random, mxrp::base::Object)

public:
   Random();

   int getNum() const;
   bool setSeed(const unsigned int);

   // slot table functions
   bool setSlotSeed(const mxrp::base::Number* const);
};

#endif
