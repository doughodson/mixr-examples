
#include "TestTwo.hpp"

#include "mixr/base/numeric/INumber.hpp"

using namespace mixr;

IMPLEMENT_SUBCLASS(TestTwo, "TestTwo")
EMPTY_DELETEDATA(TestTwo)

BEGIN_SLOTTABLE(TestTwo)
    "v1",       // V1 initial value
    "v1Rate",   // V1 rate
    "v1Max",    // V1 max value
    "v1Min",    // V1 min value
    "v2",       // V2 initial value
    "v2Rate",   // V2 rate
    "v2Max",    // V2 max value
    "v2Min",    // V2 min value
END_SLOTTABLE(TestTwo)

BEGIN_SLOT_MAP(TestTwo)
    ON_SLOT(1, setV1,     base::INumber)
    ON_SLOT(2, setV1Rate, base::INumber)
    ON_SLOT(3, setV1Max,  base::INumber)
    ON_SLOT(4, setV1Min,  base::INumber)
    ON_SLOT(5, setV2,     base::INumber)
    ON_SLOT(6, setV2Rate, base::INumber)
    ON_SLOT(7, setV2Max,  base::INumber)
    ON_SLOT(8, setV2Min,  base::INumber)
END_SLOT_MAP()

BEGIN_EVENT_HANDLER(TestTwo)
END_EVENT_HANDLER()

TestTwo::TestTwo()
{
    STANDARD_CONSTRUCTOR()
    reset();
}

void TestTwo::copyData(const TestTwo& org, const bool)
{
    BaseClass::copyData(org);

    iv1 = org.iv1;
    iv1Rate = org.iv1Rate;
    v1Max = org.v1Max;
    v1Min = org.v1Min;

    iv2 = org.iv2;
    iv2Rate = org.iv2Rate;
    v2Max = org.v2Max;
    v2Min = org.v2Min;

    reset();
}

// reset member data to known state
void TestTwo::reset()
{
    v1     = iv1;
    v1Rate = iv1Rate;
    v1SD.empty();
    v1TitleSD.empty();

    v2     = iv2;
    v2Rate = iv2Rate;
    v2SD.empty();
    v2TitleSD.empty();
}

void TestTwo::updateTC(const double dt)
{
    // Update base classes stuff
    BaseClass::updateTC(dt);

    // Update V1
    v1 += v1Rate*dt;
    if (v1 > v1Max) {
        v1 = v1Max - (v1 - v1Max);
        v1Rate = -v1Rate;
    } else if (v1 < v1Min) {
        v1 = v1Min - (v1 - v1Min);
        v1Rate = -v1Rate;
    }

    // Update V2
    v2 += v2Rate*dt;
    if (v2 > v2Max) {
        v2 = v2Max - (v2 - v2Max);
        v2Rate = -v2Rate;
    } else if (v2 < v2Min) {
        v2 = v2Min - (v2 - v2Min);
        v2Rate = -v2Rate;
    }
}

void TestTwo::updateData(const double dt)
{
    // Update base classes stuff
    BaseClass::updateData(dt);

    int i{1};
    if (v2 < 0) i++;
    if (v2Rate < 0) i += 2;

    send( "v1", UPDATE_VALUE, v1, v1SD );
    send( "v1Title", SELECT, (v1Rate < 0), v1TitleSD);
    send( "v2", UPDATE_VALUE, v2, v2SD );
    send( "v2Title", SELECT, i, v2TitleSD);
}

//------------------------------------------------------------------------------
// setV1() --
//------------------------------------------------------------------------------
bool TestTwo::setV1(const base::INumber* const sv1obj)
{
    if (sv1obj != nullptr) iv1 = sv1obj->asDouble();
    return true;
}

//------------------------------------------------------------------------------
// setV1Rate() --
//------------------------------------------------------------------------------
bool TestTwo::setV1Rate(const base::INumber* const sv1robj)
{
    if (sv1robj != nullptr) iv1Rate = sv1robj->asDouble();
    return true;
}

//------------------------------------------------------------------------------
// setV1Max() --
//------------------------------------------------------------------------------
bool TestTwo::setV1Max(const base::INumber* const sv1mobj)
{
    if (sv1mobj != nullptr) v1Max = sv1mobj->asDouble();
    return true;
}

//------------------------------------------------------------------------------
// setV1Min() --
//------------------------------------------------------------------------------
bool TestTwo::setV1Min(const base::INumber* const sv1miobj)
{
    if (sv1miobj != nullptr) v1Min = sv1miobj->asDouble();
    return true;
}

//------------------------------------------------------------------------------
// setV2() --
//------------------------------------------------------------------------------
bool TestTwo::setV2(const base::INumber* const sv2obj)
{
    if (sv2obj != nullptr) iv2 = sv2obj->asDouble();
    return true;
}

//------------------------------------------------------------------------------
// setV2Rate() --
//------------------------------------------------------------------------------
bool TestTwo::setV2Rate(const base::INumber* const sv2robj)
{
    if (sv2robj != nullptr) iv2Rate = sv2robj->asDouble();
    return true;
}

//------------------------------------------------------------------------------
// setV2Max() --
//------------------------------------------------------------------------------
bool TestTwo::setV2Max(const base::INumber* const sv2mobj)
{
    if (sv2mobj != nullptr) v2Max = sv2mobj->asDouble();
    return true;
}

//------------------------------------------------------------------------------
// setV2Min() --
//------------------------------------------------------------------------------
bool TestTwo::setV2Min(const base::INumber* const sv2miobj)
{
    if (sv2miobj != nullptr) v2Min = sv2miobj->asDouble();
    return true;
}
