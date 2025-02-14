
#include "TdElevPtr.hpp"
#include "mixr/base/numeric/INumber.hpp"
#include <iostream>

using namespace mixr;

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(TdElevPtr, "TdElevPtr")
EMPTY_DELETEDATA(TdElevPtr)

TdElevPtr::TdElevPtr()
{
    STANDARD_CONSTRUCTOR()
}

void TdElevPtr::copyData(const TdElevPtr& org, const bool)
{
    BaseClass::copyData(org);
    elev = 0.0;
}

BEGIN_EVENT_HANDLER(TdElevPtr)
    ON_EVENT_OBJ(UPDATE_VALUE, onUpdateValue, base::INumber)
END_EVENT_HANDLER()

void TdElevPtr::draw()
{
   if (isVisible())  {
       lcSaveMatrix();
       lcTranslate( 0.0, elev );
       BaseClass::draw();
       lcRestoreMatrix();
   }
}

//------------------------------------------------------------------------------
// onUpdateValue()-- event handler for an updated value
//------------------------------------------------------------------------------
bool TdElevPtr::onUpdateValue(const base::INumber* const ouvobj)
{
    if (ouvobj != nullptr) elev = ouvobj->asDouble();
    return true;
}
