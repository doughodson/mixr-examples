
#ifndef __Block_H__
#define __Block_H__

#include "mixr/base/Object.hpp"

namespace mixr {
namespace base { class List; class Integer; }
}

//------------------------------------------------------------------------------
// Class:  Block
// Description: Abstract puzzle block
//
// Block locations (x, y): lower left is (1,1)
// Block type IDs are unique to blocks of the same type (e.g., size and shape)
//------------------------------------------------------------------------------
class Block : public mixr::base::Object
{
   DECLARE_SUBCLASS(Block, mixr::base::Object)

 public:
   static const int BOARD_X_SIZE{4};
   static const int BOARD_Y_SIZE{5};

   // Block type IDs
   enum BlockId
   {
      BLOCK_2X2 = 1, // 2x2 (goal) type block (must start at 1)
      BLOCK_1X1,     // 1x1 type block
      BLOCK_2X1,     // 2x1 type block
      BLOCK_1X2      // 1x2 type block
   };

 public:
   Block();

   int getX() const     { return x; } // Blocks X (horizontal) position; one is most left
   int getY() const     { return y; } // blocks Y (vertical) position; one is at the bottom

   int getReferenceID() const { return refId; } // Block's reference ID number

   virtual BlockId getTypeId() const = 0;     // Blocks type ID
   virtual int getSizeX() const = 0;          // Block's X size
   virtual int getSizeY() const = 0;          // Block's Y size

   virtual bool testMove(const int dx, const int dy) const;  // Tests to see if we can move dx, dy; returns true if we can
   virtual bool move(const int dx, const int dy);            // Tries to move block by dx and dy; returns true if successful
   virtual bool collisionCheck(const Block *const b2) const; // True if we collide with the test block

   friend bool operator>(const Block &b1, const Block &b2);
   friend bool operator==(const Block &b1, const Block &b2);
   friend bool operator!=(const Block &b1, const Block &b2);

   // Compute a hash value for this block
   virtual int computeHashValue(const int blockIndex, const int rehashCount) const;

 protected:
   virtual bool setInitPosition(const int x, const int y);
   virtual bool setReferenceID(const int v);                // Sets the block's reference ID number

 private:
   int x{}, y{};     // Location
   int refId{};      // Block's ref ID number

private:
   // slot table helper methods
   bool setSlotPosition(const mixr::base::List* const);
   bool setSlotRefId(const mixr::base::Integer* const);
};

//------------------------------------------------------------------------------
// Class:  Block1x1
// Base class:  base::Object-> Block -> Block1x1
// Description:  Block size 1 by 1
//------------------------------------------------------------------------------
class Block1x1 final: public Block
{
   DECLARE_SUBCLASS(Block1x1, Block)
 public:
   Block1x1();

   BlockId getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block1x2
// Base class:  base::Object-> Block -> Block1x2
// Description:  Block size 1 by 2
//------------------------------------------------------------------------------
class Block1x2 final: public Block
{
   DECLARE_SUBCLASS(Block1x2, Block)
 public:
   Block1x2();

   BlockId getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block2x1
// Base class:  base::Object-> Block -> Block2x1
// Description:  Block size 2 by 1
//------------------------------------------------------------------------------
class Block2x1 final: public Block
{
   DECLARE_SUBCLASS(Block2x1, Block)
 public:
   Block2x1();

   BlockId getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block2x2
// Base class:  base::Object-> Block -> Block2x2
// Description:  Block size 2 by 2
//------------------------------------------------------------------------------
class Block2x2 final: public Block
{
   DECLARE_SUBCLASS(Block2x2, Block)
 public:
   Block2x2();

   BlockId getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

#endif
