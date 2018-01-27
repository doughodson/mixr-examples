
#include "TdAzPtr.hpp"
#include "mixr/base/numeric/Number.hpp"
#include <iostream>

using namespace mixr;

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(TdAzPtr, "TdAzPtr")
EMPTY_DELETEDATA(TdAzPtr)

TdAzPtr::TdAzPtr()
{
    STANDARD_CONSTRUCTOR()
}

void TdAzPtr::copyData(const TdAzPtr& org, const bool)
{
    BaseClass::copyData(org);
    azimuth = 0.0;
}

//------------------------------------------------------------------------------
// event() -- default event handler
//------------------------------------------------------------------------------
bool TdAzPtr::event(const int event, base::Object* const obj)
{
    bool used{};

    if (event == UPDATE_VALUE)
    {
        const auto num = dynamic_cast<const base::Number*>(obj);
        if (num != nullptr) {
            azimuth = num->to_double();
            used = true;
        }
    }

    if (!used)
    {
        // Otherwise, pass key events up to our base class
        used = BaseClass::event(event, obj);
    }

    return used;
}

void TdAzPtr::draw()
{
   if (isVisible())  {
       lcSaveMatrix();
       lcTranslate( azimuth, 0.0 );
       BaseClass::draw();
       lcRestoreMatrix();
   }
}
