
#include "State.hpp"
#include "Blocks.hpp"
#include "Controller.hpp"

#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"

using namespace mixr;

IMPLEMENT_SUBCLASS(State, "PuzzleState")

BEGIN_SLOTTABLE(State)
    "blocks",      //  1: list of blocks
END_SLOTTABLE(State)

BEGIN_SLOT_MAP(State)
    ON_SLOT( 1, setSlotBlocks, base::PairStream )
END_SLOT_MAP()

State::State()
{
   STANDARD_CONSTRUCTOR()
}

State::State(const State& org, const Block* const nb, const int idx)
{
   STANDARD_CONSTRUCTOR()

   setBlocks(org.blocks.data(), org.nblocks);

   if (nb != nullptr && idx < nblocks) {
      if (blocks[idx] != nullptr) blocks[idx]->unref();
      blocks[idx] = nb->clone();
   }
   sortBlocks();

   generation = org.getGeneration() + 1;
}

void State::copyData(const State& org, const bool)
{
   BaseClass::copyData(org);

   expanded = org.expanded;
   generation = org.generation;

   setBlocks(org.blocks.data(), org.nblocks);

   gValue = org.gValue;
   hValue = org.hValue;
}

void State::deleteData()
{
   clearBlocks();
}

int State::gFunc()
{
   gValue = getGeneration();
   return gValue;
}

//------------------------------------------------------------------------------
// hFunc() --
//------------------------------------------------------------------------------
int State::hFunc(const State* const goal)
{
   int value{};

   #if 1
      if (goal != nullptr) {
         for (int i = 0; i < nblocks; i++) {
            int idx{i + 1};
            const Block* b0{getBlock(idx)};
            const Block* gb{goal->getBlock(idx)};
            if (b0 != nullptr && gb != nullptr) {

               int dx{b0->getX() - gb->getX()};
               if (dx < 0) dx = -dx;

               int dy{b0->getY() - gb->getY()};
               if (dy < 0) dy = -dy;

               int delta{dx + dy};
               //if (dy > dx) delta = dy;

               if (idx <= 4) {
                  delta += dy*16;
               } else if (idx <= 8) {
                  delta += dy*9;
               } else if (idx <= 12) {
                  delta += dy*4;
               } else {
                  delta += dy*1;
               }

               value += delta;
            }
         }
      }
   #endif

   hValue =  value;

   return hValue;
}

//------------------------------------------------------------------------------
// Returns the i'th block (range: 1 .. getNumberOfBlocks())
//------------------------------------------------------------------------------

// Returns the i'th block (range: 1 .. getNumberOfBlocks()) (const version)
const Block* State::getBlock(const int i) const
{
   const Block* p{};
   if (i > 0 && i <= nblocks) {
      p = blocks[i-1];
   }
   return p;
}

// Returns the block with ref ID
const Block* State::getBlockByRefNum(const int refId) const
{
   const Block* p{};
   for (int i = 0; i < nblocks && p == nullptr; i++) {
      if (refId == blocks[i]->getReferenceID()) {
         // found it
         p = blocks[i];
      }
   }
   return p;
}

