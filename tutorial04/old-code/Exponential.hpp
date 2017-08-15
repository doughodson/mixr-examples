
#ifndef __mixr_base_Exponential_H__
#define __mixr_base_Exponential_H__

#include "../Rng.hpp"

namespace mixr {
namespace base {

//------------------------------------------------------------------------------
// Exponential
// Input parameters:
//    lambda = continuous inverse scale parameter
//    gamma  = continuous location parameter
//    mean   = 1/lambda + gamma
//
//------------------------------------------------------------------------------

class Number;

class Exponential: public Rng
{
  DECLARE_SUBCLASS(Exponential, Rng)

public:

  Exponential();

  virtual double draw() override;

  bool setLambda(const double x) { lambda = x; return true; }
  double getLambda() const { return lambda; }
  bool setSlotLambda(const Number* const);

  bool setGamma(const double x) { gamma = x; return true; }
  double getGamma() const { return gamma; }
  bool setSlotGamma(const Number* const);

protected:

  double lambda {1.0}; // continuous inverse scale parameter
  double gamma {};     // continuous location parameter
};

}
}

#endif

