
#ifndef __Display_H__
#define __Display_H__

#include "mixr/ui/glut/GlutDisplay.hpp"
#include <array>
#include <string>

namespace mixr {
namespace base { class Color; }
namespace graphics { class Material; }
}

class TestObject;

//------------------------------------------------------------------------------
// Class: Display
// Description: This class will send down data to it's components in different
// ways, showing how the SendData class works and testing our send commands.
//------------------------------------------------------------------------------
class Display final: public mixr::glut::GlutDisplay
{
   DECLARE_SUBCLASS(Display, mixr::glut::GlutDisplay)

public:
   Display();

   void updateData(const double dt = 0.0) final;

private:
    // boolean
    bool myBool{};
    SendData boolSD;

    // integer
    int myInt{};
    SendData intSD;

    // float
    float myFloat{};
    SendData floatSD;

    // double
    double myDouble{};
    SendData doubleSD;

    // object
    TestObject* obj{};
    SendData objSD;

    // characters
    std::string myChar = "ASCII";
    SendData charSD;

    mixr::base::Color* myColor{};
    SendData colorSD;

    static const int MAX_MATERIALS{3};
    std::array<mixr::graphics::Material*, MAX_MATERIALS> materials{};
    std::array<SendData, MAX_MATERIALS> materialSD;
    std::array<mixr::base::Vec3d, MAX_MATERIALS> diffColorRate;

    std::array<double, MAX_MATERIALS> rotations{};
    std::array<SendData, MAX_MATERIALS> rotationsSD{};

    int counter{};    // to slowly increment our numbers
};

#endif
