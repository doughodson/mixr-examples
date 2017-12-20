
#ifndef __MyPager_H__
#define __MyPager_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: MyPager
// Description: Example pager
//------------------------------------------------------------------------------
class MyPager final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(MyPager, mixr::graphics::Page)

public:
   MyPager();

   bool onEntry() final;
};

#endif
