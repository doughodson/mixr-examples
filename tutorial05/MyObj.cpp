
#include "MyObj.hpp"

#include "mixr/base/numeric/Number.hpp"
#include "mixr/base/numeric/Boolean.hpp"

#include "mixr/base/PairStream.hpp"
#include "mixr/base/List.hpp"
#include "mixr/base/String.hpp"
#include "mixr/base/Identifier.hpp"
#include "mixr/base/colors/Color.hpp"

#include <iostream>
#include <memory>

IMPLEMENT_SUBCLASS(MyObj, "MyObj")

BEGIN_SLOTTABLE(MyObj)
   "colorTable",         // 1: The Color table     <PairStream>
   "textColor",          // 2: Text color          <Identifier>
   "backColor",          // 3: Background color    <Identifier>
   "vector",             // 4: Vector              <List>
   "visible",            // 5: Visibility flag     <Number>
   "message",            // 6: The message         <String>
END_SLOTTABLE(MyObj)

BEGIN_SLOT_MAP(MyObj)
   ON_SLOT(1, setSlotColorTable, mixr::base::PairStream)
   ON_SLOT(2, setSlotTextColor,  mixr::base::Identifier)
   ON_SLOT(3, setSlotBackColor,  mixr::base::Identifier)
   ON_SLOT(4, setSlotVector,     mixr::base::List)
   ON_SLOT(5, setSlotVisible,    mixr::base::Number)
   ON_SLOT(6, setSlotMessage,    mixr::base::String)
END_SLOT_MAP()

MyObj::MyObj()
{
   STANDARD_CONSTRUCTOR()
}

void MyObj::copyData(const MyObj& org, const bool)
{
   BaseClass::copyData(org);

   if (colorTable != nullptr) { colorTable->unref(); colorTable = nullptr; }
   if (org.colorTable != nullptr) colorTable = org.colorTable->clone();

   if (textColor != nullptr) { textColor->unref(); textColor = nullptr; }
   if (org.textColor != nullptr) textColor = org.textColor->clone();

   if (backColor != nullptr) { backColor->unref(); backColor = nullptr; }
   if (org.backColor != nullptr) backColor = org.backColor->clone();

   if (vector != nullptr) { vector->unref(); vector = nullptr; }
   if (org.vector != nullptr) vector = org.vector->clone();

   if (message != nullptr) { message->unref(); message = nullptr; }
   if (org.message != nullptr) message = org.message->clone();

   visible = org.visible;
}

void MyObj::deleteData()
{
   setColorTable(nullptr);
   setTextColor(nullptr);
   setBackColor(nullptr);
   setVector(nullptr);
   setMessage(nullptr);
}

bool MyObj::setColorTable(const mixr::base::PairStream* const x)
{
   if (colorTable != nullptr) colorTable->unref();
   colorTable = x;
   if (colorTable != nullptr) colorTable->ref();
   return true;
}

const mixr::base::PairStream* MyObj::getColorTable() const
{
   return colorTable;
}

bool MyObj::setTextColor(const mixr::base::Identifier* const x)
{
   if (textColor != nullptr) textColor->unref();
   textColor = x;
   if (textColor != nullptr) textColor->ref();
   return true;
}

const mixr::base::Identifier* MyObj::getTextColor() const
{
   return textColor;
}

bool MyObj::setBackColor(const mixr::base::Identifier* const x)
{
   if (backColor != nullptr) backColor->unref();
   backColor = x;
   if (backColor != nullptr) backColor->ref();
   return true;
}

const mixr::base::Identifier* MyObj::getBackColor() const
{
   return backColor;
}

bool MyObj::setVector(const mixr::base::List* const x)
{
   if (vector != nullptr) vector->unref();
   vector = x;
   if (vector != nullptr) vector->ref();
   return true;
}

const mixr::base::List* MyObj::getVector() const
{
   return vector;
}

bool MyObj::setVisible(const bool x)
{
   visible = x;
   return true;
}

bool MyObj::getVisible() const
{
   return visible;
}

bool MyObj::setMessage(const mixr::base::String* const x)
{
   if (message != nullptr) message->unref();
   message = x;
   if (message != nullptr) message->ref();
   return true;
}

const mixr::base::String* MyObj::getMessage() const
{
   return message;
}

bool MyObj::setSlotColorTable(const mixr::base::PairStream* const x)
{
   bool ok{};
   if (x != nullptr) {
      ok = setColorTable(x);
   }
   return ok;
}

bool MyObj::setSlotTextColor(const mixr::base::Identifier* const x)
{
   bool ok{};
   if (x != nullptr) {
      ok = setTextColor(x);
   }
   return ok;
}

bool MyObj::setSlotBackColor(const mixr::base::Identifier* const x)
{
   bool ok{};
   if (x != nullptr) {
      ok = setBackColor(x);
   }
   return ok;
}

bool MyObj::setSlotVector(const mixr::base::List* const x)
{
   bool ok{};
   if (x != nullptr) {
      ok = setVector(x);
   }
   return ok;
}

bool MyObj::setSlotVisible(const mixr::base::Number* const x)
{
   bool ok{};
   if (x != nullptr) {
      ok = setVisible(x->getBoolean());
   }
   return ok;
}

bool MyObj::setSlotMessage(const mixr::base::String* const x)
{
   bool ok{};
   if (x != nullptr) {
      ok = setMessage(x);
   }
   return ok;
}

void MyObj::dumpContents() const
{
   // print out some color information
   const mixr::base::PairStream* colorTable{getColorTable()};
   if (colorTable != nullptr) {
//    Pair* p = colorTable->findByName("green");
      const mixr::base::Identifier* id{getTextColor()};
      if (id != nullptr) {
         const mixr::base::Pair* p{colorTable->findByName(id->getString())};
         if (p != nullptr) {
            std::cout << "Text color: " << id->getString();
            const auto color = dynamic_cast<const mixr::base::Color*>(p->object());
            if (color != nullptr) {
               std::cout << " Red: "   << color->red();
               std::cout << " Green: " << color->green();
               std::cout << " Blue: "  << color->blue();
            }
            std::cout << std::endl;
         } else {
            std::cout << "Text color not found\n" << std::endl;
         }
      }
   }

   // print out vector information
   const mixr::base::List* vector{getVector()};
   if (vector != nullptr) {
      const int numValues{static_cast<int>(vector->entries())};
      std::unique_ptr<int[]> values(new int[numValues]);
      const int n {static_cast<int>(vector->getNumberList(values.get(), numValues))};
      std::cout << "Vector: ";
      std::cout << "# Numeric Entries: " << n << " Values: ";
      for (int i=0; i < n; i++)
         std::cout << values[i] << " ";
      std::cout << std::endl;
   }

   // print out visible and message info
   std::cout << "Visible: " << getVisible() << "\n";
   const mixr::base::String* message {getMessage()};
   std::cout << "Message: " << message->getString() << "\n";
}

//------------------------------------------------------------------------------
// isValid() -- I'm not going to actually check anything - this method is here
//              to demonstrate that the capability to check data set via
//              slottable is correct.
//------------------------------------------------------------------------------
bool MyObj::isValid() const
{
   std::cout << "------------------------------------------\n";
   std::cout << "MyObj::isValid() called\n";
   std::cout << "------------------------------------------\n";
   dumpContents();
   std::cout << "------------------------------------------\n";

   return true;
}
