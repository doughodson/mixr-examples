//------------------------------------------------------------------------------
// Test object Meta-Object capabilities
//------------------------------------------------------------------------------

#include <iostream>

#include "mxrp/base/MetaObject.hpp"

#include "mxrp/base/Decibel.hpp"
#include "mxrp/base/Color.hpp"
#include "mxrp/base/Matrix.hpp"

void printMetadata(const mxrp::base::MetaObject* metaObject)
{
   std::cout << "class name   : " << metaObject->getClassName()   << std::endl
             << "factory name : " << metaObject->getFactoryName() << std::endl
             << "count        : " << metaObject->count            << std::endl
             << "mc           : " << metaObject->mc               << std::endl
             << "tc           : " << metaObject->tc               << std::endl;
}

int main(int, char**)
{
   std::cout << "Testing object metadata capabilities" << std::endl;

   const auto db = new mxrp::base::Decibel();
   printMetadata(mxrp::base::Decibel::getMetaObject());

   const auto c1 = new mxrp::base::Color();
   const auto c2 = new mxrp::base::Color();
   const auto c3 = new mxrp::base::Color();
   c2->unref();
   printMetadata(mxrp::base::Color::getMetaObject());

   const auto matrix1 = new mxrp::base::Matrix();
   printMetadata(mxrp::base::Matrix::getMetaObject());

   return 0;
}
