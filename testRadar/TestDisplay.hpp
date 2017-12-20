
#ifndef __TestDisplay_H__
#define __TestDisplay_H__

#include "mixr/ui/glut/GlutDisplay.hpp"

#include <array>

namespace mixr {
namespace models { class Missile; class Player; }
namespace simulation { class Simulation; class Station; }
namespace graphics { class SymbolLoader; }
}

class DspRadar;
class DspRwr;

//------------------------------------------------------------------------------
// Class: TestDisplay
// Description: Test GLUT-display that will manage a simple real-beam, b-scan radar
//              display, plus a Radar receiver display, which shows received
//              signal strength and angle of arrival, and a simple situation
//              display that shows the 'truth' location of the players.
//
// Factory name: TestDisplay
//
// Events: (all keyboard events)
//   'r' or 'R'   -- Reset simulation
//   'f' or 'F'   -- Toggle simulation freeze
//   'l' or 'L'   -- Launch weapon
//   'p' or 'P'   -- Prelaunch weapon
//   'a' or 'A'   -- A/A mode (TWS)
//   'g' or 'G'   -- A/G mode (GMTI)
//   's' or 'S'   -- Target step
//   'i' or 'I'   -- Increase Range
//   'd' or 'D'   -- Decrease Range
//   '+'          -- Ownship step (to next local air vehicle)
//------------------------------------------------------------------------------
class TestDisplay final: public mixr::glut::GlutDisplay
{
    DECLARE_SUBCLASS(TestDisplay, mixr::glut::GlutDisplay)

public:
    TestDisplay();

    mixr::models::Player* getOwnship();
    mixr::simulation::Simulation* getSimulation();
    mixr::simulation::Station* getStation();

    void maintainAirTrackSymbols(mixr::graphics::SymbolLoader* loader, const double rng);

    void mouseEvent(const int button, const int state, const int x, const int y) final;
    bool event(const int event, mixr::base::Object* const obj = nullptr) final;
    void updateData(const double dt = 0.0) final;

private:
    // Key event handlers
    bool onResetKey();
    bool onFreezeKey();
    bool onWpnRelKey();
    bool onPreRelKey();
    bool onTgtStepKey();
    bool onRtn2SearchKey();
    bool onAir2AirKey();
    bool onAir2GndKey();
    bool onIncRngKey();
    bool onDecRngKey();
    bool onStepOwnshipKey();

    DspRadar* rdrDisplay {};     // Test RADAR display
    DspRwr*   rwrDisplay {};     // Test RWR display

    double range {40.0};         // SD range

    SendData headingSD;
    SendData rangeSD;

    mixr::base::safe_ptr<mixr::simulation::Station> myStation;

    static const unsigned int MAX_TRACKS = 200;
    std::array<mixr::models::Player*, MAX_TRACKS> tracks {};  // players that we're displaying
    std::array<int, MAX_TRACKS> trkIdx {};                  // Index of track symbols
};

#endif
