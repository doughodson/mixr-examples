
#include "Base.hpp"

#include "mixr/base/numeric/Number.hpp"

#include <iostream>

IMPLEMENT_SUBCLASS(Base, "Base")
EMPTY_DELETEDATA(Base)
EMPTY_COPYDATA(Base)

BEGIN_SLOTTABLE(Base)
   "seed",
END_SLOTTABLE(Base)

BEGIN_SLOT_MAP(Base)
   ON_SLOT(1, setSlotSeed, mixr::base::Number)
END_SLOT_MAP()

Base::Base()
{
   STANDARD_CONSTRUCTOR()
   std::cout << "Base::Base() called\n";
}

bool Base::setSlotSeed(const mixr::base::Number* const)
{
   std::cout << "Base seed being set\n";
   return true;
}
