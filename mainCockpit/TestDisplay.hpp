
#ifndef __TestDisplay_H__
#define __TestDisplay_H__

#include "mixr/ui/glut/GlutDisplay.hpp"

#include <array>

namespace mixr {
namespace simulation { class Simulation; class Station; }
namespace models { class Missile; class Player; }
namespace graphics { class SymbolLoader; }
namespace xpanel { class DspRadar; class DspRwr; }
}

//------------------------------------------------------------------------------
// Class: TestDisplay
// Description: Test GLUT-display that will manage a simple real-beam, b-scan radar
//              display, plus a Radar receiver display, which shows received
//              signal strength and angle of arrival, a simple situation
//              display that shows the 'truth' location of the players, and
//              Primary Flight Display (PFD).
//
// Factory name: TestDisplay
//
// Events: (all keyboard events)
//   'r' or 'R'   -- Reset simulation
//   'f' or 'F'   -- Toggle simulation freeze
//   'l' or 'L'   -- Launch Missile
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
    static const int MAX_TRACKS{60};
    static const int NCHAR_NAV1_ID{3};
    static const int NCHAR_NAV2_ID{5};

public:
    TestDisplay();

    mixr::models::Player* getOwnship();
    mixr::simulation::Simulation* getSimulation();
    mixr::simulation::Station* getStation();

    void maintainAirTrackSymbols(mixr::graphics::SymbolLoader* loader, const double rng);

    void mouseEvent(const int button, const int state, const int x, const int y) final;
    bool event(const int event, mixr::base::Object* const obj = nullptr) final;
    void updateData(const double dt = 0.0) final;

protected:
    bool shutdownNotification() final;

private:
    // Key event handlers
    bool onResetKey();
    bool onFreezeKey();
    bool onWpnRelKey();
    bool onTgtStepKey();
    bool onRtn2SearchKey();
    bool onAir2AirKey();
    bool onAir2GndKey();
    bool onIncRngKey();
    bool onDecRngKey();
    bool onStepOwnshipKey();

    void updatePfd(const double dt);

    mixr::xpanel::DspRadar* rdrDisplay{};    // Test RADAR display
    mixr::xpanel::DspRwr* rwrDisplay{};      // Test RWR display
    double range{40.0};                      // SD range

    SendData headingSD;
    SendData rangeSD;

    mixr::base::safe_ptr<mixr::simulation::Station> myStation;

    // ---
    // RADAR, RWR and SA stuff
    // ---

    std::array<mixr::models::Player*, MAX_TRACKS> tracks{};  // players that we're displaying
    std::array<int, MAX_TRACKS> trkIdx{};                    // Index of track symbols

    // ---
    // PFD stuff
    // ---

    // pitch and roll
    double pitch{};           // degs
    double pitchRate{10.0};   // degs/sec
    double roll{};            // degs
    double rollRate{-9.0};    // degs/sec

    // heading and nav stuff
    double trueHdg{};         // degs
    double tHdgRate{11.0};    // degs/sec
    double cmdHdg{};          // commanded heading (heading bug) (degs)
    double cmdHdgRate{3.0};   // degs/sec

    // airspeed
    double airSpd{};
    double airSpdRate{5.0};

    // altitude
    double alt{10000.0};
    double altRate{80.0};

    // side slip
    double slip{};            // degs
    double slipRate{10.0};    // degs/sec

    // glideslope (in dots)
    double gSlope{};
    double gSlopeRate{0.2};

    // Lateral dev
    double latDev{};
    double ldRate{0.3};

    // commanded speed
    double cmdSpd{200.0};

    // commanded alt
    double cmdAlt{6000.0};

    // vvi
    double vvi{0.0};
    double vviRate{500.0};

    // flight director stuff (in inches)
    double fDirBank{};
    double fDirBankRate{4.0};
    double fDirPitch{};
    double fDirPitchRate{7.0};

    // barometric pressure
    double baro{};
    double baroRate{10.0};
};

#endif
