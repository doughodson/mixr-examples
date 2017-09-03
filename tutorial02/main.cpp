
#include <iostream>

#include "Rng.hpp"

int main(int argc, char* argv[])
{
   std::cout << "Creating Rng object" << std::endl;
   const auto rng = new Rng();
   std::cout << "Rng object created" << std::endl;

   rng->setSeed(25);

   for (int i=0; i<10; i++)
      std::cout << rng->num() << std::endl;

   std::cout << "Unref'ing rng object\n";
   rng->unref();
   std::cout << "Rng object unref'd\n";

   return 0;
}
