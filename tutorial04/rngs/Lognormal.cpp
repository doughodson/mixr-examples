
#include <iostream>

#include "Lognormal.hpp"

#include "mixr/base/numeric/INumber.hpp"

IMPLEMENT_SUBCLASS(Lognormal, "Lognormal")
EMPTY_DELETEDATA(Lognormal)

// slot table for this class type
BEGIN_SLOTTABLE(Lognormal)
  "mean",              // 1
  "stddev",            // 2
END_SLOTTABLE(Lognormal)
//  map slot table to handles
BEGIN_SLOT_MAP(Lognormal)
  ON_SLOT(1, setSlotMean, mixr::base::INumber)
  ON_SLOT(2, setSlotStdDev, mixr::base::INumber)
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

bool Lognormal::setSlotMean(const mixr::base::INumber* const x)
{
   bool ok = false;
   if (x != nullptr)
      ok = setMean(x->asDouble());
   return ok;
}

bool Lognormal::setSlotStdDev(const mixr::base::INumber* const x)
{
   bool ok = false;
   if (x != nullptr)
      ok = setStdDev(x->asDouble());
   return ok;
}


