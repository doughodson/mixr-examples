
#ifndef __MyPager_H__
#define __MyPager_H__

#include "mxrp/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: MyPager
// Description: Example pager
//------------------------------------------------------------------------------
class MyPager : public mxrp::graphics::Page
{
   DECLARE_SUBCLASS(MyPager, mxrp::graphics::Page)

public:
   MyPager();

   virtual bool onEntry() override;
};

#endif
