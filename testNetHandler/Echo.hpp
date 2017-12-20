
#ifndef __Echo_H__
#define __Echo_H__

#include "Endpoint.hpp"

//------------------------------------------------------------------------------
// Class: Echo
//
// Factory name: Echo
//------------------------------------------------------------------------------
class Echo final: public Endpoint
{
   DECLARE_SUBCLASS(Echo, Endpoint)

public:
   Echo();

   void updateData(const double dt = 0.0) final;
   void reset() final;

private:
   int loopCounter {};
};

#endif
