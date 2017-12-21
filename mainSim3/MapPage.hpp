
#ifndef __MapPage_H__
#define __MapPage_H__

#include "mixr/graphics/MapPage.hpp"

#include <array>

namespace mixr {
namespace models { class Player; }
namespace graphics { class SymbolLoader; }
}
class Station;

// -------------------------------------------------------------------------------
// Class: MapPage
//
// Description:
//      Derived MapPage that will show how to add, remove, and update symbols with the
//      SymbolLoader class.
// -------------------------------------------------------------------------------
class MapPage final: public mixr::graphics::MapPage
{
    DECLARE_SUBCLASS(MapPage, mixr::graphics::MapPage)

public:
    MapPage();

    void drawFunc() final;
    void updateData(const double dt = 0.0) final;

private:
    // holds our players
    static const int MAX_PLAYERS{200};
    static const int MAX_READOUTS{20};
    std::array<mixr::models::Player*, MAX_PLAYERS> player{};  // player pointer
    std::array<int, MAX_PLAYERS> playerIdx{};                 // index of our symbol for the given player
    mixr::graphics::SymbolLoader* loader{};          // our loader for quick reference
    Station* stn{};                                  // our station (to get the player list quickly)
    // show where our lat/lons are
    SendData latsSD[MAX_READOUTS];
    std::array<int, MAX_READOUTS> lats{};
    SendData latReadoutXPosSD[MAX_READOUTS];
    std::array<float, MAX_READOUTS> latReadoutXPos{};
    SendData latReadoutYPosSD[MAX_READOUTS];
    std::array<float, MAX_READOUTS> latReadoutYPos{};
    // lons
    SendData lonsSD[MAX_READOUTS];
    std::array<int, MAX_READOUTS> lons{};
    SendData lonReadoutXPosSD[MAX_READOUTS];
    std::array<float, MAX_READOUTS> lonReadoutXPos{};
    SendData lonReadoutYPosSD[MAX_READOUTS];
    std::array<float, MAX_READOUTS> lonReadoutYPos{};
};

#endif
