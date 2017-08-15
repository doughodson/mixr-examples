
#include "AbstractRng.hpp"
#include "mixr/base/numbers/Number.hpp"

#include <cstdlib>
#include <iostream>

IMPLEMENT_ABSTRACT_SUBCLASS(AbstractRng, "AbstractRng")
EMPTY_SERIALIZER(AbstractRng)

BEGIN_SLOTTABLE(AbstractRng)
   "seed",
END_SLOTTABLE(AbstractRng)

BEGIN_SLOT_MAP(AbstractRng)
   ON_SLOT(1, setSlotSeed, mixr::base::Number)
END_SLOT_MAP()

AbstractRng::AbstractRng()
{
   STANDARD_CONSTRUCTOR()

   std::cout << "RandomValue::RandomValue() called\n";
}

void AbstractRng::copyData(const AbstractRng& org, const bool)
{
   BaseClass::copyData(org);
   std::cout << "RandomValue::copyData() called\n";
}

void AbstractRng::deleteData()
{
   std::cout << "RandomValue::deleteData() called\n";
}

bool AbstractRng::setSeed(const unsigned int seed)
{
   std::srand(seed);
   return true;
}

bool AbstractRng::setSlotSeed(const mixr::base::Number* const seed)
{
   bool ok = false;
   if (seed != nullptr)
      ok = setSeed(seed->getInt());
   return ok;
}
