//------------------------------------------------------------------------------
// Test object Meta-Object capabilities
//------------------------------------------------------------------------------

#include <iostream>

#include "mixr/base/MetaObject.hpp"

#include "mixr/base/numeric/Decibel.hpp"
#include "mixr/base/colors/IColor.hpp"
#include "mixr/base/Matrix.hpp"

void printMetadata(const mixr::base::MetaObject* metaObject)
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

   const auto db = new mixr::base::Decibel();
   printMetadata(mixr::base::Decibel::getMetaObject());

   const auto c1 = new mixr::base::IColor();
   const auto c2 = new mixr::base::IColor();
   const auto c3 = new mixr::base::IColor();
   c2->unref();
   printMetadata(mixr::base::IColor::getMetaObject());

   const auto matrix1 = new mixr::base::Matrix();
   printMetadata(mixr::base::Matrix::getMetaObject());

   return 0;
}
