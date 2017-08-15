
#ifndef __Uniform_H__
#define __Uniform_H__

#include "AbstractRng.hpp"

namespace mixr {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: Uniform
// Description: Generates Random Numbers
//------------------------------------------------------------------------------
class Uniform : public AbstractRng
{
   DECLARE_SUBCLASS(Uniform, AbstractRng)

public:
   Uniform();

   // data access functions
   void setMax(const int);
   void setMin(const int);

   // slot table functions
   bool setSlotMax(const mixr::base::Number* const);
   bool setSlotMin(const mixr::base::Number* const);

   virtual int getNum() const override;

private:
   int min {};
   int max {1};
};

#endif
