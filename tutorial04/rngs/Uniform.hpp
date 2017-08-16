
#ifndef __Uniform_H__
#define __Uniform_H__

#include "AbstractRng.hpp"

namespace mixr {
namespace base { class Number; }
}

class Uniform: public AbstractRng
{
  DECLARE_SUBCLASS(Uniform, AbstractRng)

public:
  Uniform();

  virtual unsigned num() override;
  
  bool setMin(const int x)     { min = x; return true; }
  int getMin() const           { return min; }

  bool setMax(const int x)     { max = x; return true; }
  int getMax() const           { return max; }

private:
  int min {};
  int max {};

  bool setSlotMin(const mixr::base::Number* const);
  bool setSlotMax(const mixr::base::Number* const);
};

#endif
