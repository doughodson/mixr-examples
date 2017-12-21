
#include "factory.hpp"

#include "mixr/base/Object.hpp"

#include "SimIoHandler.hpp"
#include "SimPlayer.hpp"
#include "SimStation.hpp"
#include "InstrumentPanel.hpp"

// factories
#include "../shared/xzmq/factory.hpp"
#include "mixr/base/factory.hpp"
#include "mixr/graphics/factory.hpp"
#include "mixr/interop/dis/factory.hpp"
#include "mixr/instruments/factory.hpp"
#include "mixr/linkage/factory.hpp"
#include "mixr/ighost/cigi/factory.hpp"
#include "mixr/ighost/pov/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/simulation/factory.hpp"
#include "mixr/terrain/factory.hpp"
#include "mixr/ui/glut/factory.hpp"

#include <string>

mixr::base::Object* factory(const std::string& name)
{
    mixr::base::Object* obj {};

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

   if (obj == nullptr) obj = mixr::xzmq::factory(name);

   if (obj == nullptr) obj = mixr::cigi::factory(name);
   if (obj == nullptr) obj = mixr::pov::factory(name);
   if (obj == nullptr) obj = mixr::models::factory(name);
   if (obj == nullptr) obj = mixr::simulation::factory(name);
   if (obj == nullptr) obj = mixr::terrain::factory(name);
   if (obj == nullptr) obj = mixr::dis::factory(name);
   if (obj == nullptr) obj = mixr::linkage::factory(name);
   if (obj == nullptr) obj = mixr::instruments::factory(name);
   if (obj == nullptr) obj = mixr::graphics::factory(name);
   if (obj == nullptr) obj = mixr::glut::factory(name);
   if (obj == nullptr) obj = mixr::base::factory(name);

    return obj;
}
