
#include "mixr/base/Object.hpp"

#include "builder.hpp"

void testFileReader()
{
   // default configuration filename
   std::string configFilename{"testFileReader.edl"};

   mixr::base::Object* obj = builder<mixr::base::Object*>(configFilename);

   return;
}

