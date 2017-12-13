
#include "TableRow.hpp"

#include "mixr/base/Pair.hpp"
#include "mixr/base/PairStream.hpp"

using namespace mixr;

IMPLEMENT_SUBCLASS(TableRow, "TableRow")
EMPTY_SLOTTABLE(TableRow)

TableRow::TableRow()
{
   STANDARD_CONSTRUCTOR()
}

void TableRow::copyData(const TableRow& org, const bool)
{
   BaseClass::copyData(org);
}

void TableRow::deleteData()
{
}

int TableRow::line() const
{
   return BaseClass::line();
}

int TableRow::line(const int ll)
{
   BaseClass::line(ll);
   position();
   return BaseClass::line();
}

int TableRow::column() const
{
   return BaseClass::column();
}

int TableRow::column(const int cc)
{
   BaseClass::column(cc);
   position();
   return BaseClass::column();
}

void  TableRow::put(base::Pair* pp)
{
   base::PairStream* subcomponents{getComponents()};
   BaseClass::processComponents(subcomponents, typeid(graphics::AbstractField), pp);
   if (subcomponents != nullptr) subcomponents->unref();
}

void TableRow::position()
{
   // position the fields in this table item
   base::PairStream* subcomponents{getComponents()};
   if (subcomponents != nullptr) {

      int ln{line()};
      int cp{column()};

      base::List::Item* item{subcomponents->getFirstItem()};
      while (item != nullptr) {
         const auto pair = static_cast<base::Pair*>(item->getValue());
         const auto ti = static_cast<graphics::AbstractField*>(pair->object());

         ti->line(ln);
         ti->column(cp);
         cp += static_cast<int>(ti->width());

         item = item->getNext();
      }
      subcomponents->unref();
      subcomponents = nullptr;
   }
}
