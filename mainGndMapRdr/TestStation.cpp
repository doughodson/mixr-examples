
#include "TestStation.hpp"
#include "Display.hpp"

#include "mixr/models/player/Player.hpp"
#include "mixr/models/system/Gimbal.hpp"

#include "mixr/simulation/Simulation.hpp"

#include "mixr/base/numeric/Boolean.hpp"

#include "mixr/base/Identifier.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"

#include "mixr/base/units/Angles.hpp"

using namespace mixr;

IMPLEMENT_SUBCLASS(TestStation, "TestStation")
EMPTY_DELETEDATA(TestStation)

BEGIN_SLOTTABLE(TestStation)
    "display",
END_SLOTTABLE(TestStation)

BEGIN_SLOT_MAP(TestStation)
   ON_SLOT(1, setSlotDisplay, Display)
END_SLOT_MAP()

TestStation::TestStation()
{
    STANDARD_CONSTRUCTOR()
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

bool TestStation::setSlotDisplay(Display* const d)
{
    display = d;
    display->container(this);
    return true;
}

