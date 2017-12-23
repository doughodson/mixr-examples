
#ifndef __TestRotator_H__
#define __TestRotator_H__

#include "mixr/graphics/Graphic.hpp"

//------------------------------------------------------------------------------
// Class: TestRotator
//------------------------------------------------------------------------------
class TestRotator final: public mixr::graphics::Graphic
{
   DECLARE_SUBCLASS(TestRotator, mixr::graphics::Graphic)

public:
    TestRotator();

    void drawFunc() final;
    void updateData(const double dt = 0.0) final;

private:
    double t1Pos{};
    double t1Rate{0.5};
    double t2Pos{};
    double t2Rate{0.7};
    double t3Pos{};
    double t3Rate{0.3};
    double rotate{};
    double rotateRate{20};
    GLfloat light_position[4]{};
    int count{};
};

#endif
