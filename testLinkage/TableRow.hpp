
#ifndef __TableRow_H__
#define __TableRow_H__

#include "mixr/graphics/readouts/Readout.hpp"

namespace mixr {
namespace base { class Pair; }
}

//-----------------------------------------------------------------------
// Class: TableRow
// Description: One row of in the table (used by Table only)
//-----------------------------------------------------------------------
class TableRow final: public mixr::graphics::Readout
{
   DECLARE_SUBCLASS(TableRow, mixr::graphics::Readout)

public:
   TableRow();

   void put(mixr::base::Pair* const);

   // graphics::Readout interface
   int line() const final;
   void line(const int ll) final;
   int column() const final;
   void column(const int cc) final;

private:
   void position();
};

#endif