//------------------------------------------------------------------------------
// Expand the state, s, and
//  returns the state that matches the 'goal' state, if found, else zero
//------------------------------------------------------------------------------
const State* State::expand(const State* const goal, Controller* const puz)
{
   const State* endState{};
   expanded = true;

   if (goal != nullptr && puz != nullptr) {

      // for each block contained in the state ...
      for (int idx = 0; idx < nblocks && endState == nullptr; idx++) {

         // Current block
         const Block* const cb{blocks[idx]};

         // move right as far as we can, expanding new states as we go
         {
            bool collision{};
            int dy{};
            for (int dx = 1; !collision && endState == nullptr && cb->testMove(dx,dy,puz); dx++) {
               Block* nb{cb->clone()};
               nb->move(dx,dy,puz);
               for (int j = 0; j < nblocks && !collision; j++) {
                  if ( j != idx ) {
                     collision = nb->collisionCheck(blocks[j]);
                  }
               }
               if ( !collision ) endState = stateFactory(nb, idx, goal, puz);
               nb->unref();
            }
         }

         // move left as far as we can, expanding new states as we go
         {
            bool collision{};
            int dy{};
            for (int dx = -1; !collision && endState == nullptr &&  cb->testMove(dx,dy,puz); dx--) {
               Block* nb{cb->clone()};
               nb->move(dx,dy,puz);
               for (int j = 0; j < nblocks && !collision; j++) {
                  if ( j != idx ) {
                     collision = nb->collisionCheck(blocks[j]);
                  }
               }
               if ( !collision ) endState = stateFactory(nb, idx, goal, puz);
               nb->unref();
            }
         }

         // move up as far as we can, expanding new states as we go
         {
            bool collision{};
            int dx{};
            for (int dy = 1; !collision && endState == nullptr &&  cb->testMove(dx,dy,puz); dy++) {
               Block* nb{cb->clone()};
               nb->move(dx,dy,puz);
               for (int j = 0; j < nblocks && !collision; j++) {
                  if ( j != idx ) {
                     collision = nb->collisionCheck(blocks[j]);
                  }
               }
               if ( !collision ) endState = stateFactory(nb, idx, goal, puz);
               nb->unref();
            }
         }

         // move down as far as we can, expanding new states as we go
         {
            bool collision{};
            int dx{};
            for (int dy = -1; !collision && endState == nullptr &&  cb->testMove(dx,dy,puz); dy--) {
               Block* nb{cb->clone()};
               nb->move(dx,dy,puz);
               for (int j = 0; j < nblocks && !collision; j++) {
                  if ( j != idx ) {
                     collision = nb->collisionCheck(blocks[j]);
                  }
               }
               if ( !collision ) endState = stateFactory(nb, idx, goal, puz);
               nb->unref();
            }
         }
      }

   }

   return endState;
}

//------------------------------------------------------------------------------
// stateFactory -- create a new state (based on this one) and replace the block
// at index, idx, with the new block, nb.
//------------------------------------------------------------------------------
const State* State::stateFactory(const Block* const nb, const int idx, const State* const goal, Controller* const puz)
{
   const State* endState{};
   if (nb != nullptr && idx < nblocks && goal != nullptr) {

      // create a new state with this block.
      const auto ns = new State(*this,nb,idx);
      ns->container(this);
      ns->defineBoard(puz);
      ns->hFunc(goal);
      ns->gFunc();

      // try to put the new state on the hash table
      if ( puz->putHash(ns) ) {
         // Ok .. this really IS a new state; check to see if we have
         // reached our goal state
         //if (*ns == *goal) {
         if (ns->reachedGoal(goal)) {
            // We found it!
            endState = ns;
         } else {
            // Not yet .. add it to the list of open (unexpanded) states
            puz->putOpen(ns);
         }
      }

      ns->unref();
   }

   return endState;
}

//------------------------------------------------------------------------------
// reachedGoal -- check to see if we've reached the goal state
//------------------------------------------------------------------------------
bool State::reachedGoal(const State* const goalState) const
{
   bool ok{};

   if (goalState != nullptr) {
      ok = (*this == *goalState);
   }
   return ok;
}

//------------------------------------------------------------------------------
// Define block IDs for the board
//------------------------------------------------------------------------------
bool State::defineBoard(const Controller* const puz)
{
   // Remove the old board IDs
   if (board != nullptr) {
      delete[] board;
      board = nullptr;
      boardSize = 0;
   }

   if (puz != nullptr) {

      // get the size of the board
      const int xSize{puz->getBoardSizeX()};
      const int ySize{puz->getBoardSizeY()};
      boardSize = xSize * ySize;

      // Allocate the board and clear it
      board = new int[boardSize];
      for (int i = 0; i < boardSize; i++) {
         board[i] = 0;
      }

      // Now for all of our blocks, set their IDs in the
      // correct board position
      for (int i = 0; i < nblocks; i++) {
         int ix{blocks[i]->getX()};
         int iy{blocks[i]->getY()};
         //unsigned int id = blocks[i]->getTypeId();
         int idx{(ix-1) + (iy-1) * ySize};
         if (idx < boardSize) {
            board[idx] = blocks[i]->getTypeId();
         }
      }

   }

   return true;
}

