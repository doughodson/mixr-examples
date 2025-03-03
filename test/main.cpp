
// factories
#include "mixr/base/factory.hpp"

#include <string>
#include <iostream>

void testReadouts();
void testFileReader();

// factory to support object creation for all tests
mixr::base::IObject* factory(const std::string& name)
{
   // base library
   mixr::base::IObject* obj{mixr::base::factory(name)};
   return obj;
}

int main(int argc, char* argv[])
{
   testReadouts();
   return 0;
}
