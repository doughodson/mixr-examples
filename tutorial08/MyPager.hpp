
#ifndef __MyPager_HPP__
#define __MyPager_HPP__

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
