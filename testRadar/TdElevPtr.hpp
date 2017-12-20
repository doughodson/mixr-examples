
#ifndef __TdElevPtr_H__
#define __TdElevPtr_H__

#include "mixr/graphics/Graphic.hpp"

//------------------------------------------------------------------------------
// Class: TdElevPtr
// Description: Display an elevation pointer.  Before drawing, we position the
//              pointer based our received elevation angle.  The shape of the
//              pointer is defined by our graphic subcomponents.
//
// Notes:
//    1) Elevation is in degrees.
//    2) Movement is limited to +/- 30 degrees, which is scaled to +/- 1.0 in
//       world coordinates.
//
// Factory name: TdElevPtr
// Events:
//    UPDATE_VALUE  <Number>  ! elevation angle (degs)
//------------------------------------------------------------------------------
namespace mixr {
namespace base { class Number; }
}

class TdElevPtr final: public mixr::graphics::Graphic
{
   DECLARE_SUBCLASS(TdElevPtr, mixr::graphics::Graphic)

public:
   TdElevPtr();

   double getElevation() const;     // degs
   bool setElevation(const double); // degs

   void draw() final;

   bool event(const int event, mixr::base::Object* const obj = nullptr) final;

private:
   bool onUpdateValue(const mixr::base::Number* const);

   double elev{};  // (degs)
};

#endif
