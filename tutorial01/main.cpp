
#include <iostream>

#include "openeaagles/base/String.h"

namespace tutorial {

int main(int argc, char* argv[])
{
   oe::base::String* str = new oe::base::String("Hello world\n");

   std::cout << str->getString();

   str->setStr("Goodbye world\n");

   std::cout << str->getString();

   str->unref();

   return 0;
}

}

//
int main(int argc, char* argv[])
{
   tutorial::main(argc, argv);
}
