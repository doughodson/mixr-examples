
#ifndef __Table_HPP__
#define __Table_HPP__

#include "mixr/graphics/readouts/IReadout.hpp"

namespace mixr {
namespace base { class Integer; class PairStream; }
}

//------------------------------------------------------------------------------
// Class: Table
// Description: Manages a table
//
// Factory name: Table
// Slots:
//    rows     <Integer>    ! Number of rows (default: 1)
//    spacing  <Integer>    ! Spacing between rows (default: 1)
//    columns  <PairStream> ! Column descriptions: list of items in each row
//------------------------------------------------------------------------------
class Table final: public mixr::graphics::IReadout
{
   DECLARE_SUBCLASS(Table, mixr::graphics::IReadout)

public:
   Table();

   const mixr::base::PairStream* getColumns() const;
   int getNumberOfRows() const;

   // graphics::Readout interface
   int line() const final;
   void line(const int ll) final;
   int column() const final;
   void column(const int cc) final;

   // base::Component interface
   void reset() final;

private:
   static const int DEFAULT_ROW{1};
   static const int DEFAULT_SPACING{1};

   void build();        // Builds the table into our components
   void position();     // Positions the table

   int rows{DEFAULT_ROW};                    // Number of rows in table
   int spacing{DEFAULT_SPACING};             // Spacing between rows (default: 1)
   const mixr::base::PairStream* columns{};  // columns items

private:
   // slot table helper methods
   bool setSlotRows(mixr::base::Integer* const);
   bool setSlotSpacing(mixr::base::Integer* const);
   bool setSlotColumns(mixr::base::PairStream* const);
};

#endif
