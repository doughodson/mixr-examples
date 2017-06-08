
#include "MyPager.hpp"

#include "mxrp/base/Pair.hpp"
#include "mxrp/base/PairStream.hpp"

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(MyPager, "MyPager")
EMPTY_COPYDATA(MyPager)
EMPTY_DELETEDATA(MyPager)
EMPTY_SERIALIZER(MyPager)

MyPager::MyPager()
{
   STANDARD_CONSTRUCTOR()
}

bool MyPager::onEntry()
{
   mxrp::base::PairStream* components = getComponents();
   if (components != nullptr) {
      mxrp::base::List::Item* item = components->getFirstItem();
      while (item != nullptr) {
         const auto pair = static_cast<mxrp::base::Pair*>(item->getValue());
         const auto cp = static_cast<mxrp::base::Component*>(pair->object());
         if (cp != nullptr)
            cp->event(RESET_EVENT);
         item = item->getNext();
      }
   }
   return true;
}
