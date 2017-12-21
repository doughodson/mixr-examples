
#include "TdAzPtr.hpp"
#include "mixr/base/numeric/Number.hpp"
#include "mixr/base/units/angle_utils.hpp"

namespace mixr {
namespace xpanel {

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(TdAzPtr,"TdAzPtr")
EMPTY_DELETEDATA(TdAzPtr)

BEGIN_EVENT_HANDLER(TdAzPtr)
    ON_EVENT_OBJ(UPDATE_VALUE, onUpdateValue, base::Number)
END_EVENT_HANDLER()

TdAzPtr::TdAzPtr()
{
    STANDARD_CONSTRUCTOR()
}

void TdAzPtr::copyData(const TdAzPtr& org, const bool)
{
    BaseClass::copyData(org);
    azimuth = org.azimuth;
}

double TdAzPtr::getAzimuth() const
{
   return azimuth;
}

bool TdAzPtr::setAzimuth(const double v)
{
   azimuth = base::angle::aepcdDeg(v);
   return true;
}

//------------------------------------------------------------------------------
// Event handlers
//------------------------------------------------------------------------------
bool TdAzPtr::onUpdateValue(const base::Number* const msg)
{
    bool ok{};
    if (msg != nullptr) {
      ok = setAzimuth(msg->getReal());
    }
    return ok;
}

//------------------------------------------------------------------------------
// Translate in X by the azimuth angle and draw.
//------------------------------------------------------------------------------
void TdAzPtr::draw()
{
   if (isVisible())  {
       lcSaveMatrix();
       lcTranslate( azimuth/30.0f, 0.0 );
       graphics::Graphic::draw();
       lcRestoreMatrix();
   }
}

}
}
