
#ifndef __mixr_xpanel_TdAzPtr_HPP__
#define __mixr_xpanel_TdAzPtr_HPP__

#include "mixr/graphics/Graphic.hpp"

namespace mixr {
namespace base { class INumber; }
namespace xpanel {

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
// Events:
//    UPDATE_VALUE  <INumber>  ! azimuth angle (degs)
//------------------------------------------------------------------------------
class TdAzPtr final: public graphics::Graphic
{
   DECLARE_SUBCLASS(TdAzPtr, graphics::Graphic)

public:
   TdAzPtr();

   double getAzimuth() const;       // degs
   bool setAzimuth(const double);   // degs

   void draw() final;
   bool event(const int event, base::IObject* const obj = nullptr) final;

private:
   bool onUpdateValue(const base::INumber* const msg);

   double azimuth{};  // (degs)
};

}
}

#endif
