
#ifndef __Table_H__
#define __Table_H__

#include "mixr/graphics/readouts/AbstractField.hpp"

namespace mixr {
namespace base { class Number; class PairStream; }
}

//------------------------------------------------------------------------------
// Class: Table
// Description: Manages a table
//
// Factory name: Table
// Slots:
//    rows     <Number>     ! Number of rows (default: 1)
//    spacing  <Number>     ! Spacing between rows (default: 1)
//    columns  <PairStream> ! Column descriptions: list of items in each row
//------------------------------------------------------------------------------
class Table : public mixr::graphics::AbstractField
{
   DECLARE_SUBCLASS(Table, mixr::graphics::AbstractField)

public:
   Table();

   virtual const mixr::base::PairStream* getColumns() const;
   virtual int getNumberOfRows() const;

   // graphics::AbstractField interface
   int line() const override;
   int line(const int ll) override;
   int column() const override;
   int column(const int cc) override;

   // base::Component interface
   void reset() override;

private:
   static const int DEFAULT_ROW     {1};
   static const int DEFAULT_SPACING {1};

   void build();        // Builds the table into our components
   void position();     // Positions the table

   int rows {DEFAULT_ROW};                    // Number of rows in table
   int spacing {DEFAULT_SPACING};             // Spacing between rows (default: 1)
   const mixr::base::PairStream* columns {};  // columns items

private:
   // slot table helper methods
   bool setSlotRows(mixr::base::Number* const);
   bool setSlotSpacing(mixr::base::Number* const);
   bool setSlotColumns(mixr::base::PairStream* const);
};

#endif
