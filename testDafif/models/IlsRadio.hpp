
#ifndef __IlsRadio_HPP__
#define __IlsRadio_HPP__

#include "INavRadio.hpp"

namespace mixr {
namespace dafif { class AirportLoader; class NavaidLoader; }
}

//------------------------------------------------------------------------------
// Class: IlsRadio
// Description: Instrument landing system (ILS) navigation radio model
// Factory name: IlsRadio
//------------------------------------------------------------------------------
class IlsRadio final: public INavRadio
{
   DECLARE_SUBCLASS(IlsRadio, INavRadio)

public:
   // constants for figuring degrees to dots
   static const double GS_DEG_PER_DOT;
   static const double LOC_DEG_PER_DOT;

public:
   IlsRadio();

   //Outside Access FCNs
   double getGlideslopeDifference();
   double getLocalizerDifference();
   double getGlideslopeDifferenceDots();
   double getLocalizerDifferenceDots();

   void updateData(const double dt = 0.0) override;

protected:
   // Always find the glideslope first!!!!
   virtual bool findILSGlideslopeByFreq(double freq);
   virtual bool findLocalizerByFreq(double freq);

private:
   int timerCounter{};              // For Only doing calc every so often
   bool localizerValid{};
   bool glideSlopeValid{};
   double range{};                  // slant range to the end of the runway
   double grdrange{};               // ground range to the end of the RWY
   double bearing{};                // bearing of the end of the RWY
   double destLatitude{};           // lat for end of RWY
   double destLongitude{};          // lon for end of RWY
   double deltaGlideSlope{};
   double deltaLocalizerBearing{};
   double currentMagVar{};          // mag var at glideslope emitter
   double acGlideSlope{};
   double acLocalizerBearing{};
   double ilsGlideSlope{};
   double ilsLocalizerBearing{};
};

#endif
