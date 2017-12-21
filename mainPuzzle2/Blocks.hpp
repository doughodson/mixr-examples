
#ifndef __Blocks_H__
#define __Blocks_H__

#include "mixr/base/Object.hpp"

namespace mixr {
namespace base { class List; class Integer; }
}

class Controller;

//------------------------------------------------------------------------------
// Class:  Block
//
// Description:  Abstract puzzle block
//
// Block locations (x, y): lower left is (1,1)
// Block type IDs are unique to blocks of the same type (e.g., size and shape)
//------------------------------------------------------------------------------
class Block : public mixr::base::Object
{
    DECLARE_SUBCLASS(Block, mixr::base::Object)

public:
   Block();

   int getX() const        { return x; }              // Blocks X (horizontal) position; one is most left
   int getY() const        { return y; }              // blocks Y (vertical) position; one is at the bottom

   int getReferenceID() const { return refId; }       // Block's reference ID number

   virtual int getTypeId() const = 0;                 // Blocks type ID
   virtual int getSizeX() const = 0;                  // Block's X size
   virtual int getSizeY() const = 0;                  // Block's Y size

   // Tests to see if we can move dx, dy; returns true if we can
   virtual bool testMove(const int dx, const int dy, const Controller* const puz) const;

   // Tries to move block by dx and dy; returns true if successful
   virtual bool move(const int dx, const int dy, const Controller* const puz);

   // True if we collide with the test block
   virtual bool collisionCheck(const Block* const b2) const;

   friend int compare(const Block& b1, const Block& b2);
   friend int comparePosition(const Block& b1, const Block& b2);

   // Compute a hash value for this block
   virtual int computeHashValue(const int blockIndex, const int rehashCount) const;

protected:
   virtual bool setInitPosition(const unsigned int x, const unsigned int y);
   virtual bool setReferenceID(const unsigned int v);          // Sets the block's reference ID number

private:
   int x{}, y{};  // Location
   int refId{};   // Block's ref ID number

private:
   // slot table helper methods
   bool setSlotPosition(const mixr::base::List* const);
   bool setSlotRefId(const mixr::base::Integer* const);

};

//------------------------------------------------------------------------------
// Class:  Block1
//------------------------------------------------------------------------------
class Block1 final: public Block {
   DECLARE_SUBCLASS(Block1, Block)
public:
   Block1();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block2
//------------------------------------------------------------------------------
class Block2 final: public Block {
   DECLARE_SUBCLASS(Block2, Block)
public:
   Block2();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block3
//------------------------------------------------------------------------------
class Block3 final: public Block {
   DECLARE_SUBCLASS(Block3, Block)
public:
   Block3();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block4
//------------------------------------------------------------------------------
class Block4 final: public Block {
   DECLARE_SUBCLASS(Block4, Block)
public:
   Block4();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block5
//------------------------------------------------------------------------------
class Block5 final: public Block {
   DECLARE_SUBCLASS(Block5, Block)
public:
   Block5();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block6
//------------------------------------------------------------------------------
class Block6 final: public Block {
   DECLARE_SUBCLASS(Block6, Block)
public:
   Block6();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block7
//------------------------------------------------------------------------------
class Block7 final: public Block {
   DECLARE_SUBCLASS(Block7, Block)
public:
   Block7();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block8
//------------------------------------------------------------------------------
class Block8 final: public Block {
   DECLARE_SUBCLASS(Block8, Block)
public:
   Block8();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block9
//------------------------------------------------------------------------------
class Block9 final: public Block {
   DECLARE_SUBCLASS(Block9, Block)
public:
   Block9();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block10
//------------------------------------------------------------------------------
class Block10 final: public Block {
   DECLARE_SUBCLASS(Block10, Block)
public:
   Block10();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block11
//------------------------------------------------------------------------------
class Block11 final: public Block {
   DECLARE_SUBCLASS(Block11, Block)
public:
   Block11();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block12
//------------------------------------------------------------------------------
class Block12 final: public Block {
   DECLARE_SUBCLASS(Block12, Block)
public:
   Block12();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block13
//------------------------------------------------------------------------------
class Block13 final: public Block {
   DECLARE_SUBCLASS(Block13, Block)
public:
   Block13();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block14
//------------------------------------------------------------------------------
class Block14 final: public Block {
   DECLARE_SUBCLASS(Block14, Block)
public:
   Block14();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

//------------------------------------------------------------------------------
// Class:  Block15
//------------------------------------------------------------------------------
class Block15 final: public Block {
   DECLARE_SUBCLASS(Block15, Block)
public:
   Block15();

   int getTypeId() const final;
   int getSizeX() const final;
   int getSizeY() const final;
};

#endif
