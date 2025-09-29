
#ifndef __TestDisplay_HPP__
#define __TestDisplay_HPP__

#include "mixr/ui/glut/GlutDisplay.hpp"
#include <array>

namespace mixr {
namespace models { class Missile; class IPlayer; }
namespace simulation { class ISimulation; class IStation; }
namespace graphics { class SymbolLoader; }
}

//------------------------------------------------------------------------------
// Class: TestDisplay
//
// Factory name: TestDisplay
//
// Events: (all keyboard events)
//   'r' or 'R'   -- Reset simulation
//   'f' or 'F'   -- Toggle simulation freeze
//   'l' or 'L'   -- Launch Missile
//   'p' or 'P'   -- Prelaunch weapon
//   's' or 'S'   -- Target step
//   'i' or 'I'   -- Increase Range
//   'd' or 'D'   -- Decrease Range
//------------------------------------------------------------------------------
class TestDisplay final: public mixr::glut::GlutDisplay
{
    DECLARE_SUBCLASS(TestDisplay, mixr::glut::GlutDisplay)

public:
    TestDisplay();

    mixr::models::IPlayer* getOwnship();
    mixr::simulation::ISimulation* getSimulation();
    mixr::simulation::IStation* getStation();

    void maintainAirTrackSymbols(mixr::graphics::SymbolLoader* loader, const double rng);

    bool event(const int event, mixr::base::IObject* const obj = nullptr) final;
    void updateData(const double dt = 0.0) final;

private:
    // Key event handlers
    bool onToggleTimeKey();
    bool onResetKey();
    bool onFreezeKey();
    bool onWpnRelKey();
    bool onPreRelKey();
    bool onIncRngKey();
    bool onDecRngKey();
    bool onStepOwnshipKey();

    double range{40.0};          // SD range

    SendData headingSD;
    SendData rangeSD;

    mixr::base::safe_ptr<mixr::simulation::IStation> myStation;

    static const int MAX_TRACKS{200};
    std::array<mixr::models::IPlayer*, MAX_TRACKS> tracks{};  // players that we're displaying
    std::array<int, MAX_TRACKS> trkIdx{};                     // Index of track symbols
};

#endif
