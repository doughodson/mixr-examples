
#ifndef __ObjectHandler_H__
#define __ObjectHandler_H__

#include "mxrp/graphics/Graphic.hpp"

class TestObject;

//------------------------------------------------------------------------------
// Class: ObjectHandler
// Description: This is a simple generic class that will take in a send
// command from it's parent as an object, and will then fill it's own
// private data from that object.
//------------------------------------------------------------------------------
class ObjectHandler : public mxrp::graphics::Graphic
{
   DECLARE_SUBCLASS(ObjectHandler, mxrp::graphics::Graphic)

public:
   ObjectHandler();

   virtual bool event(const int event, mxrp::base::Object* const obj = nullptr) override;

private:
   bool onUpdateObject(const TestObject* const x);

   SendData boolSD;
   SendData intSD;
   SendData floatSD;
   SendData doubleSD;
   SendData realSD;
   SendData charSD;
};

#endif
