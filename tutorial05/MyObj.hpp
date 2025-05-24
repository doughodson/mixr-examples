
#ifndef __MyObj_HPP__
#define __MyObj_HPP__

#include "mixr/base/IObject.hpp"

namespace mixr {
namespace base { class Boolean; class PairStream; class IList; class String; class Identifier; }
}

//------------------------------------------------------------------------------
// Class: MyObj
// Description: example class
//------------------------------------------------------------------------------
class MyObj final: public mixr::base::IObject
{
   DECLARE_SUBCLASS(MyObj, mixr::base::IObject)

public:
   MyObj();

   // data access functions
   bool setColorTable(const mixr::base::PairStream* const);
   const mixr::base::PairStream* getColorTable() const;
   bool setTextColor(const mixr::base::Identifier* const);
   const mixr::base::Identifier* getTextColor() const;
   bool setBackColor(const mixr::base::Identifier* const);
   const mixr::base::Identifier* getBackColor() const;

   bool setVector(const mixr::base::IList* const);
   const mixr::base::IList* getVector() const;

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
   const mixr::base::IList* vector{};
   const mixr::base::String* message{};
   bool visible{};

private:
   // slot table helper methods
   bool setSlotColorTable(const mixr::base::PairStream* const);
   bool setSlotTextColor(const mixr::base::Identifier* const);
   bool setSlotBackColor(const mixr::base::Identifier* const);
   bool setSlotVector(const mixr::base::IList* const);
   bool setSlotVisible(const mixr::base::Boolean* const);
   bool setSlotMessage(const mixr::base::String* const);
};

#endif
