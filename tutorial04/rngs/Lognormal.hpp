
#ifndef __Lognormal_HPP__
#define __Lognormal_HPP__

#include "AbstractRng.hpp"

namespace mixr {
  namespace base { class INumber; }
}

//------------------------------------------------------------------------------
// Lognormal - this class returns a random variate from the lognormal distribution.
// Input parameters:
//     sigma : continuous parameter
//     mu    : continuous parameter
//     gamma : continuous location parameter (gamma = 0 for 2 parameter lognormal)
//------------------------------------------------------------------------------
class Lognormal final: public AbstractRng
{
   DECLARE_SUBCLASS(Lognormal, AbstractRng)

public:
   Lognormal();

   double num() final;

   bool setMean(const double x)       { mean = x; return true; }
   double getMean() const             { return mean; }

   bool setStdDev(const double x)     { stddev = x; return true; }
   double getStdDev() const           { return stddev; }

private:
   double mean{};
   double stddev{};

private:
   // slot table helper methods
   bool setSlotMean(const mixr::base::INumber* const);
   bool setSlotStdDev(const mixr::base::INumber* const);
};

#endif
