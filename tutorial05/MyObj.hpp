
#ifndef __MyObj_H__
#define __MyObj_H__

#include "mixr/base/Object.hpp"

namespace mixr {
namespace base { class PairStream; class List; class String; class Number; class Identifier; }
}

//------------------------------------------------------------------------------
// Class: MyObj
// Description: example class
//------------------------------------------------------------------------------
class MyObj final: public mixr::base::Object
{
   DECLARE_SUBCLASS(MyObj, mixr::base::Object)

public:
   MyObj();

   // data access functions
   bool setColorTable(const mixr::base::PairStream* const);
   const mixr::base::PairStream* getColorTable() const;
   bool setTextColor(const mixr::base::Identifier* const);
   const mixr::base::Identifier* getTextColor() const;
   bool setBackColor(const mixr::base::Identifier* const);
   const mixr::base::Identifier* getBackColor() const;

   bool setVector(const mixr::base::List* const);
   const mixr::base::List* getVector() const;

   bool setVisible(bool);
   bool getVisible() const;

   bool setMessage(const mixr::base::String* const);
   const mixr::base::String* getMessage() const;

   void dumpContents() const;

   bool isValid() const final;

private:
   const mixr::base::PairStream* colorTable{};
   const mixr::base::Identifier* textColor{};
   const mixr::base::Identifier* backColor{};
   const mixr::base::List* vector{};
   const mixr::base::String* message{};
   bool visible{};

private:
   // slot table helper methods
   bool setSlotColorTable(const mixr::base::PairStream* const);
   bool setSlotTextColor(const mixr::base::Identifier* const);
   bool setSlotBackColor(const mixr::base::Identifier* const);
   bool setSlotVector(const mixr::base::List* const);
   bool setSlotVisible(const mixr::base::Number* const);
   bool setSlotMessage(const mixr::base::String* const);
};

#endif
