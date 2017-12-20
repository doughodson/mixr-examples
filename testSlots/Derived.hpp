
#ifndef __Derived_H__
#define __Derived_H__

#include "Base.hpp"

namespace mixr {
   namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: Derived
// Description: Derived off Base class
//------------------------------------------------------------------------------
class Derived final: public Base
{
   DECLARE_SUBCLASS(Derived, Base)

public:
   Derived();

private:
   // slot table helper methods
   bool setSlotSeed(const mixr::base::Number* const);
};

#endif
