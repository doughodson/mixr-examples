
#include "TdElevPtr.h"
#include "openeaagles/basic/Number.h"

namespace oe {
namespace example {

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(TdElevPtr,"TdElevPtr")
EMPTY_SERIALIZER(TdElevPtr)

//------------------------------------------------------------------------------
// Constructor(s)
//------------------------------------------------------------------------------
TdElevPtr::TdElevPtr()
{
    STANDARD_CONSTRUCTOR()
    elev = 0.0;
}

//------------------------------------------------------------------------------
// copyData(), deleteData() -- copy (delete) member data
//------------------------------------------------------------------------------
void TdElevPtr::copyData(const TdElevPtr& org, const bool)
{
    BaseClass::copyData(org);
    elev = 0.0;
}

EMPTY_DELETEDATA(TdElevPtr)

//------------------------------------------------------------------------------
// macro event handler - replaces event() function
//------------------------------------------------------------------------------
BEGIN_EVENT_HANDLER(TdElevPtr)
    ON_EVENT_OBJ(UPDATE_VALUE, onUpdateValue, basic::Number)
END_EVENT_HANDLER()


//------------------------------------------------------------------------------
// draw() -- draw the pointer
//------------------------------------------------------------------------------
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
bool TdElevPtr::onUpdateValue(const basic::Number* const ouvobj)
{
    if (ouvobj != nullptr) elev = ouvobj->getReal();
    return true;
}

} // End example namespace
} // End oe namespace
