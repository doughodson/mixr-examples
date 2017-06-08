
#include "factory.hpp"

#include "mxrp/base/Object.hpp"

#include "SimIoHandler.hpp"
#include "SimPlayer.hpp"
#include "SimStation.hpp"
#include "InstrumentPanel.hpp"

// factories
#include "../shared/xzmq/factory.hpp"
#include "mxrp/base/factory.hpp"
#include "mxrp/graphics/factory.hpp"
#include "mxrp/gui/glut/factory.hpp"
#include "mxrp/interop/dis/factory.hpp"
#include "mxrp/instruments/factory.hpp"
#include "mxrp/iodevice/factory.hpp"
#include "mxrp/otw/factory.hpp"
#include "mxrp/models/factory.hpp"
#include "mxrp/simulation/factory.hpp"
#include "mxrp/terrain/factory.hpp"

#include <string>

mxrp::base::Object* factory(const std::string& name)
{
    mxrp::base::Object* obj = nullptr;

    // Sim3 Station & IoHandler
    if ( name == SimStation::getFactoryName() ) {
        obj = new SimStation();
    }
     else if ( name == SimIoHandler::getFactoryName() ) {
        obj = new SimIoHandler();
    }

    // Sim3 Player
    else if ( name == SimPlayer::getFactoryName() ) {
        obj = new SimPlayer();
    }

    // InstrumentPanel
    else if ( name == InstrumentPanel::getFactoryName() ) {
        obj = new InstrumentPanel();
    }

   if (obj == nullptr) obj = mxrp::xzmq::factory(name);

   if (obj == nullptr) obj = mxrp::otw::factory(name);
   if (obj == nullptr) obj = mxrp::models::factory(name);
   if (obj == nullptr) obj = mxrp::simulation::factory(name);
   if (obj == nullptr) obj = mxrp::terrain::factory(name);
   if (obj == nullptr) obj = mxrp::dis::factory(name);
   if (obj == nullptr) obj = mxrp::iodevice::factory(name);
   if (obj == nullptr) obj = mxrp::instruments::factory(name);
   if (obj == nullptr) obj = mxrp::graphics::factory(name);
   if (obj == nullptr) obj = mxrp::glut::factory(name);
   if (obj == nullptr) obj = mxrp::base::factory(name);

    return obj;
}
