
#include "IlsRadio.hpp"

#include "mixr/models/player/IPlayer.hpp"

#include "mixr/dafif/loaders/AirportLoader.hpp"
#include "mixr/dafif/loaders/NavaidLoader.hpp"

#include "WorldModel.hpp"

#include "mixr/base/units/lengths.hpp"
#include "mixr/base/util/nav_utils.hpp"

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(IlsRadio, "IlsRadio")
EMPTY_DELETEDATA(IlsRadio)

const double IlsRadio::GS_DEG_PER_DOT{0.25};
const double IlsRadio::LOC_DEG_PER_DOT{1.25};

IlsRadio::IlsRadio()
{
    STANDARD_CONSTRUCTOR()
    setMaxDetectRange(35.0);
}

void IlsRadio::copyData(const IlsRadio& org, const bool)
{
    BaseClass::copyData(org);

    timerCounter = org.timerCounter;
    destLatitude = org.destLatitude;
    destLongitude = org.destLongitude;
    currentMagVar = org.currentMagVar;
    localizerValid = org.localizerValid;
    glideSlopeValid = org.glideSlopeValid;
    range = org.range;
    grdrange = org.grdrange;
    bearing = org.bearing;
    ilsGlideSlope = org.ilsGlideSlope;
    acGlideSlope = org.acGlideSlope;
    deltaGlideSlope = org.deltaGlideSlope;
    ilsLocalizerBearing = org.ilsLocalizerBearing;
    acLocalizerBearing = org.acLocalizerBearing;
    deltaLocalizerBearing = org.deltaLocalizerBearing;
}

void IlsRadio::updateData(const double dt)
{
    // Must have ownship
    if (getOwnship() == nullptr) return;

    // Set our position to that of our ownship vehicle
    setPosition();

    //Do not update data every time...Hard code delay length...
    if (timerCounter == 0) {
        //Get Glideslope and Runway orientation:
        glideSlopeValid = findILSGlideslopeByFreq(getFrequency());
        localizerValid = findLocalizerByFreq(getFrequency());

        //Get test results - make sure dest LL do not change as plane flies
        mixr::base::nav::gbd2ll(getLatitude(),getLongitude(),bearing,grdrange,&destLatitude,&destLongitude);
        //Test for bad result...
        if ((glideSlopeValid == false)|(localizerValid == false)) {
            //std::cerr << "No ILS In Range..." << std::endl;
        }
    } else if (timerCounter == 30) {
        timerCounter = 0; //Make sure the lookup occurs on the next cycle
    } else {
        timerCounter++; //Do not do another DB lookup - wait for some time
    }

    BaseClass::updateData(dt);
}

//------------------------------------------------------------------------------
// Outside FCNs
//------------------------------------------------------------------------------
double IlsRadio::getGlideslopeDifference()
{
    return deltaGlideSlope;
}

double IlsRadio::getGlideslopeDifferenceDots()
{
    return deltaGlideSlope / GS_DEG_PER_DOT;
}

double IlsRadio::getLocalizerDifference()
{
    return deltaLocalizerBearing;
}

double IlsRadio::getLocalizerDifferenceDots()
{
    return deltaLocalizerBearing / LOC_DEG_PER_DOT;
}

