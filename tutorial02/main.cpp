
#include <iostream>

#include "Rng.hpp"

int main(int argc, char* argv[])
{
   std::cout << "Creating Rng object\n";
   const auto rng = new Rng();
   std::cout << "Rng object created\n";

   rng->setSeed(25);

   for (unsigned int i=0; i<10; i++)
      std::cout << rng->getNum() << std::endl;

   std::cout << "Unref'ing rng object\n";
   rng->unref();
   std::cout << "Rng object unrefed\n";

   return 0;
}
