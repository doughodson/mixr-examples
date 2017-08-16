
#ifndef __Lognormal_H__
#define __Lognormal_H__

#include "AbstractRng.hpp"

namespace mixr {
  namespace base { class Number; }
}
  
//------------------------------------------------------------------------------
// Lognormal - this class returns a random variate from the lognormal distribution.
// Input parameters:
//     sigma : continuous parameter
//     mu    : continuous parameter
//     gamma : continuous location parameter (gamma = 0 for 2 parameter lognormal)
//------------------------------------------------------------------------------
class Lognormal: public AbstractRng
{
  DECLARE_SUBCLASS(Lognormal, AbstractRng)

public:
  Lognormal();

  virtual unsigned num() override;
  
  bool setSigma(const double x)            { sigma = x; return true; }
  double getSigma() const                  { return sigma; }

  bool setMu(const double x)               { mu = x; return true; }
  double getMu() const                     { return mu; }

  bool setGamma(const double x)            { gamma = x; return true; }
  double getGamma() const                  { return gamma; }

private:
  double sigma {};
  double mu {};
  double gamma {};

  bool setSlotSigma(const mixr::base::Number* const);
  bool setSlotMu(const mixr::base::Number* const);
  bool setSlotGamma(const mixr::base::Number* const);
};

#endif
