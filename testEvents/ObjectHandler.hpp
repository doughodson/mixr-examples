
#ifndef __ObjectHandler_H__
#define __ObjectHandler_H__

#include "mixr/graphics/Graphic.hpp"

class TestObject;

//------------------------------------------------------------------------------
// Class: ObjectHandler
// Description: This is a simple generic class that will take in a send
// command from it's parent as an object, and will then fill it's own
// private data from that object.
//------------------------------------------------------------------------------
class ObjectHandler final: public mixr::graphics::Graphic
{
   DECLARE_SUBCLASS(ObjectHandler, mixr::graphics::Graphic)

public:
   ObjectHandler();

   bool event(const int event, mixr::base::Object* const obj = nullptr) final;

private:
   bool onUpdateObject(const TestObject* const);

   SendData boolSD;
   SendData intSD;
   SendData floatSD;
   SendData doubleSD;
   SendData realSD;
   SendData charSD;
};

#endif
