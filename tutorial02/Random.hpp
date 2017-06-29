
#ifndef __Random_H__
#define __Random_H__

#include "mixr/base/Object.hpp"

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
   void setSeed(const unsigned int);
};

#endif
