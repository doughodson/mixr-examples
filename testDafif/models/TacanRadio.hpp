
#ifndef __Radios_HPP__
#define __Radios_HPP__

#include "INavRadio.hpp"

namespace mixr {
namespace dafif { class AirportLoader; class NavaidLoader; }
}

//------------------------------------------------------------------------------
// Class: TacanRadio
// Description: Tactical air navigation system (TACAN) radio model
// Factory name: TacanRadio
//------------------------------------------------------------------------------
class TacanRadio final: public INavRadio
{
   DECLARE_SUBCLASS(TacanRadio, INavRadio)

public:
   // bands
   enum class Band { TCN_X_BAND = 0, TCN_Y_BAND };

   // power modes
   enum class PwrModes {
      PWR_TCN_OFF = BaseClass::PWR_OFF,
      PWR_TCN_REC,          // REC mode
      PWR_TCN_TRAN_REC,     // T/R mode
      PWR_TCN_AA_TRAN_REC,  // AA TR mode
   };

public:
   TacanRadio();

   Band getBand() const;
   virtual bool setBand(const Band x);

   double getRange() const;       // Range (nautical miles)
   double getBearing() const;     // Bearing (degrees)

   void updateData(const double dt = 0.0) override;

protected:
   // Get Range and Bearing - Input pointers for your outputs
   bool computeRangeBearing(bool* rngIsValid, double* range, double* grdrange, bool* bearingIsValid, double* bearing);

private:
   void initData();

   Band band {Band::TCN_X_BAND};

   bool rangeIsValid{};
   bool bearingIsValid{};

   double range{};
   double grdrange{};
   double bearing{};
   double destLatitude{};
   double destLongitude{};
   double currentMagVar{};
};

#endif
