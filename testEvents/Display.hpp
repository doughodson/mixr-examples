
#ifndef __Display_H__
#define __Display_H__

#include "mxrp/gui/glut/GlutDisplay.hpp"
#include <array>
#include <string>

namespace mxrp {
namespace base { class Color; }
namespace graphics { class Material; }
}

class TestObject;

//------------------------------------------------------------------------------
// Class: Display
// Description: This class will send down data to it's components in different
// ways, showing how the SendData class works and testing our send commands.
//------------------------------------------------------------------------------
class Display : public mxrp::glut::GlutDisplay
{
   DECLARE_SUBCLASS(Display, mxrp::glut::GlutDisplay)

public:
   Display();

   virtual void updateData(const double dt = 0.0) override;

private:
    // boolean
    bool myBool {};
    SendData boolSD;

    // integer
    int myInt {};
    SendData intSD;

    // float
    float myFloat {};
    SendData floatSD;

    // double
    double myDouble {};
    SendData doubleSD;

    // object
    TestObject* obj {};
    SendData objSD;

    // characters
    std::string myChar = "ASCII";
    SendData charSD;

    mxrp::base::Color* myColor {};
    SendData colorSD;

    static const int MAX_MATERIALS = 3;
    std::array<mxrp::graphics::Material*, MAX_MATERIALS> materials {};
    std::array<SendData, MAX_MATERIALS> materialSD;
    std::array<mxrp::base::Vec3d, MAX_MATERIALS> diffColorRate;

    std::array<double, MAX_MATERIALS> rotations {};
    std::array<SendData, MAX_MATERIALS> rotationsSD {};

    int counter {};    // to slowly increment our numbers
};

#endif
