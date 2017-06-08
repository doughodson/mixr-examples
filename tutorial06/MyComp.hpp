
#ifndef __MyComp_H__
#define __MyComp_H__

#include "mxrp/base/Component.hpp"

namespace mxrp {
namespace base { class String; }
}

//------------------------------------------------------------------------------
// Class: MyComp
// Description: example class
//------------------------------------------------------------------------------
class MyComp : public mxrp::base::Component
{
   DECLARE_SUBCLASS(MyComp, mxrp::base::Component)

public:
   MyComp();

   // data access functions
   bool setStr(const mxrp::base::String* const);
   const mxrp::base::String* getStr() const;

   // slot table functions
   bool setSlotStr(const mxrp::base::String* const);

   virtual void reset() override;
   virtual void updateTC(const double dt = 0.0) override;
   virtual void updateData(const double dt = 0.0) override;

private:
   const mxrp::base::String* str {};
};

#endif
