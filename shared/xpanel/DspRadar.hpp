
#ifndef __mixr_xpanel_DspRadar_H__
#define __mixr_xpanel_DspRadar_H__

#include "mixr/graphics/Graphic.hpp"
#include <array>

namespace mixr {
namespace base   { class PairStream; }
namespace models { class Radar; }
namespace xpanel {

//------------------------------------------------------------------------------
// Class: DspRadar
// Description: Simple Realbeam B-Scan RADAR.  Displays the real-beam signal,
//              with color coded doppler shift, and overlaid with tracks.
// Factory name: DspRadar
//------------------------------------------------------------------------------
class DspRadar final: public graphics::Graphic
{
   DECLARE_SUBCLASS(DspRadar, graphics::Graphic)

public:
   DspRadar();

   const models::Radar* getRadar()         { return radar; }
   const models::Radar* getRadar() const   { return radar; }
   bool setRadar(models::Radar* const s)   { radar = s; return true; }

   void drawFunc() final;
   void updateData(const double dt = 0.0) final;

private:
    static const int MAX_TRKS{50};

    const models::Radar* radar{};                 // The test RADAR sensor
    SendData azSD;
    SendData elSD;

    // Tracks
    int nTracks{};                                // Number of tracks
    int ntsTrk{-1};                               // Index of the 'next-to-shoot' track
    std::array<double, MAX_TRKS> trkRng{};        // Track's range             (meters)
    std::array<double, MAX_TRKS> trkAz{};         // Track's relative azimuth
    std::array<double, MAX_TRKS> trkVel{};        // Track's velocity          (m/s)
    std::array<double, MAX_TRKS> trkRelGndTrk{};  // Track's relative ground track (to nearest 45 deg)
};

}
}

#endif
