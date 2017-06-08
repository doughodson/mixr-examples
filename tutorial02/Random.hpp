
#ifndef __Random_H__
#define __Random_H__

#include "mxrp/base/Object.hpp"

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
   void setSeed(const unsigned int);
};

#endif
