
#ifndef __DspRadar_H__
#define __DspRadar_H__

#include "mixr/graphics/Graphic.hpp"
#include <array>

namespace mixr {
namespace base { class PairStream; }
namespace models { class Radar; }
}

//------------------------------------------------------------------------------
// Class: DspRadar
// Description: Simple Realbeam B-Scan RADAR.  Displays the real-beam signal,
//              with color coded doppler shift, and overlayed with tracks.
// Factory name: DspRadar
//------------------------------------------------------------------------------
class DspRadar final: public mixr::graphics::Graphic
{
   DECLARE_SUBCLASS(DspRadar, mixr::graphics::Graphic)

public:
   DspRadar();

   const mixr::models::Radar* getRadar()             { return radar; }
   const mixr::models::Radar* getRadar() const       { return radar; }
   bool setRadar(mixr::models::Radar* const s)       { radar = s; return true; }

   void drawFunc() final;

   void updateData(const double dt = 0.0) final;

private:
    static const int MAX_TRKS{50};

    const mixr::models::Radar* radar{};  // The test RADAR sensor
    SendData azSD;
    SendData elSD;

    // Tracks
    unsigned int nTracks{};                       // Number of tracks
    int ntsTrk{-1};                               // Index of the 'next-to-shoot' track
    std::array<double, MAX_TRKS> trkRng{};        // Track's range                    (meters)
    std::array<double, MAX_TRKS> trkAz{};         // Track's relative azimuth
    std::array<double, MAX_TRKS> trkVel{};        // Track's velocity                 (m/s)
    std::array<double, MAX_TRKS> trkRelGndTrk{};  // Track's relative ground track (to nearest 45 deg)
};

#endif
