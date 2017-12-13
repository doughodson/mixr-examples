
#ifndef __TableRow_H__
#define __TableRow_H__

#include "mixr/graphics/readouts/AbstractField.hpp"

namespace mixr {
namespace base { class Pair; }
}

//-----------------------------------------------------------------------
// Class: TableRow
// Description: One row of in the table (used by Table only)
//-----------------------------------------------------------------------
class TableRow : public mixr::graphics::AbstractField
{
   DECLARE_SUBCLASS(TableRow, mixr::graphics::AbstractField)

public:
   TableRow();

   void put(mixr::base::Pair* const);

   // graphics::AbstractField interface
   int line() const override;
   int line(const int ll) override;
   int column() const override;
   int column(const int cc) override;

private:
   void position();
};

#endif
