
#ifndef __TdElevPtr_HPP__
#define __TdElevPtr_HPP__

#include "mixr/graphics/Graphic.hpp"

namespace mixr {
namespace base { class INumber; }
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

    bool event(const int event, mixr::base::IObject* const obj = nullptr) final;
    void draw() final;

    //event handler macro functions
    bool onUpdateValue(const mixr::base::INumber* const ouvobj);

private:
    double elev {};
};

#endif
