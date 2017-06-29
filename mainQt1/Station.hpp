
#ifndef __Station_H__
#define __Station_H__

#include "mixr/simulation/Station.hpp"

class StnTimerObject;

//------------------------------------------------------------
// Class: StnTimerObject
// Description: create our window and startup any timers needed
//------------------------------------------------------------
class Station : public mixr::simulation::Station
{
   DECLARE_SUBCLASS(Station, mixr::simulation::Station)
public:
   Station();

   // create our top level windows
   virtual int createWindow(int argc, char *argv[]);

private:
   StnTimerObject* timerObj {};
};

#endif
