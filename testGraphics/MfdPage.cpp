
#include "MfdPage.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/graphics/Rotators.hpp"
#include "mixr/base/PairStream.hpp"

using namespace mixr;

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(MfdPage, "MfdPage")
EMPTY_COPYDATA(MfdPage)
EMPTY_DELETEDATA(MfdPage)

MfdPage::MfdPage()
{
   STANDARD_CONSTRUCTOR()
}

BEGIN_EVENT_HANDLER(MfdPage)
END_EVENT_HANDLER()

//------------------------------------------------------------------------------
// onEntry() -- default ON_ENTRY handler
//------------------------------------------------------------------------------
bool MfdPage::onEntry()
{
   base::PairStream* subcomponents{getComponents()};
    if(subcomponents != nullptr) {
        base::List::Item* item{subcomponents->getFirstItem()};
        while (item != nullptr) {
            const auto pair = static_cast<base::Pair*>(item->getValue());
            const auto cp = static_cast<base::Component*>(pair->object());
            if (cp != nullptr) cp->event(RESET_EVENT);
            item = item->getNext();
        }
        subcomponents->unref();
        subcomponents = nullptr;
    }
    return true;
}

void MfdPage::updateData(const double dt)
{
    BaseClass::updateData(dt);

    rotate += (rotateRate * dt);
    if (rotate > 360) {
        rotate = 360;
        rotateRate = -rotateRate;
    }
    if (rotate < -360) {
        rotate = -360;
        rotateRate = -rotateRate;
    }

    send("rotator", UPDATE_VALUE2, rotate, rSD);
}
