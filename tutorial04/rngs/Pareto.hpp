
#ifndef __Pareto_H__
#define __Pareto_H__

#include "AbstractRng.hpp"

namespace mixr {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Pareto
// Input parameters:
//     alpha = order, this controls how sharp the drop-off is
//     beta = min value
//------------------------------------------------------------------------------
class Pareto: public AbstractRng
{
  DECLARE_SUBCLASS(Pareto, AbstractRng)

public:

  Pareto();

  virtual unsigned num() override;
  
  bool setAlpha(const double x)                      { alpha = x; return true; }
  double getAlpha() const                            { return alpha; }

  bool setBeta(const double x)                       { beta = x; return true; }
  double getBeta() const                             { return beta; }

private:
  double alpha {0.03};
  double beta {1.0};

  bool setSlotAlpha(const mixr::base::Number* const);
  bool setSlotBeta(const mixr::base::Number* const);
};

#endif

