
#ifndef __MyComp_HPP__
#define __MyComp_HPP__

#include "mixr/base/IComponent.hpp"

namespace mixr {
namespace base { class String; }
}

//------------------------------------------------------------------------------
// Class: MyComp
// Description: example class
//------------------------------------------------------------------------------
class MyComp final: public mixr::base::IComponent
{
   DECLARE_SUBCLASS(MyComp, mixr::base::IComponent)

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
