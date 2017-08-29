
#include <iostream>

#include "Lognormal.hpp"

#include "mixr/base/numeric/Number.hpp"

using mixr::base::Number;

IMPLEMENT_SUBCLASS(Lognormal, "Lognormal")
EMPTY_DELETEDATA(Lognormal)

// slot table for this class type
BEGIN_SLOTTABLE(Lognormal)
  "mean",              // 1
  "stddev",            // 2
END_SLOTTABLE(Lognormal)
//  map slot table to handles
BEGIN_SLOT_MAP(Lognormal)
  ON_SLOT(1, setSlotMean, Number)
  ON_SLOT(2, setSlotStdDev, Number)
END_SLOT_MAP()

Lognormal::Lognormal()
{
   STANDARD_CONSTRUCTOR()
}

void Lognormal::copyData(const Lognormal& org, const bool)
{
   BaseClass::copyData(org);
   mean = org.mean;
   stddev = org.stddev;
}

double Lognormal::num()
{
   std::lognormal_distribution<double> dist(mean, stddev);
   return dist(engine);
}

bool Lognormal::setSlotMean(const Number* const x)
{
   bool ok = false;
   if (x != nullptr)
      ok = setMean(x->getDouble());
   return ok;
}

bool Lognormal::setSlotStdDev(const Number* const x)
{
   bool ok = false;
   if (x != nullptr)
      ok = setStdDev(x->getDouble());
   return ok;
}


