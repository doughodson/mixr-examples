
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
class MyComp : public mixr::base::Component
{
   DECLARE_SUBCLASS(MyComp, mixr::base::Component)

public:
   MyComp();

   // data access functions
   bool setStr(const mixr::base::String* const);
   const mixr::base::String* getStr() const;

   virtual void reset() override;
   virtual void updateTC(const double dt = 0.0) override;
   virtual void updateData(const double dt = 0.0) override;

private:
   const mixr::base::String* str {};

private:
   // slot table helper methods
   bool setSlotStr(const mixr::base::String* const);
};

#endif
