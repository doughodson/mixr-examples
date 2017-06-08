
#ifndef __TdAzPtr_H__
#define __TdAzPtr_H__

#include "mxrp/graphics/Graphic.hpp"

//------------------------------------------------------------------------------
// Class: TdAzPtr
//
// Description: Test Display Azimuth Pointer
//------------------------------------------------------------------------------
class TdAzPtr : public mxrp::graphics::Graphic
{
    DECLARE_SUBCLASS(TdAzPtr, mxrp::graphics::Graphic)

public:
    TdAzPtr();

    virtual bool event(const int event, mxrp::base::Object* const obj = nullptr) override;
    virtual void draw() override;

private:
    double azimuth {};
};

#endif
