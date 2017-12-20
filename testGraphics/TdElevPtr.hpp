
#ifndef __TdElevPtr_H__
#define __TdElevPtr_H__

#include "mixr/graphics/Graphic.hpp"

namespace mixr {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: TdElevPtr
//
// Description: Test Display Elevation Pointer
//------------------------------------------------------------------------------
class TdElevPtr final: public mixr::graphics::Graphic
{
    DECLARE_SUBCLASS(TdElevPtr, mixr::graphics::Graphic)

public:
    TdElevPtr();

    bool event(const int event, mixr::base::Object* const obj = nullptr) final;
    void draw() final;

    //event handler macro functions
    bool onUpdateValue(const mixr::base::Number* const ouvobj);

private:
    double elev {};
};

#endif
