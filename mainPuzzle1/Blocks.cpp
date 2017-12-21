
#include "Blocks.hpp"

#include "mixr/base/numeric/Integer.hpp"
#include "mixr/base/List.hpp"

IMPLEMENT_ABSTRACT_SUBCLASS(Block, "PuzzleBlock")
EMPTY_DELETEDATA(Block)

BEGIN_SLOTTABLE(Block)
    "position",      //  1: initial position vector
    "id",            //  2: Block's reference ID
END_SLOTTABLE(Block)

BEGIN_SLOT_MAP(Block)
    ON_SLOT( 1, setSlotPosition, mixr::base::List)
    ON_SLOT( 2, setSlotRefId, mixr::base::Integer)
END_SLOT_MAP()

Block::Block()
{
   STANDARD_CONSTRUCTOR()
}

void Block::copyData(const Block& org, const bool)
{
   BaseClass::copyData(org);

   x  = org.x;
   y  = org.y;
   refId = org.refId;
}

bool operator>(const Block& b1, const Block& b2)
{
   bool gt{};
   if (b1.getTypeId() > b2.getTypeId()) {
      gt = true;
   } else if (b1.getTypeId() == b2.getTypeId()) {
      if (b1.x > b2.x) {
         gt = true;
      } else if (b1.x == b2.x) {
         if (b1.y > b2.y)
            gt = true;
      }
   }
   return gt;
}

// Are two blocks equal
bool operator==(const Block& b1, const Block& b2)
{
   return ( (b1.getTypeId() == b2.getTypeId()) && (b1.x == b2.x) && (b1.y == b2.y) );
}

// Are two blocks not equal
bool operator!=(const Block& b1, const Block& b2)
{
   return ( (b1.getTypeId() != b2.getTypeId()) || (b1.x != b2.x) || (b1.y != b2.y) );
}

//------------------------------------------------------------------------------
// Block movement support
//------------------------------------------------------------------------------

// Move block by dx and dy; returns true if successful
bool Block::move(const int dx, const int dy)
{
   bool ok{testMove(dx,dy)};
   if ( ok ) {
      x += dx;
      y += dy;
   }
   return ok;
}

// Tests to see if we can move dx, dy; returns true if we can
bool Block::testMove(const int dx, const int dy) const
{
   return (
         (x + dx) >= 1 &&
         (x + getSizeX() + dx - 1) <= BOARD_X_SIZE &&
         (y + dy) >= 1 &&
         (y + getSizeY() + dy - 1) <= BOARD_Y_SIZE
      );
}

//------------------------------------------------------------------------------
// collisionCheck() -- True if we collide with the test block
//------------------------------------------------------------------------------
bool Block::collisionCheck(const Block* const b2) const
{
  bool c{};
  for (int i = 0; i < getSizeX() && !c; i++) {
    for (int j = 0; j < getSizeY() && !c; j++) {
       int xx{x + i};
       int yy{y + j};
       if ( xx >= b2->x && xx <= (b2->x + b2->getSizeX() - 1) &&
            yy >= b2->y && yy <= (b2->y + b2->getSizeY() - 1) ) c = true;
    }
  }
  return c;
}

//------------------------------------------------------------------------------
// computeHashValue() -- Compute a hash value for this block
//------------------------------------------------------------------------------
int Block::computeHashValue(const int blockIndex, const int rehashCount) const
{
  int i{};
  int a{1};
  int b{1};
  int c{1};

  for (i = 0; i < rehashCount; i++) {
     a *= blockIndex;
     b *= x;
     c *= y;
  }

  b *= x;

  c *= y;
  c *= y;

  return a*b*c;
}

//------------------------------------------------------------------------------
// Set functions
//------------------------------------------------------------------------------

// Initial position
bool Block::setInitPosition(const int ix, const int iy)
{
   x = ix;
   y = iy;
   return true;
}

// Sets the block's reference ID number
bool Block::setReferenceID(const int v)
{
   refId = v;
   return true;
}

//------------------------------------------------------------------------------
// Slot function(s)
//------------------------------------------------------------------------------
bool Block::setSlotPosition(const mixr::base::List* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      int values[2];
      const int n{static_cast<int>(msg->getNumberList(values, 2))};
      if (n == 2) {
         ok = setInitPosition(values[0], values[1]);
      }
   }
   return ok;
}

bool Block::setSlotRefId(const mixr::base::Integer* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      const int i{msg->getInt()};
      if (i >= 0) {
         const auto id = static_cast<unsigned int>(i);
         ok = setReferenceID(id);
      }
   }
   return ok;
}

//==============================================================================
// Class: Block1x1
//==============================================================================

IMPLEMENT_SUBCLASS(Block1x1, "Block1x1")
EMPTY_SLOTTABLE(Block1x1)

EMPTY_COPYDATA(Block1x1)
EMPTY_DELETEDATA(Block1x1)

Block1x1::Block1x1()
{
   STANDARD_CONSTRUCTOR()
}

//------------------------------------------------------------------------------
// Access functions
//------------------------------------------------------------------------------
Block::BlockId Block1x1::getTypeId() const   { return Block::BLOCK_1X1; }
int Block1x1::getSizeX() const               { return 1; }
int Block1x1::getSizeY() const               { return 1; }


//==============================================================================
// Class: Block1x2
//==============================================================================

IMPLEMENT_SUBCLASS(Block1x2,"Block1x2")
EMPTY_SLOTTABLE(Block1x2)

EMPTY_COPYDATA(Block1x2)
EMPTY_DELETEDATA(Block1x2)

Block1x2::Block1x2()
{
   STANDARD_CONSTRUCTOR()
}

//------------------------------------------------------------------------------
// Access functions
//------------------------------------------------------------------------------
Block::BlockId Block1x2::getTypeId() const   { return Block::BLOCK_1X2; }
int Block1x2::getSizeX() const               { return 1; }
int Block1x2::getSizeY() const               { return 2; }

//==============================================================================
// Class: Block2x1
//==============================================================================

IMPLEMENT_SUBCLASS(Block2x1,"Block2x1")
EMPTY_SLOTTABLE(Block2x1)

EMPTY_COPYDATA(Block2x1)
EMPTY_DELETEDATA(Block2x1)

Block2x1::Block2x1()
{
   STANDARD_CONSTRUCTOR()
}

//------------------------------------------------------------------------------
// Access functions
//------------------------------------------------------------------------------
Block::BlockId Block2x1::getTypeId() const   { return Block::BLOCK_2X1; }
int Block2x1::getSizeX() const               { return 2; }
int Block2x1::getSizeY() const               { return 1; }


//==============================================================================
// Class: Block2x2
//==============================================================================

IMPLEMENT_SUBCLASS(Block2x2,"Block2x2")
EMPTY_SLOTTABLE(Block2x2)

EMPTY_COPYDATA(Block2x2)
EMPTY_DELETEDATA(Block2x2)

Block2x2::Block2x2()
{
   STANDARD_CONSTRUCTOR()
}

//------------------------------------------------------------------------------
// Access functions
//------------------------------------------------------------------------------
Block::BlockId Block2x2::getTypeId() const   { return Block::BLOCK_2X2; }
int Block2x2::getSizeX() const               { return 2; }
int Block2x2::getSizeY() const               { return 2; }
