
#include <iostream>

#include "Random.h"

namespace oe {
namespace tutorial {

int main(int argc, char* argv[])
{
   std::cout << "Creating Random object\n";
   Random* rgen = new Random();
   std::cout << "Random object created\n";

   rgen->setSeed(25);

   for(unsigned int i=0; i<10; i++)
      std::cout << rgen->getNum() << std::endl;

   std::cout << "Unref'ing random object\n";
   rgen->unref();
   std::cout << "Random object unrefed\n";

   return 0;
}

} // namespace tutorial
} // namespace oe

//-----------------------------------------------------------------------------
// main() -- Main routine
//-----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
   oe::tutorial::main(argc, argv);
}

