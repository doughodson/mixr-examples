
#ifndef __mixr_xbehaviors_PlaneState_H__
#define __mixr_xbehaviors_PlaneState_H__

#include "mixr/base/ubf/AbstractState.hpp"
#include <array>

namespace mixr {
namespace xbehaviors {

//------------------------------------------------------------------------------
// Class: PlaneState
//
// Description: this implementation of PlaneState assumes that player using this
//              state has only one missile (or is ok with firing all missiles at
//              first target)
//------------------------------------------------------------------------------
class PlaneState final: public base::ubf::AbstractState
{
   DECLARE_SUBCLASS(PlaneState, base::ubf::AbstractState)

public:
   PlaneState();

   void reset() final;
   void updateState(const base::Component* const actor) final;

   // set/get
   void setAlive(const bool x)                 { alive = x; return; }
   bool isAlive() const                        { return alive; }

   void setRoll(const double x)                { roll = x; return; }
   double getRoll() const                      { return roll; }

   void setPitch(const double x)               { pitch = x; return; }
   double getPitch() const                     { return pitch; }

   void setHeading(const double x)             { heading = x; return; }
   double getHeading() const                   { return heading; }

   void setRollRate(const double x)            { rollRate = x; return; }
   double getRollRate() const                  { return rollRate; }

   void setPitchRate(const double x)           { pitchRate = x; return; }
   double getPitchRate() const                 { return pitchRate; }

   void setYawRate(const double x)             { yawRate = x; return; }
   double getYawRate() const                   { return yawRate; }

   void setAltitude(const double x)            { altitude = x; return; }
   double getAltitude() const                  { return altitude; }

   void setThrottle(const double x)            { throttle = x; return; }
   double getThrottle() const                  { return throttle; }

   void setSpeed(const double x)               { speed = x; return; }
   double getSpeed() const                     { return speed; }

   void setPitchTrim(const double x)           { pitchTrim = x; return; }
   double getPitchTrim() const                 { return pitchTrim; }

   void setNumTracks(const int x)              { numTracks = x; return; }
   int getNumTracks() const                    { return numTracks; }

   //tracking setter
   void setTracking(const bool x)              { tracking = x; return; }
   //returns true if plane is currently tracking
   bool isTracking() const                     { return tracking; }

   void setMissileFired(const bool x)          { missileFired = x; return; }
   bool isMissileFired() const                 { return missileFired; }

   void setTargetTrack(const int x)            { targetTrack = x; return; }
   int getTargetTrack() const                  { return targetTrack; }

   void setNumEngines(const int x)             { numEngines = x; return; }
   int getNumEngines() const                   { return numEngines; }

   void setIncomingMissile(const bool x)       { incomingMissile = x; return; }
   bool isIncomingMissile() const              { return incomingMissile; }

   //sets the pitch to current object being tracked
   void setPitchToTracked(const int track, const double angle);
   double getPitchToTracked(const int track) const;

   void setHeadingToTracked(const int track, const double angle);
   double getHeadingToTracked(const int track) const;

   void setDistanceToTracked(const int track, const double distance);
   double getDistanceToTracked(const int track) const;

public:
   static const int MAX_TRACKS{50};

private:
   void initData();

   bool alive{};
   double roll{};
   double pitch{};
   double rollRate{};
   double pitchRate{};
   double yawRate{};
   double heading{};
   double altitude{};
   double throttle{};
   double speed{};
   double pitchTrim{};
   std::array<double, MAX_TRACKS> pitchToTracked{};
   std::array<double, MAX_TRACKS> headingToTracked{};
   std::array<double, MAX_TRACKS> distanceToTracked{};
   int targetTrack{MAX_TRACKS};
   int numTracks{};
   bool tracking{};
   bool missileFired{};
   bool incomingMissile{};
   int numEngines{};
};

}
}

#endif
