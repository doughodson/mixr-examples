
#ifndef __DspRadar_HPP__
#define __DspRadar_HPP__

#include "mixr/graphics/Graphic.hpp"
#include <array>

namespace mixr {
namespace base { class PairStream; }
namespace models { class IRadar; }
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

   const mixr::models::IRadar* getRadar()             { return radar; }
   const mixr::models::IRadar* getRadar() const       { return radar; }
   bool setRadar(mixr::models::IRadar* const s)       { radar = s; return true; }

   void drawFunc() final;

   void updateData(const double dt = 0.0) final;

private:
    static const int MAX_TRKS{50};

    const mixr::models::IRadar* radar{};  // The test RADAR sensor
    SendData azSD;
    SendData elSD;

    // tracks
    int nTracks{};                                // number of tracks
    int ntsTrk{-1};                               // index of the 'next-to-shoot' track
    std::array<double, MAX_TRKS> trkRng{};        // track's range                    (meters)
    std::array<double, MAX_TRKS> trkAz{};         // track's relative azimuth
    std::array<double, MAX_TRKS> trkVel{};        // track's velocity                 (m/s)
    std::array<double, MAX_TRKS> trkRelGndTrk{};  // track's relative ground track (to nearest 45 deg)
};

#endif
