
#include <iostream>

#include "mixr/base/distributions/Pareto.hpp"
#include "mixr/base/numbers/Number.hpp"

namespace mixr {
namespace base {

IMPLEMENT_SUBCLASS(Pareto, "Pareto")

// slot table for this class type
BEGIN_SLOTTABLE(Pareto)
  "alpha",              // 1
  "beta",               // 2
END_SLOTTABLE(Pareto)
//  map slot table to handles
BEGIN_SLOT_MAP(Pareto)
  ON_SLOT(1, setSlotAlpha, Number)
  ON_SLOT(2, setSlotBeta, Number)
END_SLOT_MAP()

EMPTY_DELETEDATA(Pareto)

Pareto::Pareto()
{
  STANDARD_CONSTRUCTOR()
}

void Pareto::copyData(const Pareto& org, const bool cc)
{
  BaseClass::copyData(org);
  alpha = org.alpha;
  beta = org.beta;
}

double Pareto::draw()
{
  // draw a random value in the open interval (0,1)
  const double x = drawOpen();
  const double z = std::pow (x, -1.0 / alpha);
  return beta * z;
}

bool Pareto::setSlotAlpha(const Number* const x)
{
  bool ok = false;
  if(x != nullptr)
    ok = setAlpha(x->getDouble());
  return ok;
}

bool Pareto::setSlotBeta(const Number* const x)
{
  bool ok = false;
  if(x != nullptr)
    ok = setBeta(x->getDouble());
  return ok;
}

std::ostream& Pareto::serialize(std::ostream& sout, const int i, const bool slotsOnly) const
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
  sout << "alpha: " << alpha << std::endl;
  indent(sout,i+j);
  sout << "beta: " << beta << std::endl;

  if ( !slotsOnly ) {
    indent(sout,i);
    sout << ")" << std::endl;
  }

  return sout;
}

}
}
