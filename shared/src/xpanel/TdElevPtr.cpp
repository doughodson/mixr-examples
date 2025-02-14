
#include "shared/xpanel/TdElevPtr.hpp"

#include "mixr/base/numeric/INumber.hpp"
#include "mixr/base/units/util/angle_utils.hpp"

namespace mixr {
namespace xpanel {

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(TdElevPtr, "TdElevPtr")
EMPTY_DELETEDATA(TdElevPtr)

BEGIN_EVENT_HANDLER(TdElevPtr)
    ON_EVENT_OBJ(UPDATE_VALUE, onUpdateValue, base::INumber)
END_EVENT_HANDLER()

TdElevPtr::TdElevPtr()
{
    STANDARD_CONSTRUCTOR()
}

void TdElevPtr::copyData(const TdElevPtr& org, const bool)
{
    BaseClass::copyData(org);
    elev = org.elev;
}

//------------------------------------------------------------------------------
// Get & Set functions
//------------------------------------------------------------------------------
double TdElevPtr::getElevation() const
{
   return elev;
}

bool TdElevPtr::setElevation(const double v)
{
   elev = base::angle::aepcdDeg(v);
   return true;
}

//------------------------------------------------------------------------------
// Event handlers
//------------------------------------------------------------------------------
bool TdElevPtr::onUpdateValue(const base::INumber* const msg)
{
    bool ok{};
    if (msg != nullptr) {
      ok = setElevation(msg->asDouble());
    }
    return ok;
}

//------------------------------------------------------------------------------
// Translate in Y by the elevation angle and draw.
//------------------------------------------------------------------------------
void TdElevPtr::draw()
{
   if (isVisible())  {
       lcSaveMatrix();
       lcTranslate( 0.0, elev/30.0f );
       graphics::Graphic::draw();
       lcRestoreMatrix();
   }
}

}
}
