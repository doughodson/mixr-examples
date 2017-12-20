//------------------------------------------------------------------------------
// Test template class creation and functionality
//------------------------------------------------------------------------------

#include <iostream>

#include "linked_list.hpp"
#include "mixr/base/colors/Color.hpp"

int main(int argc, char**)
{
   std::cout << "Test templates" << std::endl;

   const auto colorList = new mixr::base::LinkedList<mixr::base::Color>;

   if (colorList->isEmpty()) { std::cout << "List is empty\n"; }

   std::cout << "# entries : " << colorList->entries() << std::endl;

   const auto c1 = new mixr::base::Color();

   colorList->put(c1);

   std::cout << "# entries : " << colorList->entries() << std::endl;

   return 0;
}

