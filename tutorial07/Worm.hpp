#ifndef __Worm_H__
#define __Worm_H__

#include "mixr/graphics/Graphic.hpp"
#include <array>

namespace mixr {
namespace base { class Angle; class Number; }
}

//------------------------------------------------------------------------------
// Class: Worm
//
// Description: Move within a user defined box displaying a trail
//
// ( Worm selectName: 111 color: green speed: 10 startAngle: ( Degrees 30 ) )
//
//------------------------------------------------------------------------------
class Worm final: public mixr::graphics::Graphic
{
   DECLARE_SUBCLASS(Worm, mixr::graphics::Graphic)

public:
   Worm();

   void getPosition(double& xx, double& yy) const      { xx = xPos; yy = yPos; }
   void setPosition(const double xx, const double yy)  { xPos = xx; yPos = yy; }

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
   static const int MAX_HIST{10};

   double left{-10.0}, right{10.0};                // X limits
   double bottom{-10.0}, top{10.0};                // Y limits
   double xPos{}, yPos{};                          // Position
   double xOld{}, yOld{};                          // Previous Position
   double dx{}, dy{};                              // Delta position
   double speed{10.0};                             // Speed
   double sangle{};                                // Starting angle (radians)
   std::array<mixr::base::Vec2d, MAX_HIST> trail;  // Display trail
   int nTrails{};                                  // Trail size
   int index{};                                    // Trail index
   const mixr::base::Angle* iangle{};              // Input angle

private:
   // slot table helper methods
   bool setSlotSpeed(const mixr::base::Number* const);
   bool setSlotAngle(const mixr::base::Angle* const);
   bool setSlotAngle(const mixr::base::Number* const);
};

#endif
