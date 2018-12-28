
#include "TestObject.hpp"

#include "mixr/base/util/str_utils.hpp"

IMPLEMENT_SUBCLASS(TestObject, "TestObject")
EMPTY_SLOTTABLE(TestObject);
EMPTY_DELETEDATA(TestObject)

void TestObject::copyData(const TestObject& org, const bool)
{
    BaseClass::copyData(org);

    boolVal = org.boolVal;
    intVal = org.intVal;
    floatVal = org.floatVal;
    doubleVal = org.doubleVal;
    charVal = org.charVal;
}
