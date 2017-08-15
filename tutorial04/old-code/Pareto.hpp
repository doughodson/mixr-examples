
#ifndef __mixr_base_Pareto_H__
#define __mixr_base_Pareto_H__

#include "../Rng.hpp"

namespace mixr {
namespace base {

//------------------------------------------------------------------------------
// Pareto
// Input parameters:
//     alpha = order, this controls how sharp the drop-off is
//     beta = min value
//------------------------------------------------------------------------------

class Number;

class Pareto: public Rng
{
  DECLARE_SUBCLASS(Pareto, Rng)

public:

  Pareto();

  virtual double draw() override;

  bool setAlpha(const double x)                      { alpha = x; return true; }
  double getAlpha() const                            { return alpha; }
  bool setSlotAlpha(const Number* const);

  bool setBeta(const double x)                       { beta = x; return true; }
  double getBeta() const                             { return beta; }
  bool setSlotBeta(const Number* const);

protected:
  double alpha {0.03};
  double beta {1.0};
};

}
}

#endif

