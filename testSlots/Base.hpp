
#ifndef __Base_HPP__
#define __Base_HPP__

#include "mixr/base/IObject.hpp"

namespace mixr {
   namespace base { class INumber; }
}

//------------------------------------------------------------------------------
// Class: Base
// Description: Base class that processes slot inputs
//------------------------------------------------------------------------------
class Base : public mixr::base::IObject
{
   DECLARE_SUBCLASS(Base, mixr::base::IObject)

public:
   Base();

private:
   // slot table helper methods
   bool setSlotSeed(const mixr::base::INumber* const);
};

#endif
