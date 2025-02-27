
#ifndef __Uniform_HPP__
#define __Uniform_HPP__

#include "AbstractRng.hpp"

namespace mixr {
namespace base { class INumber; }
}

class Uniform final: public AbstractRng
{
   DECLARE_SUBCLASS(Uniform, AbstractRng)

public:
   Uniform();

   double num() final;

   bool setMin(const double x)  { min = x; return true; }
   double getMin() const        { return min; }

   bool setMax(const double x)  { max = x; return true; }
   double getMax() const        { return max; }

private:
   double min {};
   double max {};

private:
   // slot table helper methods
   bool setSlotMin(const mixr::base::INumber* const);
   bool setSlotMax(const mixr::base::INumber* const);
};

#endif
