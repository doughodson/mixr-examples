
#ifndef __Random_H__
#define __Random_H__

#include "mxrp/base/Object.hpp"

namespace mxrp {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: Random
// Description: Generates Random Numbers
//------------------------------------------------------------------------------
class Random : public mxrp::base::Object
{
   DECLARE_SUBCLASS(Random, mxrp::base::Object)

public:
   Random();

   // data access functions
   virtual int getNum() const = 0;
   bool setSeed(const unsigned int);

   // slot table functions
   bool setSlotSeed(const mxrp::base::Number* const);

};

#endif
