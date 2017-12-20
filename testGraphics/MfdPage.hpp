
#ifndef __MfdPage_H__
#define __MfdPage_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: MfdPage
//
// Description: Example MFD page
//------------------------------------------------------------------------------
class MfdPage final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(MfdPage, mixr::graphics::Page)

public:
   MfdPage();

   bool onEntry() final;

   bool event(const int event, mixr::base::Object* const obj = nullptr) final;
   void updateData(const double dt = 0.0) final;

private:
   double rotate{};
   double rotateRate{5.0};
   SendData rSD;
};

#endif
