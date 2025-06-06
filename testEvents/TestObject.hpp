
#ifndef __TestObject_HPP__
#define __TestObject_HPP__

#include "mixr/base/IObject.hpp"
#include <string>

//------------------------------------------------------------------------------
// Class: TestObject
// Description: A very simple object class that will hold basic information, and
// will be passed from a parent to ObjectHandler via send commands, and the
// ObjectHandler will extract the data and send it to the output.  This tests
// the send command passing objects.
//------------------------------------------------------------------------------
class TestObject final: public mixr::base::IObject
{
   DECLARE_SUBCLASS(TestObject, mixr::base::IObject)

public:
   TestObject()                        { STANDARD_CONSTRUCTOR() }

   // set/get data
   void setBoolean(const bool x)       { boolVal = x;      }
   void setInteger(const int x)        { intVal = x;       }
   void setFloat(const float x)        { floatVal = x;     }
   void setDouble(const double x)      { doubleVal = x;    }
   void setChar(const std::string& x)  { charVal = x;      }

   bool getBoolean()                   { return boolVal;   }
   int getInteger()                    { return intVal;    }
   float getFloat()                    { return floatVal;  }
   double getDouble()                  { return doubleVal; }
   const std::string& getChar()        { return charVal;   }

private:
   bool boolVal{};
   int intVal{};
   float floatVal{};
   double doubleVal{};
   std::string charVal{"ASCII"};
};

#endif
