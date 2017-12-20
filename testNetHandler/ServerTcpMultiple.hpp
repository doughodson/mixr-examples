
#ifndef __ServerTcpMultiple_H__
#define __ServerTcpMultiple_H__

#include "Endpoint.hpp"

//------------------------------------------------------------------------------
// Class:  ServerTcpMultiple
//
// Description:
//
// Factory name: ServerTcpMulti
//------------------------------------------------------------------------------
class ServerTcpMultiple final: public Endpoint
{
   DECLARE_SUBCLASS(ServerTcpMultiple, Endpoint)

public:
   ServerTcpMultiple();

   void updateData(const double dt = 0.0) final;
   void reset() final;

};

#endif
