
#ifndef __Exponential_H__
#define __Exponential_H__

#include "AbstractRng.hpp"

namespace mixr {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: Exponential
//------------------------------------------------------------------------------
class Exponential final: public AbstractRng
{
   DECLARE_SUBCLASS(Exponential, AbstractRng)

public:
   Exponential();

   double num() final;

   bool setMean(const double x)            { mean = x; return true; }
   double getMean() const                  { return mean; }

private:
   double mean {1.0};  // mean of distribution

private:
   // slot table helper methods
   bool setSlotMean(const mixr::base::Number* const);
};

#endif
