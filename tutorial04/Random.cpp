//------------------------------------------------------------------------------
// Random
//------------------------------------------------------------------------------

#include "Random.h"
#include "openeaagles/base/Number.h"
#include <cstdlib>

namespace oe {
namespace tutorial {

IMPLEMENT_ABSTRACT_SUBCLASS(Random,"Random")
// setup slot table
BEGIN_SLOTTABLE(Random)
    "seed",              // random number seed value
END_SLOTTABLE(Random)
// map attributes to slots
BEGIN_SLOT_MAP(Random)
    ON_SLOT(1, setSlotSeed, base::Number)
END_SLOT_MAP()
// nothing to serialize
EMPTY_SERIALIZER(Random)

//------------------------------------------------------------------------------
// Constructor(s)
//------------------------------------------------------------------------------
Random::Random(void)
{
   STANDARD_CONSTRUCTOR()

   std::cout << "Random::Random() called\n";
}

//------------------------------------------------------------------------------
// copyData() -- copy member data
//------------------------------------------------------------------------------
void Random::copyData(const Random& org, const bool)
{
   BaseClass::copyData(org);
   std::cout << "Random::copyData() called\n";
}

//------------------------------------------------------------------------------
//deleteData() -- delete member data
//------------------------------------------------------------------------------
void Random::deleteData()
{
   std::cout << "Random::deleteData() called\n";
}

//------------------------------------------------------------------------------
// data access functions
//------------------------------------------------------------------------------
bool Random::setSeed(const unsigned int seed)
{
   std::srand(seed);
   return true;
}

//------------------------------------------------------------------------------
// slot table functions
//------------------------------------------------------------------------------
base::Object* Random::getSlotByIndex(const int si)
{
   return BaseClass::getSlotByIndex(si);
}

bool Random::setSlotSeed(const base::Number* const seed)
{
   bool ok = false;
   if (seed != nullptr)
      ok = setSeed(seed->getInt());
   return ok;
}

} // namespace tutorial
} // namespace oe

