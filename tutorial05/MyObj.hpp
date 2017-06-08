
#ifndef __MyObj_H__
#define __MyObj_H__

#include "mxrp/base/Object.hpp"

namespace mxrp {
namespace base { class PairStream; class List; class String; class Number; class Identifier; }
}

//------------------------------------------------------------------------------
// Class: MyObj
// Description: example class
//------------------------------------------------------------------------------
class MyObj : public mxrp::base::Object
{
  DECLARE_SUBCLASS(MyObj, mxrp::base::Object)

public:
  MyObj();

  // data access functions
  bool setColorTable(const mxrp::base::PairStream* const);
  const mxrp::base::PairStream* getColorTable() const;
  bool setTextColor(const mxrp::base::Identifier* const);
  const mxrp::base::Identifier* getTextColor() const;
  bool setBackColor(const mxrp::base::Identifier* const);
  const mxrp::base::Identifier* getBackColor() const;

  bool setVector(const mxrp::base::List* const);
  const mxrp::base::List* getVector() const;

  bool setVisible(bool);
  bool getVisible() const;

  bool setMessage(const mxrp::base::String* const);
  const mxrp::base::String* getMessage() const;

  // slot table functions
  bool setSlotColorTable(const mxrp::base::PairStream* const);
  bool setSlotTextColor(const mxrp::base::Identifier* const x);
  bool setSlotBackColor(const mxrp::base::Identifier* const x);

  bool setSlotVector(const mxrp::base::List* const);
  bool setSlotVisible(const mxrp::base::Number* const);
  bool setSlotMessage(const mxrp::base::String* const);

  virtual bool isValid() const override;

private:
  const mxrp::base::PairStream* colorTable {};
  const mxrp::base::Identifier* textColor {};
  const mxrp::base::Identifier* backColor {};
  const mxrp::base::List* vector {};
  const mxrp::base::String* message {};
  bool visible {};
};

#endif
