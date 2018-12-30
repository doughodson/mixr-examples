
#ifndef __Echo_HPP__
#define __Echo_HPP__

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
