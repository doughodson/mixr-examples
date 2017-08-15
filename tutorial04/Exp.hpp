
#ifndef __Exp_H__
#define __Exp_H__

#include "RandomValue.hpp"

namespace mixr {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: Exponential
// Description: Generates Random Numbers
//------------------------------------------------------------------------------
class Exp : public RandomValue
{
   DECLARE_SUBCLASS(Exp, RandomValue)

public:

   Exp();

   // data access functions
   virtual void setMean(const double);

   // slot table functions
   virtual bool setSlotMean(const mixr::base::Number* const);

   virtual int getNum() const override;

private:
   double mean {10.0};

};

#endif
