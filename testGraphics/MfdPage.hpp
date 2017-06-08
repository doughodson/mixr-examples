
#ifndef __MfdPage_H__
#define __MfdPage_H__

#include "mxrp/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: MfdPage
//
// Description: Example MFD page
//------------------------------------------------------------------------------
class MfdPage : public mxrp::graphics::Page
{
   DECLARE_SUBCLASS(MfdPage, mxrp::graphics::Page)

public:
   MfdPage();

   virtual bool onEntry() override;

   virtual bool event(const int event, mxrp::base::Object* const obj = nullptr) override;
   virtual void updateData(const double dt = 0.0) override;

private:
   double rotate {};
   double rotateRate {5.0};
   SendData rSD;
};

#endif
