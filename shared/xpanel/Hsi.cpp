
#include "Hsi.hpp"

#include "mixr/base/numeric/INumber.hpp"

namespace mixr {
namespace xpanel {

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(Hsi, "Hsi")
EMPTY_DELETEDATA(Hsi)

BEGIN_EVENT_HANDLER(Hsi)
    ON_EVENT_OBJ(UPDATE_VALUE3, onUpdateSelHdgHsi,  base::INumber)
    ON_EVENT_OBJ(UPDATE_VALUE4, onUpdateSelCrsHsi,  base::INumber)
    ON_EVENT_OBJ(UPDATE_VALUE5, onUpdateNav1BrgHsi, base::INumber)
    ON_EVENT_OBJ(UPDATE_VALUE6, onUpdateNav2BrgHsi, base::INumber)
    ON_EVENT_OBJ(UPDATE_VALUE7, onUpdateCdiDotsHsi, base::INumber)
    ON_EVENT_OBJ(UPDATE_VALUE8, onUpdateToFromHsi,  base::INumber)
END_EVENT_HANDLER()

Hsi::Hsi()
{
    STANDARD_CONSTRUCTOR()
}

void Hsi::copyData(const Hsi& org, const bool)
{
    BaseClass::copyData(org);
    selHdg = org.selHdg;
    selCrs = org.selCrs;
    selCrsSD.empty();
    cdiDots = org.cdiDots;
    cdiDotsSD.empty();
    toFrom = org.toFrom;
    toFromSD.empty();
    nav1Brg = org.nav1Brg;
    nav2Brg = org.nav2Brg;
    nav1BrgSD.empty();
    nav2BrgSD.empty();
    selHdgROSD.empty();
}

bool Hsi::setSelectedHeading(const double newSH)
{
    selHdg = newSH;
    return true;
}

bool Hsi::setSelectedCourse(const double newC)
{
    selCrs = newC;
    return true;
}

bool Hsi::setNav1Brg(const double newB)
{
    nav1Brg = newB;
    return true;
}

bool Hsi::setNav2Brg(const double newB)
{
    nav2Brg = newB;
    return true;
}

bool Hsi::setCdiDots(const double newCDI)
{
    cdiDots = newCDI;
    return true;
}

bool Hsi::setToFrom(const double newTF)
{
    toFrom = newTF;
    return true;
}

// Event functions
bool Hsi::onUpdateSelHdgHsi(const base::INumber* const x)
{
    bool ok{};
    if (x != nullptr) ok = setSelectedHeading(x->asDouble());
    return ok;
}
bool Hsi::onUpdateSelCrsHsi(const base::INumber* const x)
{
    bool ok{};
    if (x != nullptr) ok = setSelectedCourse(x->asDouble());
    return ok;
}
bool Hsi::onUpdateNav1BrgHsi(const base::INumber* const x)
{
    bool ok{};
    if (x != nullptr) ok = setNav1Brg(x->asDouble());
    return ok;
}
bool Hsi::onUpdateNav2BrgHsi(const base::INumber* const x)
{
    bool ok{};
    if (x != nullptr) ok = setNav2Brg(x->asDouble());
    return ok;
}
bool Hsi::onUpdateCdiDotsHsi(const base::INumber* const x)
{
    bool ok{};
    if (x != nullptr) ok = setCdiDots(x->asDouble());
    return ok;
}
bool Hsi::onUpdateToFromHsi(const base::INumber* const x)
{
    bool ok{};
    if (x != nullptr) ok = setToFrom(x->asDouble());
    return ok;
}

void Hsi::updateData(const double dt)
{
    // update our baseclass first
    BaseClass::updateData(dt);

    // send our data down to our primary course pointer
    send("pricrsptr", UPDATE_VALUE2, selCrs, selCrsSD);
    send("pricrsptr", UPDATE_VALUE3, cdiDots, cdiDotsSD);
    send("pricrsptr", UPDATE_VALUE4, toFrom, toFromSD);

    // send our data down to our bearing pointers
    send("nav1brgptr", UPDATE_VALUE2, nav1Brg, nav1BrgSD);
    send("nav2brgptr", UPDATE_VALUE2, nav2Brg, nav2BrgSD);

    // send our selected heading it's value (just a rotator)
    send("selhdg", UPDATE_VALUE2, selHdg, selHdgSD);
    send("selhdgro", UPDATE_VALUE, selHdg, selHdgROSD);
}

}
}
