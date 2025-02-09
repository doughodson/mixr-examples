
#ifndef __EventDisplay_HPP__
#define __EventDisplay_HPP__

#include "mixr/ui/glut/GlutDisplay.hpp"
#include <array>
#include <string>

namespace mixr {
namespace base { class IColor; }
namespace graphics { class Material; }
}

class TestObject;

//------------------------------------------------------------------------------
// Class: EventDisplay
// Description: This class extends a GlutDisplay with special event creation
// and distribution to test event handling capabilities of the Component
// class
//------------------------------------------------------------------------------
class EventDisplay final: public mixr::glut::GlutDisplay
{
   DECLARE_SUBCLASS(EventDisplay, mixr::glut::GlutDisplay)

public:
   EventDisplay();

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
    std::string myChar{"ASCII"};
    SendData charSD;

    mixr::base::IColor* myColor{};
    SendData colorSD;

    static const int MAX_MATERIALS{3};
    std::array<mixr::graphics::Material*, MAX_MATERIALS> materials{};
    std::array<SendData, MAX_MATERIALS> materialSD;
    std::array<mixr::base::Vec3d, MAX_MATERIALS> diffColorRate;

    std::array<double, MAX_MATERIALS> rotations{};
    std::array<SendData, MAX_MATERIALS> rotationsSD{};
};

#endif
