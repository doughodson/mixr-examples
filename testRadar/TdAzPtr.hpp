
#ifndef __TdAzPtr_H__
#define __TdAzPtr_H__

#include "mxrp/graphics/Graphic.hpp"

namespace mxrp {
namespace base { class Number; }
}

//------------------------------------------------------------------------------
// Class: TdAzPtr
// Description: Display an azimuth pointer.  Before drawing, we position the
//              pointer based our received azimuth angle.  The shape of the
//              pointer is defined by our graphic subcomponents.
//
// Notes:
//    1) Azimuth is in degrees.
//    2) Movement is limited to +/- 30 degrees, which is scaled to +/- 1.0 in
//       world coordinates.
//
// Factory name: TdAzPtr
//
// Events:
//    UPDATE_VALUE  <Number>  ! azimuth angle (degs)
//------------------------------------------------------------------------------
class TdAzPtr : public mxrp::graphics::Graphic
{
   DECLARE_SUBCLASS(TdAzPtr, mxrp::graphics::Graphic)

public:
   TdAzPtr();

   double getAzimuth() const;       // degs
   bool setAzimuth(const double);   // degs

   virtual void draw() override;

   virtual bool event(const int event, mxrp::base::Object* const obj = nullptr) override;

private:
   bool onUpdateValue(const mxrp::base::Number* const msg);

   double azimuth {};  // (degs)
};

#endif