//------------------------------------------------------------------------------
//Find ILS Glideslope By Freq - ALWAYS FIND GLIDESLOPE FIRST THEN LOCALIZER!!!
//------------------------------------------------------------------------------
bool IlsRadio::findILSGlideslopeByFreq(double freq)
{
   //Reset glideSlopeValid so only the first valid glide slope is returned...
   glideSlopeValid = false;

   if (getAirportLoader() != nullptr && freq > 0) {
      if (getAirportLoader()->requestDbInUse()) {
         //Set the active area:
         getAirportLoader()->setArea(getLatitude(), getLongitude(), getMaxDetectRange());
         //See what the results are:
         int found{getAirportLoader()->queryIlsByFreq(static_cast<float>(freq))};

         //Sort through the results and check the type - assume the closest ones are correct
         //"found" list is already sorted from closest to farthest away:
         for (int i = 0; i < found; i++) {
            mixr::dafif::Ils* p{getAirportLoader()->getIls(i)};
            //Debug Prints:
            //p->printRecord(std::cout);
            //Get Glideslope data here:
            if((!glideSlopeValid)&&(p->isIlsType(mixr::dafif::Ils::GLIDESLOPE))){
               //Glideslope should not affect the bearing data from the localizer
               currentMagVar = p->magVariance();
               float ilsGS{}, acGS{}, delGS{};
               p->getGlideSlopeData(getLatitude(),getLongitude(),getAltitude(),&ilsGS,&acGS,&delGS);
               ilsGlideSlope = ilsGS;
               acGlideSlope= acGS;
               deltaGlideSlope = delGS;
               glideSlopeValid = true;
            }
            //Toast the object:
            p->unref();
         }
         getAirportLoader()->clearDbInUse();
      }
   }
   return glideSlopeValid;
}

//------------------------------------------------------------------------------
//Find Localizer by freq - ALWAYS FIND GLIDESLOPE FIRST THEN FIND LOCALIZER!!!
//------------------------------------------------------------------------------
bool IlsRadio::findLocalizerByFreq(double freq)
{
   localizerValid = false;
   ////Temp Variables...Will use to distinguish low and high end of runway...
   //double magHeading1 = 0;
   //double magHeading2 = 0;
   //double trueBearing1 = 0;
   //double trueBearing2 = 0;

   //if (getAirportLoader() != 0 && freq > 0) {
   //   if (getAirportLoader()->requestDbInUse()) {
   //      //Set the active area to search
   //      getAirportLoader()->setArea(getLatitude(), getLongitude(), getMaxDetectRange());
   //      //Find a list that matches freq
   //      int found = getAirportLoader()->queryRunwayByFreq(freq);
   //      //Debug Display:
   //      //std::cout << "RWY Loc Found = " << found << std::endl;
   //      //Run through the list and find the closest at the appropriate angle:
   //      for (int i = 0; i < found; i++) {
   //            dafif::Runway* p = getAirportLoader()->getRunway(i);
   //            //Get the RWY orientation and bearing for both ends of the runway:
   //            p->getRunwayMagHeading(getLatitude(),getLongitude(),getAltitude(),&magHeading1,&magHeading2,&trueBearing1,&trueBearing2);
   //            //Just for kicks find how far away we are from the end of the runway:
               //p->getTrueBearingRange(getLatitude(),getLongitude(),getAltitude(),&bearing,&range,&grdrange);
   //
   //            //Need a test to see if we want the low end or high end here:
   //            acLocalizerBearing = static_cast<double>(trueBearing1);
   //            //If localizer is from -270 - 90 we know the plane is south and will use low end of RWY
   //            if((acLocalizerBearing>0)&(acLocalizerBearing<=90)|(acLocalizerBearing>270)){
   //               //Use the Low End of RWY
   //               //Mag Var must be already calculated by glideslope marker - not available from localizer(p) here (argg)
   //               ilsLocalizerBearing = magHeading1+currentMagVar;
   //               deltaLocalizerBearing = ilsLocalizerBearing-acLocalizerBearing;
   //            }
   //            else{
   //               //Use the High End of RWY
   //               //Mag Var must be already calculated by glideslope marker - not available from localizer(p) here (argg)
   //               ilsLocalizerBearing = magHeading2+currentMagVar;
   //               deltaLocalizerBearing = ilsLocalizerBearing-acLocalizerBearing;
   //            }

   //            localizerValid = true;
   //            //Delete the object
   //            p->unref();
   //      }
   //   getAirportLoader()->clearDbInUse();
   //   }
   //}
   return localizerValid;
}

