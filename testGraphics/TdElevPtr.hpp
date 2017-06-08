
#ifndef __TdElevPtr_H__
#define __TdElevPtr_H__

#include "mxrp/graphics/Graphic.hpp"

namespace mxrp {
   namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: TdElevPtr
//
// Description: Test Display Elevation Pointer
//------------------------------------------------------------------------------
class TdElevPtr : public mxrp::graphics::Graphic
{
    DECLARE_SUBCLASS(TdElevPtr, mxrp::graphics::Graphic)

public:
    TdElevPtr();

    virtual bool event(const int event, mxrp::base::Object* const obj = nullptr) override;
    virtual void draw() override;

    //event handler macro functions
    virtual bool onUpdateValue(const mxrp::base::Number* const ouvobj);

private:
    double elev {};
};

#endif
