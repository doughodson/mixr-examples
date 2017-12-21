
#ifndef __SituationalDisplay_H__
#define __SituationalDisplay_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: SituationalDisplay
//
// Description: Situational Display
//------------------------------------------------------------------------------
class SituationalDisplay final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(SituationalDisplay, mixr::graphics::Page)

public:
   SituationalDisplay();

   // set functions
   bool setReferenceLat(const double);  // Sets latitude (degs)
   bool setReferenceLon(const double);  // Sets longitude (degs)
   bool setHeading(const double);       // Sets heading (degs)
   bool setRange(const double);         // Sets Range (NM)
   bool setOrbitRange(const double);    // Orbit range
   bool setHeadingBug(const double);    // Sets heading bug (degs)
   bool setNav1Brg(const double);       // Sets navaid 1 bearing (degs)
   bool setNav1Dme(const double);       // Sets navaid 1 DME (NM)
   bool setNav1Id(const char* const);   // Sets navaid 1 identifier
   bool setNav2Brg(const double);       // Sets navaid 2 bearing (degs)
   bool setNav2Dme(const double);       // Sets navaid 2 DME (NM)
   bool setNav2Id(const char* const);   // Sets navaid 2 identifier

   // get functions
   double getOwnshipLat()                            { return refLat;   }
   double getOwnshipLon()                            { return refLon;   }
   double getHeading()                               { return heading;  }
   double getRange()                                 { return range;    }
   double getOrbitRange()                            { return orbRange; }
   double getHdgBug()                                { return hdgBug;   }
   double getNav1Brg()                               { return nav1Brg;  }
   double getNav1Dme()                               { return nav1Dme;  }
   bool getNav1Id(const int index, char* newString);
   double getNav2Brg()                               { return nav2Brg;  }
   double getNav2Dme()                               { return nav2Dme;  }
   bool getNav2Id(const int index, char* newString);

   void updateData(const double dt = 0) final;

private:
   static const int NCHAR_NAV1_ID{3};
   static const int NCHAR_NAV2_ID{5};

   double refLat{};         // latitude
   double refLon{};         // longitude

   double heading{};        // our heading (degs)
   SendData headingROSD;
   double range{80.0};      // our range (NM)
   SendData rangeROSD;
   double orbRange{5.0};    // our orbit range

   // Heading bug
   double hdgBug{};         // selected heading bug (degs)
   SendData hdgBugSD;
   SendData hdgBugROSD;

   // navaid 1
   double nav1Brg{};                     // degs
   double nav1Dme{};                     // Nm
   char   nav1Id[NCHAR_NAV1_ID + 1]{};   // ID
   SendData nav1DmeSD;
   SendData nav1BrgROSD;
   SendData nav1BrgSD;
   SendData nav1IdSD;

   // map page stuff
   SendData headingSD;
   SendData rangeSD;
   SendData refLatSD;
   SendData refLonSD;
   SendData centeredSD;

   // navaid 2
   double nav2Brg{};                     // degs
   double nav2Dme{};                     // Nm
   char   nav2Id[NCHAR_NAV2_ID + 1]{};   // TACAN ID
   SendData nav2DmeSD;
   SendData nav2BrgROSD;
   SendData nav2BrgSD;
   SendData nav2IdSD;

   // Terrain follower
   double planeAlt{1000.0};
   SendData planeAltSD;
   SendData headingCRSD;
};

#endif
