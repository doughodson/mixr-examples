
#include "Table.hpp"

#include "TableRow.hpp"

#include "mixr/base/numeric/Number.hpp"

#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"

#include <sstream>

using namespace mixr;

IMPLEMENT_SUBCLASS(Table, "Table")

BEGIN_SLOTTABLE(Table)
   "rows",          //   1) Number of rows
   "spacing",       //   2) Spacing between rows
   "columns",       //   3) Column descriptions: list of items in each row
END_SLOTTABLE(Table)

BEGIN_SLOT_MAP(Table)
   ON_SLOT( 1, setSlotRows,    base::Number)
   ON_SLOT( 2, setSlotSpacing, base::Number)
   ON_SLOT( 3, setSlotColumns, base::PairStream)
END_SLOT_MAP()

Table::Table()
{
   STANDARD_CONSTRUCTOR()
}

void Table::copyData(const Table& org, const bool)
{
   BaseClass::copyData(org);

   rows = org.rows;
   spacing = org.spacing;

   if (org.columns) {
      base::PairStream* p{org.columns->clone()};
      setSlotColumns(p);
   } else {
      setSlotColumns(nullptr);
   }

   build();

   line(org.line());
   column(org.column());
}

//deleteData() -- delete this object's data
void Table::deleteData()
{
   setSlotColumns(nullptr);
}

//------------------------------------------------------------------------------
// reset() -- Reset parameters
//------------------------------------------------------------------------------
void Table::reset()
{
    BaseClass::reset();

    // force a reposition
    line( line() );
    column( column() );
}

//------------------------------------------------------------------------------
// get functions
//------------------------------------------------------------------------------
int Table::line() const
{
   return BaseClass::line();
}

int Table::column() const
{
   return BaseClass::column();
}

const base::PairStream* Table::getColumns() const
{
   return columns;
}

int Table::getNumberOfRows() const
{
   return rows;
}

//------------------------------------------------------------------------------
// set functions
//------------------------------------------------------------------------------
int Table::line(const int ll)
{
   BaseClass::line(ll);
   position();
   return BaseClass::line();
}

int Table::column(const int cc)
{
   BaseClass::column(cc);
   position();
   return BaseClass::column();
}

//------------------------------------------------------------------------------
// position() -- position the rows in this table
//------------------------------------------------------------------------------
void Table::position()
{
   base::PairStream* subcomponents{getComponents()};
   if (subcomponents != nullptr) {

      int ln{line()};
      int cp{column()};

      // Position our subcomponents, which are all TableRow objects (see build())
      base::List::Item* item{subcomponents->getFirstItem()};
      while (item != nullptr) {
         const auto pair = static_cast<base::Pair*>(item->getValue());
         const auto row = static_cast<TableRow*>(pair->object());

         row->line(ln);
         row->column(cp);
         ln += spacing;

         item = item->getNext();
      }
      subcomponents->unref();
      subcomponents = nullptr;
   }
}

//------------------------------------------------------------------------------
// build() -- build the table in our components list
//------------------------------------------------------------------------------
void Table::build()
{
   base::PairStream* newList{};

   if (rows > 0 && columns != nullptr) {

      newList = new base::PairStream();

      // For each row: create a TableRow containing all the items in 'columns'
      for (int i = 1; i <= rows; i++) {

         // new row
         const auto row = new TableRow();
         row->container(this);

         const base::List::Item* item{columns->getFirstItem()};
         while (item != nullptr) {
            const auto pair = static_cast<const base::Pair*>(item->getValue());
            const base::Object* obj{pair->object()};
            if (obj->isClassType(typeid(graphics::Graphic))) {
               base::Pair* pp{pair->clone()};
               const auto gobj = static_cast<graphics::Graphic*>(pp->object());
               gobj->container(row);
               row->put(pp);
               pp->unref();
            }

            item = item->getNext();
         }

         // put the row on our components list with a slotname equal to its row number
         {
            std::ostringstream cbuf;
            cbuf << i;
            const auto pp = new base::Pair(cbuf.str().c_str(), row);
            newList->put(pp);
            pp->unref();
         }

         row->unref();
      }

      // Position our subcomponents
      position();
   }

   // These are new our subcomponents ...
   processComponents(newList, typeid(base::Component));
   if (newList != nullptr) newList->unref();
}


//------------------------------------------------------------------------------
// Slot functions
//------------------------------------------------------------------------------
bool Table::setSlotRows(base::Number* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      const int v{msg->getInt()};
      if (v >= 0) {
         rows = v;
         ok = true;
      }
   }
   return ok;
}

bool Table::setSlotSpacing(base::Number* const msg)
{
   bool ok{};
   if (msg != nullptr) {
      const int v{msg->getInt()};
      if (v >= 0) {
         spacing = v;
         ok = true;
      }
   }
   return ok;
}

bool Table::setSlotColumns(base::PairStream* const msg)
{
   if (columns != nullptr) { columns->unref(); columns = nullptr; }
   if (msg != nullptr) {
      // Make a copy of the list and Make sure we have only Field objexts
      const auto newColumns = new base::PairStream();
      base::List::Item* item{msg->getFirstItem()};
      while (item != nullptr) {
          const auto pair = static_cast<base::Pair*>(item->getValue());
          const auto g = dynamic_cast<graphics::AbstractField*>(pair->object());
          if (g != nullptr) {
              // We have a Field object, so add it to the new columns list
              newColumns->put(pair);
          }
          item = item->getNext();
      }
      columns = newColumns;
   }
   build();
   return true;
}

