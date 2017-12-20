
#include "TestOne.hpp"
#include "mixr/base/units/Angles.hpp"

#include <cmath>

using namespace mixr;

IMPLEMENT_SUBCLASS(TestOne, "TestOne")
EMPTY_DELETEDATA(TestOne)

BEGIN_SLOTTABLE(TestOne)
    "speed",       // speed
    "startAngle",  // starting angle (off X axis)
END_SLOTTABLE(TestOne)

BEGIN_SLOT_MAP(TestOne)
    ON_SLOT(1, realSpeed, base::Number)
    ON_SLOT(2, setAngle, base::Angle)
    ON_SLOT(2, setAngle, base::Number)
END_SLOT_MAP()

BEGIN_EVENT_HANDLER(TestOne)
END_EVENT_HANDLER()

TestOne::TestOne()
{
    STANDARD_CONSTRUCTOR()
    setSpeed(10.0);
}

void TestOne::copyData(const TestOne& org, const bool)
{
    int i{};

    BaseClass::copyData(org);

    if (iangle != nullptr) iangle->unref();
    if (org.iangle != nullptr) iangle = org.iangle->clone();
    else iangle = nullptr;

    left = org.left;
    right = org.right;
    bottom = org.bottom;
    top = org.top;
    xPos = org.xPos;
    yPos = org.yPos;
    xOld = org.xOld;
    yOld = org.yOld;
    dx = org.dx;
    dy = org.dy;
    speed = org.speed;
    sangle = org.sangle;
    nTrails = org.nTrails;
    index   = org.index;
    for (i = 0; i < nTrails; i++) {
        trail[i] = org.trail[i];
    }
}

void TestOne::reset()
{
    BaseClass::reset();
    xPos = 0;
    yPos =0;
    nTrails = 0;
    if (iangle != nullptr) {
        base::Radians radians;
        setStartAngle(static_cast<double>(radians.convert(*iangle)));
    }
}

//------------------------------------------------------------------------------
// setStartAngle() -- set starting angle
//------------------------------------------------------------------------------
void TestOne::setStartAngle(const double radians)
{
    sangle = radians;
    dx = std::cos(sangle) * speed;
    dy = std::sin(sangle) * speed;
}

//------------------------------------------------------------------------------
// setSpeed() -- set speed
//------------------------------------------------------------------------------
void TestOne::setSpeed(const double xx)
{
    speed = xx;
    dx = std::cos(sangle) * speed;
    dy = std::sin(sangle) * speed;
}

//------------------------------------------------------------------------------
// updateTC() -- update time critical stuff here
//------------------------------------------------------------------------------
void TestOne::updateTC(const double dt)
{
    // Update base classes stuff
    BaseClass::updateTC(dt);

    // ---
    // Move
    // ---

    xPos += dx*dt;
    if (xPos > right) {
        xPos = right - (xPos - right);
        dx = -dx;
    } else if (xPos < left) {
        xPos = left - (xPos - left);
        dx = -dx;
    }

    yPos += dy*dt;
    if (yPos > top) {
        yPos = top - (yPos - top);
        dy = -dy;
    } else if (yPos < bottom) {
        yPos = bottom - (yPos - bottom);
        dy = -dy;
    }

}

void TestOne::updateData(const double dt)
{
    // Update base classes stuff
    BaseClass::updateData(dt);

    // ---
    // Save the point every pass (if it has changed)
    // ---
    if (nTrails == 0 || xPos != xOld || yPos != yOld) {
        trail[index++].set(xPos, yPos);
        if (index >= maxHist) index = 0;
        if (nTrails < maxHist) nTrails++;
        xOld = xPos;
        yOld = yPos;
    }
}

void TestOne::drawFunc()
{
    glBegin(GL_LINE_STRIP);
    int idx{index - 1};
    int i{};
    while (i < nTrails) {
        if (idx < 0) idx = maxHist - 1;
        lcVertex2v(trail[idx--].ptr());
        i++;
    }
    glEnd();
}

//------------------------------------------------------------------------------
// realSpeed() -- sets the starting real speed
//------------------------------------------------------------------------------
bool TestOne::realSpeed(const base::Number* const rsobj)
{
    if (rsobj != nullptr) setSpeed(rsobj->getReal());
    return true;
}

//------------------------------------------------------------------------------
// setAngle() -- sets the starting angle using an base::Angle parameter
//------------------------------------------------------------------------------
bool TestOne::setAngle(base::Angle* saobj)
{
    if (saobj != nullptr) {
        base::Radians radians;
        setStartAngle(static_cast<double>(radians.convert(*saobj)));
        iangle = saobj;
        iangle->ref();
    }
    return true;
}

//------------------------------------------------------------------------------
// setAngle() -- sets the starting angle using an base::Number parameter
//------------------------------------------------------------------------------
bool TestOne::setAngle(const base::Number* const saobj)
{
    setStartAngle(saobj->getReal());
    return true;
}
