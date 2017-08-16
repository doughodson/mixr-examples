
#include <iostream>

#include "Uniform.hpp"
#include "mixr/base/numbers/Number.hpp"

using mixr::base::Number;

IMPLEMENT_SUBCLASS(Uniform,"Uniform")
EMPTY_DELETEDATA(Uniform)

// slot table for this class type
BEGIN_SLOTTABLE(Uniform)
  "min",            // 1
  "max",            // 2
END_SLOTTABLE(Uniform)
//  map slot table to handles
BEGIN_SLOT_MAP(Uniform)
  ON_SLOT(1, setSlotMin, Number)
  ON_SLOT(2, setSlotMax, Number)
END_SLOT_MAP()

Uniform::Uniform()
{
   STANDARD_CONSTRUCTOR()
}

void Uniform::copyData(const Uniform& org, const bool cc)
{
   BaseClass::copyData(org);

   min = org.min;
   max = org.max;
}

unsigned Uniform::num()
{
   std::uniform_int_distribution<> dist(min, max);
   const unsigned val = dist(engine);
   return val;
}

bool Uniform::setSlotMin(const Number* const x)
{
   bool ok = false;
   if (x != nullptr)
      ok = setMin(x->getDouble());
   return ok;
}

bool Uniform::setSlotMax(const Number* const x)
{
   bool ok = false;
   if (x != nullptr)
      ok = setMax(x->getDouble());
   return ok;
}

std::ostream& Uniform::serialize(std::ostream& sout, const int i, const bool slotsOnly) const
{
   int j = 0;
   if ( !slotsOnly ) {
//    indent(sout,i);
      sout << "( " << getFactoryName() << std::endl;
      j = 4;
   }

   // serialize base class
   BaseClass::serialize(sout,i+j,true);

   indent(sout,i+j);
   sout << "min: " << min << std::endl;
   indent(sout,i+j);
   sout << "max: " << max << std::endl;

   if ( !slotsOnly ) {
      indent(sout,i);
      sout << ")" << std::endl;
   }

   return sout;
}

