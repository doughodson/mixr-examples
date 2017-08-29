
#ifndef __Base_H__
#define __Base_H__

#include "mixr/base/Object.hpp"

namespace mixr {
   namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: Base
// Description: Base class that processes slot inputs
//------------------------------------------------------------------------------
class Base : public mixr::base::Object
{
   DECLARE_SUBCLASS(Base, mixr::base::Object)

public:
   Base();

private:
   // slot table helper methods
   bool setSlotSeed(const mixr::base::Number* const);
};

#endif
