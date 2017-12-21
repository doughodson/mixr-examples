
#ifndef __State_H__
#define __State_H__

#include "mixr/base/Component.hpp"

#include <array>

namespace mixr {
namespace base { class PairStream; }
}

class Block;
class Controller;

//------------------------------------------------------------------------------
// Class: State
//
// Description:  Puzzle state vector
//------------------------------------------------------------------------------
class State final: public mixr::base::Component
{
    DECLARE_SUBCLASS(State, mixr::base::Component)

public:
   static const int MAX_BLOCKS{30};         // Max number of blocks in each state

public:
   State();
   State(const State& org, const Block* const nb, const int idx);

   virtual int f() const              { return (g() + h()); }        // f() function
   virtual int g() const;                                            // g() function
   virtual int h() const;                                            // h() function
   virtual bool isExpanded() const    { return expanded; }           // Has this state been expanded?
   virtual int getGeneration() const  { return generation; }         // State's generation number

   virtual int getNumberOfBlocks() const    { return nblocks; }   // Number of blocks
   virtual const Block* getBlock(const int n) const;              // Returns the n'th block (range: 1 .. getNumberOfBlocks())
   virtual const Block* getBlockByRefNum(const int) const;        // Returns the block with ref ID

   // Expand the state, s, and
   //  returns the state that matches the 'goal' state, if found, else zero
   virtual const State* expand(const State* const goal, Controller* const);

   // State's hash index; 'rh' is rehash count; 'max' is the maximum index
   virtual int hash(int rh, int max) const;

   friend bool operator==(const State& s1, const State& s2);
   friend bool operator!=(const State& s1, const State& s2);

protected:
   //  create a new state (based on this one) and replace the block
   // at index, idx, with the new block, nb.
   const State* stateFactory(const Block* const nb, const int idx, const State* const goal, Controller* const);

   // Sets the state's array of blocks
   virtual int setBlocks(const Block* const newBlocks[], const int numNewBlocks);
   virtual void sortBlocks();
   virtual void clearBlocks();

private:
   std::array<const Block*, MAX_BLOCKS> blocks {};    // Our blocks
   int nblocks {};               // Number of blocks
   bool expanded {};             // True if we've been expanded
   int generation {};            // Generation index

private:
   // slot table helper methods
   bool setSlotBlocks(const mixr::base::PairStream* const);
};

#endif
