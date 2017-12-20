
#ifndef __Endpoint_H__
#define __Endpoint_H__

#include "mixr/base/Component.hpp"

namespace mixr {
namespace base { class NetHandler; class Number; }
}

//------------------------------------------------------------------------------
// Class: Endpoint
//
// Description: Common basic class that contains network handlers
//
// Slots:
//      netHandler  <NetHandler>    Network handler (input/output, or just output if 'netInput' is defined)
//      netInput    <NetHandler>    Optional input handler (otherwise 'netHandler' is used)
//      netOutput   <NetHandler>    Alias for the 'netHandler' slot.
//      noWait      <Number>        No wait (unblocked) I/O flag (default: false -- blocked I/O)
//      loops       <Number>        Number of messages to send/recv before disconnecting and
//                                  halting (default: infinite)
//
//------------------------------------------------------------------------------
class Endpoint : public mixr::base::Component
{
   DECLARE_SUBCLASS(Endpoint, mixr::base::Component)

public:
    static const unsigned int MAX_SIZE{1024};  // Max buffer size

public:
    Endpoint();

    bool areNetworksEnabled() const;

    // Initialize the networks
    bool initNetworks();

    // Send (transmit) our data buffer; returns true if successful.
    // 'size' just be less than MAX_SIZE.
    bool sendData(const char* const msg, const unsigned int size);

    // Receive a data buffer; returns number of bytes received;
    // 'maxsize' just be less than MAX_SIZE.
    int recvData(char* const msg, const unsigned int maxsize);

    void reset() override;

protected:
    void closeConnections();
    int getLoops() const { return loops; }

private:
    mixr::base::safe_ptr<mixr::base::NetHandler> netHandler; // Network handler (input/output, or just output if netInput is defined)
    mixr::base::safe_ptr<mixr::base::NetHandler> netInput;   // Optional input handler (otherwise 'netHandler' is used)
    int loops{};                                             // Number of transfer loops (zero if no limit)
    bool networkInitialized{};                               // Network has been initialized
    bool networkInitFailed{};                                // Network initialization has failed
    bool noWaitFlag{};                                       // No wait (unblocked) I/O flag

private:
    // slot table helper methods
    bool setSlotNetwork(mixr::base::NetHandler* const);
    bool setSlotNetInput(mixr::base::NetHandler* const);
    bool setSlotNoWait(mixr::base::Number* const);
    bool setSlotLoops(mixr::base::Number* const);
};

#endif
