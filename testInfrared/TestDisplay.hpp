
#ifndef __TestDisplay_H__
#define __TestDisplay_H__

#include "mxrp/gui/glut/GlutDisplay.hpp"
#include <array>

namespace mxrp {
namespace models { class Missile; class Player; }
namespace simulation { class Simulation; class Station; }
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
class TestDisplay : public mxrp::glut::GlutDisplay
{
    DECLARE_SUBCLASS(TestDisplay, mxrp::glut::GlutDisplay)

public:
    TestDisplay();

    mxrp::models::Player* getOwnship();
    mxrp::simulation::Simulation* getSimulation();
    mxrp::simulation::Station* getStation();

    virtual void maintainAirTrackSymbols(mxrp::graphics::SymbolLoader* loader, const double rng);

    virtual bool event(const int event, mxrp::base::Object* const obj = nullptr) override;
    virtual void updateData(const double dt = 0.0) override;

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

    double range {40.0};          // SD range

    SendData headingSD;
    SendData rangeSD;

    mxrp::base::safe_ptr<mxrp::simulation::Station> myStation;

    static const unsigned int MAX_TRACKS = 200;
    std::array<mxrp::models::Player*, MAX_TRACKS> tracks {};  // players that we're displaying
    std::array<int, MAX_TRACKS> trkIdx {};                  // Index of track symbols
};

#endif
