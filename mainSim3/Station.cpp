
#include "Station.hpp"

#include "mixr/ui/glut/GlutDisplay.hpp"

IMPLEMENT_SUBCLASS(Station, "MapTestStation")
EMPTY_DELETEDATA(Station)

BEGIN_SLOTTABLE(Station)
    "display",          // 1) sets our display
END_SLOTTABLE(Station)

BEGIN_SLOT_MAP(Station)
    ON_SLOT(1, setSlotDisplay, mixr::glut::GlutDisplay)
END_SLOT_MAP()

Station::Station()
{
    STANDARD_CONSTRUCTOR()
}

void Station::copyData(const Station& org, const bool)
{
    BaseClass::copyData(org);

    display = org.display->clone();
    displayInit = org.displayInit;
}

//------------------------------------------------------------------------------
// reset() - this is our reset event, which will be called from the mainline
// by sending the base::Component::RESET_EVENT token.  Here we will set up
// our display
//------------------------------------------------------------------------------
void Station::reset()
{
    if (display != nullptr && !displayInit) {
        display->createWindow();
        display->focus(display);
        displayInit = true;
    }

    // this calls our Baseclass (simulation::IStation -> reset)
    BaseClass::reset();
}


//------------------------------------------------------------------------------
// setSlotDisplay() - sets our display
//------------------------------------------------------------------------------
bool Station::setSlotDisplay(mixr::glut::GlutDisplay* x)
{
    bool ok{};
    if (x != nullptr) {
        display = x;
        display->container(this);
        ok = true;
    }

    return ok;
}

