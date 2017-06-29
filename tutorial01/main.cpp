
#include <iostream>

#include "mixr/base/String.hpp"

int main(int argc, char* argv[])
{
   const auto str = new mixr::base::String("Hello world\n");

   std::cout << str->getString();

   str->setStr("Goodbye world\n");

   std::cout << str->getString();

   str->unref();

   return 0;
}
