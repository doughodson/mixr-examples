
#include "TestStation.hpp"
#include "Display.hpp"

#include "mxrp/models/player/Player.hpp"
#include "mxrp/models/system/Gimbal.hpp"

#include "mxrp/simulation/Simulation.hpp"

#include "mxrp/base/Identifier.hpp"
#include "mxrp/base/Boolean.hpp"
#include "mxrp/base/Pair.hpp"
#include "mxrp/base/PairStream.hpp"
#include "mxrp/base/units/Angles.hpp"

using namespace oe;

IMPLEMENT_SUBCLASS(TestStation, "TestStation")
EMPTY_SERIALIZER(TestStation)
EMPTY_DELETEDATA(TestStation)

// slot table for this class type
BEGIN_SLOTTABLE(TestStation)
    "display",
END_SLOTTABLE(TestStation)

//  Map slot table to handles
BEGIN_SLOT_MAP(TestStation)
   ON_SLOT(1, setDisplay, Display)
END_SLOT_MAP()

TestStation::TestStation()
{
    STANDARD_CONSTRUCTOR()

    display = nullptr;
    displayInit = false;
}

void TestStation::copyData(const TestStation& org, const bool)
{
    BaseClass::copyData(org);

    display = nullptr;
    displayInit = false;
}

void TestStation::updateTC(const double dt)
{
   BaseClass::updateTC(dt);

   if (display != nullptr) display->updateTC(dt);
}

void TestStation::reset()
{
    BaseClass::reset();
    if (!displayInit && display != nullptr) {
        display->createWindow();
        display->focus(display);
        displayInit = true;
    }
}

//------------------------------------------------------------------------------
// setDisplay() -- Set the Display
//------------------------------------------------------------------------------
bool TestStation::setDisplay(Display* const d)
{
    display = d;
    display->container(this);
    return true;
}

