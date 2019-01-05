
#include "mixr/graphics/readouts/readout_utils.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace mixr;

void testNumberFormats()
{
   std::string example;
   bool postSign{};

   std::cout << std::endl;
   std::cout << "Number formats (Integer)\n";
   std::cout << "------------------------\n";

   example = "+0##";
   std::string format0{graphics::processInteger(graphics::DataType::number, example, &postSign)};
   std::cout << "Number: " << example << " format: " << format0 << std::endl;

   std::string format1{graphics::processInteger(graphics::DataType::octal, example, &postSign)};
   std::cout << "Number octal: " << example << " format: " << format1 << std::endl;

   std::string format2{graphics::processInteger(graphics::DataType::hex, example, &postSign)};
   std::cout << "Number hex: " << example << " format: " << format2 << std::endl;

   std::cout << std::endl;
   std::cout << "Number formats (Float)\n";
   std::cout << "----------------------\n";

}

void testDirectionalFormats()
{
   std::string example;
   bool postSign{};

   std::cout << std::endl;
   std::cout << "Direction formats\n";
   std::cout << "-----------------\n";

   example = "+0DD@MM'SS.S";
   std::string format3{graphics::processDirection(graphics::DirMode::ddmmss, example, &postSign)};
   std::cout << "Directional: " << example << " format: " << format3 << std::endl;
}

void testTimeFormats()
{
   std::string example;
   bool postSign{};

   std::cout << std::endl;
   std::cout << "Time formats\n";
   std::cout << "------------\n";

   example = "HH:MM:SS";
   std::string format4{graphics::processTime(graphics::TimeMode::hhmmss, example, &postSign)};
   std::cout << "Time: " << example << " format: " << format4 << std::endl;
}

void testReadouts()
{
   testNumberFormats();
   testDirectionalFormats();
   testTimeFormats();
}