//------------------------------------------------------------------------------
// hash() -- Compute the state's hash index; 'rh' is rehash count; 'max' is the maximum index
//------------------------------------------------------------------------------
unsigned int State::hash(unsigned int rh, unsigned int max) const
{
   int h{};
   for (int idx = 0; idx < nblocks; idx++) {
      h += blocks[idx]->computeHashValue(idx,rh);
   }
   return h % max;
}

//------------------------------------------------------------------------------
// Comparison functions
//------------------------------------------------------------------------------

// operator== -- are two states equal
bool operator==(const State& ss1, const State& ss2)
{
   bool equal{};

   // States are equal if their boards are the same
   if (ss1.board != nullptr && ss2.board != nullptr) {
      if (ss1.boardSize == ss2.boardSize) {
         // Both states have boards and they're the same size,
         // so we're equal until proven otherwise
         equal = true;
         for (int i = 0; i < ss1.boardSize && equal; i++) {
            equal = (ss1.board[i] == ss2.board[i]);
         }
      }
   }

   return equal;
}


// operator== -- are two states not equal
bool operator!=(const State& ss1, const State& ss2)
{
   return !(ss1 == ss2);
}

//------------------------------------------------------------------------------
// Support functions for the array of blocks
//------------------------------------------------------------------------------

// Sets from an array of pointers to the blocks
int State::setBlocks(const Block* const newBlocks[], const int numNumBlocks)
{
   // First clear out the old
   clearBlocks();

   // Copy the new
   if (newBlocks != nullptr && numNumBlocks > 0) {
      int n{numNumBlocks};
      if (n > MAX_BLOCKS) n =MAX_BLOCKS;
      for (int i = 0; i < n; i++) {
         blocks[i] = newBlocks[i]->clone();
      }
      nblocks = n;
      sortBlocks();
   }
   return nblocks;
}

// sort the blocks
void State::sortBlocks()
{
   for (int i = 1; i < nblocks; i++) {
      for (int j = i; j > 0 && compare( *blocks[j-1] , *blocks[j] ) > 0; j-- ) {
         const Block* bb{blocks[j]};
         blocks[j] = blocks[j-1];
         blocks[j-1] = bb;
      }
   }
}

// Clear blocks
void State::clearBlocks()
{
   for (int i = 0; i < MAX_BLOCKS; i++) {
      if (blocks[i] != nullptr) blocks[i]->unref();
      blocks[i] = nullptr;
   }
   nblocks = 0;

   if (board != nullptr) {
      delete[] board;
      board = nullptr;
      boardSize = 0;
   }
}

//------------------------------------------------------------------------------
// Slot function(s)
//------------------------------------------------------------------------------

// Blocks (list of Blocks)
bool State::setSlotBlocks(const base::PairStream* const msg)
{
   bool ok{};
   if (msg != nullptr) {

      // Array of blocks
      int n{};
      const Block* newBlocks[MAX_BLOCKS];

      // Assume all will be well
      ok = true;

      // Find all blocks (and check their type to make sure)
      const base::List::Item* item{msg->getFirstItem()};
      while (item != nullptr && n < MAX_BLOCKS && ok) {
         const auto pair = static_cast<const base::Pair*>(item->getValue());
         const auto p = dynamic_cast<const Block*>( pair->object() );
         if (p != nullptr) {
            newBlocks[n++] = p;  // Save the point
         } else {
            std::cerr << "State::setSlotBlocks() ERROR -- non-block object was found in the list of blocks" << std::endl;
            ok = false;   // This one wasn't a block
         }
         item = item->getNext();
      }

      // If all is well and we have at least one block ---
      if (ok && n > 0) {
         setBlocks(newBlocks,n);
      }
   }
   return ok;
}

