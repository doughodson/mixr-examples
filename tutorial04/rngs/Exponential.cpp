
#include <iostream>

#include "Exponential.hpp"
#include "mixr/base/numeric/Number.hpp"

using mixr::base::Number;

IMPLEMENT_SUBCLASS(Exponential,"Exponential")
EMPTY_DELETEDATA(Exponential)

// slot table for this class type
BEGIN_SLOTTABLE(Exponential)
   "mean",
END_SLOTTABLE(Exponential)
//  map slot table to handles
BEGIN_SLOT_MAP(Exponential)
   ON_SLOT(1, setSlotMean, Number)
END_SLOT_MAP()

Exponential::Exponential()
{
   STANDARD_CONSTRUCTOR()
}

void Exponential::copyData(const Exponential& org, const bool)
{
   BaseClass::copyData(org);
   mean = org.mean;
}

double Exponential::num()
{
   std::exponential_distribution<double> dist(mean);
   return dist(engine);
}

bool Exponential::setSlotMean(const Number* const x)
{
   bool ok = false;
   if (x != nullptr)
      ok = setMean(x->getDouble());
   return ok;
}


