
#ifndef __Station_H__
#define __Station_H__

#include "mxrp/simulation/Station.hpp"

class StnTimerObject;

//------------------------------------------------------------
// Class: StnTimerObject
// Description: create our window and startup any timers needed
//------------------------------------------------------------
class Station : public mxrp::simulation::Station
{
   DECLARE_SUBCLASS(Station, mxrp::simulation::Station)
public:
   Station();

   // create our top level windows
   virtual int createWindow(int argc, char *argv[]);

private:
   StnTimerObject* timerObj {};
};

#endif
