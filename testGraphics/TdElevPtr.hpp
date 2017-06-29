
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
class TdElevPtr : public mixr::graphics::Graphic
{
    DECLARE_SUBCLASS(TdElevPtr, mixr::graphics::Graphic)

public:
    TdElevPtr();

    virtual bool event(const int event, mixr::base::Object* const obj = nullptr) override;
    virtual void draw() override;

    //event handler macro functions
    virtual bool onUpdateValue(const mixr::base::Number* const ouvobj);

private:
    double elev {};
};

#endif
