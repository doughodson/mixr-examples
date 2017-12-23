
#ifndef __TestOne_H__
#define __TestOne_H__

#include "mixr/graphics/Graphic.hpp"
#include <array>

namespace mixr {
namespace base { class Angle; class Number; }
}

//------------------------------------------------------------------------------
// Class: TestOne
//
// Description: Move within a user defined box displaying a trail
//------------------------------------------------------------------------------
class TestOne final: public mixr::graphics::Graphic
{
    DECLARE_SUBCLASS(TestOne, mixr::graphics::Graphic)

public:
    TestOne();

    void getPosition(double& xx, double& yy) const             { xx = xPos; yy = yPos; }
    void setPosition(const double xx, const double yy)         { xPos = xx; yPos = yy; }
    bool realSpeed(const mixr::base::Number* const rsobj);
    bool setAngle(mixr::base::Angle* saobj);
    bool setAngle(const mixr::base::Number* const saobj);

    double leftLimit() const                { return left; }
    void leftLimit(const double ll)         { left = ll; }

    double rightLimit() const               { return right; }
    void rightLimit(const double rr)        { right = rr; }

    double bottomLimit() const              { return bottom; }
    void bottomLimit(const double bb)       { bottom = bb; }

    double topLimit() const                 { return top; }
    void topLimit(const double tt)          { top = tt; }

    void setStartAngle(const double deg);
    void setSpeed(const double xx);

    void drawFunc() final;

    void updateTC(const double dt = 0.0) final;
    void updateData(const double dt = 0.0) final;
    bool event(const int event, mixr::base::Object* const obj = nullptr) final;
    void reset() final;

private:
    static const int maxHist{10};

    double left{-10.0}, right{10.0};               // X limits
    double bottom{-10.0}, top{10.0};               // Y limits
    double xPos{}, yPos{};                         // Position
    double xOld{}, yOld{};                         // Previous Position
    double dx{}, dy{};                             // Delta position
    double speed{10.0};                            // Speed
    double sangle{};                               // Starting angle (radians)
    std::array<mixr::base::Vec2d, maxHist> trail;  // Display trail
    int nTrails{};                                 // Trail size
    int index{};                                   // Trail index
    mixr::base::Angle* iangle{};                   // Input angle
};

#endif
