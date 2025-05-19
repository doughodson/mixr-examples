
#include "TacanRadio.hpp"

#include "mixr/models/player/Player.hpp"

#include "mixr/dafif/loaders/AirportLoader.hpp"
#include "mixr/dafif/loaders/NavaidLoader.hpp"

#include "WorldModel.hpp"

#include "mixr/base/units/lengths.hpp"
#include "mixr/base/util/nav_utils.hpp"

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(TacanRadio, "TacanRadio")

TacanRadio::TacanRadio()
{
   STANDARD_CONSTRUCTOR()

   initData();
}

void TacanRadio::initData()
{
    setMaxDetectRange(120.0);
    setNumberOfChannels(126);

    // Set frequencies
    {
        unsigned short chan{1};

        // channels [ 1 .. 16 ]
        while (chan <= 16) {
            setChannelFrequency(chan++, 0.0);
        }

        // channels [ 17 .. 59 ]
        while (chan < 59) {
            setChannelFrequency(chan, (static_cast<double>(chan) * 0.1 + 106.3));
            chan++;
        }

        // channels [ 60 .. 69 ]
        while (chan <= 69) {
            setChannelFrequency(chan++, 0.0);
        }

        // channels [ 70 .. 126 ]
        while (chan <= 126) {
            setChannelFrequency(chan, (static_cast<double>(chan) * 0.1 + 107.3) );
            chan++;
        }
    }
}

void TacanRadio::copyData(const TacanRadio& org, const bool cc)
{
   BaseClass::copyData(org);
   if (cc) initData();

   rangeIsValid = org.rangeIsValid;
   bearingIsValid = org.bearingIsValid;
   range = org.range;
   grdrange = org.grdrange;
   bearing = org.bearing;
   destLatitude = org.destLatitude;
   destLongitude = org.destLongitude;
   currentMagVar = org.currentMagVar;
   band = org.band;
}

void TacanRadio::deleteData()
{
}

void TacanRadio::updateData(const double dt)
{
   BaseClass::updateData(dt);

   //Must have ownship
   if (getOwnship() == nullptr) return;

   // Set our position to that of our ownship vehicle
   setPosition();

   //

   //Get Range and Bearing...
   //bool rangeBearingTestResult = getRangeBearing(&rangeIsValid,&range,&grdrange,&bearingIsValid,&bearing);
}

//------------------------------------------------------------------------------
// Get functions
//------------------------------------------------------------------------------

TacanRadio::Band TacanRadio::getBand() const
{
   return band;
}

double TacanRadio::getRange() const
{
   return range;
}

double TacanRadio::getBearing() const
{
   return bearing;
}

//------------------------------------------------------------------------------
// Set functions
//------------------------------------------------------------------------------

// setBand() - set the X or Y band
bool TacanRadio::setBand(const Band x)
{
   band = x;
   return true;
}


//------------------------------------------------------------------------------
// computeRangeBearing
//------------------------------------------------------------------------------
bool TacanRadio::computeRangeBearing(bool* rngIsValid, double* range, double* grdrange, bool* bearingIsValid, double* bearing)
{
   bool ok{};

   //*rngIsValid = false;
   //*range = 0.0;
   //*grdrange = 0.0;
   //*bearingIsValid = false;
   //*bearing = 0.0;

   //if (getNavaidLoader() != 0 ) {
   //   if ( getNavaidLoader()->requestDbInUse() ) {
   //      getNavaidLoader()->setArea(getLatitude(), getLongitude(), getMaxDetectRange());

   //      *rngIsValid = false;
   //      *range = 0;
   //      *bearingIsValid = false;
   //      *bearing = 0.0;

   //      int found = getNavaidLoader()->queryByChannel(getChannel());

   //      if (found > 0) {
   //         int i = 0;

   //         dafif::Navaid* nav = getNavaidLoader()->getNavaid(i);

   //         if (nav != nullptr) {
               //nav->getTrueBearingRange(getLatitude(), getLongitude(), getAltitude(), bearingIsValid, bearing, rngIsValid, range, grdrange);
   //            currentMagVar = nav->magVariance();
   //            nav->unref();
   //            ok = true;
   //         }
   //      }
   //      getNavaidLoader()->clearDbInUse();
   //   }
   //}

   return ok;
}


