
#ifndef __TestSD_H__
#define __TestSD_H__

#include "mixr/graphics/Page.hpp"
#include "mixr/base/units/angle_utils.hpp"

//------------------------------------------------------------------------------
// Class: TestSD
//
// Description: Sends test data down to the situational display
//------------------------------------------------------------------------------
class TestSD final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestSD, mixr::graphics::Page )

public:
    TestSD();

    void updateData(const double dt = 0.0) final;
    bool event(const int event, mixr::base::Object* const obj = nullptr) final;

    static const int MAX_TRACKS{8};
    static const int MAX_AIRPORTS{8};
    static const int MAX_NAV_AIDS{8};

private:
    bool onToggleRange();

    double heading{};            // our heading
    // rate which are going (up or down)
    double headingRate{0.2 * mixr::base::angle::R2DCC};

    double bearing{};            // goes to our bearing pointer
    double bearingRate{0.4 * mixr::base::angle::R2DCC};

    double range{80.0};          // our range

    // navaid bearings
    double nav1Brg{};            // navaid 1 bearing pointer
    double nav1BrgRate{4.0};
    double nav2Brg{};            // waypoint bearing pointer
    double nav2BrgRate{6.0};

    double orbRange{5.0};        // orbit range

    // heading
    double hdgBug{};             // selected heading bug
    double hdgBugRate{2.0};

    // Structure for our symbol loader
    struct mySymbols {
        double     x{};       // X position or latitude
        double     y{};       // Y position or longitude
        double     hdg{};     // heading (degs)
        int       type{1};    // numeric type (for looking up in slottable)
        char     id[8]{};     // name of the airport (up to 8 characters)
    };

    // air track stuff
    mySymbols myTracks[MAX_TRACKS];    // holds our track data
    bool tracksLoaded{};               // tracks have been loaded

    // airport stuff
    mySymbols myAP[MAX_AIRPORTS];      // holds our airport data
    bool airportsLoaded{};             // airports have been loaded

    // navaid stuff
    mySymbols myNA[MAX_NAV_AIDS];      // holds our navaid data
    bool navAidsLoaded{};              // navaids have been loaded
};

#endif
