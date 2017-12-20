
#ifndef __MyComp_H__
#define __MyComp_H__

#include "mixr/base/Component.hpp"

namespace mixr {
namespace base { class String; }
}

//------------------------------------------------------------------------------
// Class: MyComp
// Description: example class
//------------------------------------------------------------------------------
class MyComp final: public mixr::base::Component
{
   DECLARE_SUBCLASS(MyComp, mixr::base::Component)

public:
   MyComp();

   // data access functions
   bool setStr(const mixr::base::String* const);
   const mixr::base::String* getStr() const;

   void reset() final;
   void updateTC(const double dt = 0.0) final;
   void updateData(const double dt = 0.0) final;

private:
   const mixr::base::String* str{};

private:
   // slot table helper methods
   bool setSlotStr(const mixr::base::String* const);
};

#endif
