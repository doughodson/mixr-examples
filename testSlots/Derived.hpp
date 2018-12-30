
#ifndef __Derived_HPP__
#define __Derived_HPP__

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
