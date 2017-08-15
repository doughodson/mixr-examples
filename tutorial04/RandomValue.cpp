
#include "RandomValue.hpp"
#include "mixr/base/numbers/Number.hpp"

#include <cstdlib>
#include <iostream>

IMPLEMENT_ABSTRACT_SUBCLASS(RandomValue, "RandomValue")
EMPTY_SERIALIZER(RandomValue)

BEGIN_SLOTTABLE(RandomValue)
   "seed",
END_SLOTTABLE(RandomValue)

BEGIN_SLOT_MAP(RandomValue)
   ON_SLOT(1, setSlotSeed, mixr::base::Number)
END_SLOT_MAP()

RandomValue::RandomValue()
{
   STANDARD_CONSTRUCTOR()

   std::cout << "RandomValue::RandomValue() called\n";
}

void RandomValue::copyData(const RandomValue& org, const bool)
{
   BaseClass::copyData(org);
   std::cout << "RandomValue::copyData() called\n";
}

void RandomValue::deleteData()
{
   std::cout << "RandomValue::deleteData() called\n";
}

bool RandomValue::setSeed(const unsigned int seed)
{
   std::srand(seed);
   return true;
}

bool RandomValue::setSlotSeed(const mixr::base::Number* const seed)
{
   bool ok = false;
   if (seed != nullptr)
      ok = setSeed(seed->getInt());
   return ok;
}
