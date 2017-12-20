
#ifndef __TdAzPtr_H__
#define __TdAzPtr_H__

#include "mixr/graphics/Graphic.hpp"

//------------------------------------------------------------------------------
// Class: TdAzPtr
//
// Description: Test Display Azimuth Pointer
//------------------------------------------------------------------------------
class TdAzPtr final: public mixr::graphics::Graphic
{
    DECLARE_SUBCLASS(TdAzPtr, mixr::graphics::Graphic)

public:
    TdAzPtr();

    bool event(const int event, mixr::base::Object* const obj = nullptr) final;
    void draw() final;

private:
    double azimuth{};
};

#endif
