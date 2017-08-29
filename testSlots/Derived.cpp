
#include "Derived.hpp"

#include "mixr/base/numeric/Number.hpp"

#include <iostream>

IMPLEMENT_SUBCLASS(Derived, "Derived")
EMPTY_DELETEDATA(Derived)
EMPTY_COPYDATA(Derived)

BEGIN_SLOTTABLE(Derived)
   "seed",
END_SLOTTABLE(Derived)

BEGIN_SLOT_MAP(Derived)
   ON_SLOT(1, setSlotSeed, mixr::base::Number)
END_SLOT_MAP()

Derived::Derived()
{
   STANDARD_CONSTRUCTOR()
   std::cout << "Derived::Derived() called\n";
}

bool Derived::setSlotSeed(const mixr::base::Number* const)
{
   std::cout << "Derived seed being set\n";
   return true;
}

