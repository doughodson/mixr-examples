
#ifndef __Exponential_H__
#define __Exponential_H__

#include "AbstractRng.hpp"

namespace mixr {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Exponential
// Input parameters:
//    lambda = continuous inverse scale parameter
//    gamma  = continuous location parameter
//    mean   = 1/lambda + gamma
//
//------------------------------------------------------------------------------
class Exponential: public AbstractRng
{
  DECLARE_SUBCLASS(Exponential, AbstractRng)

public:

  Exponential();

  virtual unsigned num() override;

  bool setLambda(const double x)            { lambda = x; return true; }
  double getLambda() const                  { return lambda; }

  bool setGamma(const double x)             { gamma = x; return true; }
  double getGamma() const                   { return gamma; }

private:

  double lambda {1.0}; // continuous inverse scale parameter
  double gamma {};     // continuous location parameter

  bool setSlotLambda(const mixr::base::Number* const);
  bool setSlotGamma(const mixr::base::Number* const);
};

#endif

