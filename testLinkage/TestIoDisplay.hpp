
#ifndef __TestIoDisplay_H__
#define __TestIoDisplay_H__

#include "mixr/ui/glut/GlutDisplay.hpp"

#include <array>
#include <string>

namespace mixr {
namespace base { class AbstractIoHandler; class Number; class String; }
}

//------------------------------------------------------------------------------
// Class TestIoDisplay
// Description: Display class for the I/O devices test program (see testdisplay.epp)
//
// Factory name: TestIoDisplay
// Slots --
//    ioHandler   <base::IoHandler>     Single I/O data handler
//    item        <base::Integer>       Item number [ 1 ... TBL_SIZE ];
//                                         -- clear current channel number and
//                                         -- type for this item.  Next 'ai' or
//                                         -- 'di' will define for this 'item'.
//    di          <base::Integer>       DI channel number for last 'item'
//    ai          <base::Integer>       AI channel number for last 'item'
//    label       <base::String>        (optional) Label
//
// Example:
//   ( TestIoDisplay
//       item:  1   ai: 5     // Item #1 is AI #5
//       item:  2   ai: 5     // Item #2 is AI #6
//       item:  3             // Item #3 is blank
//       item:  4   di: 10    // Item #4 is DI #10
//       item:  5   di: 11    // Item #4 is DI #11
//   )
//------------------------------------------------------------------------------
class TestIoDisplay final: public mixr::glut::GlutDisplay
{
   DECLARE_SUBCLASS(TestIoDisplay, mixr::glut::GlutDisplay)

public:
   static const int ROWS{20};            // see display.epp/
   static const int COLUMNS{3};          // see display.epp
   static const int TBL_SIZE{ROWS*COLUMNS};

public:
   TestIoDisplay();

   void reset() final;
   void updateData(const double dt = 0.0) final;
   void updateTC(const double dt = 0.0) final;

   bool onEscKey() final;

private:
   enum class Type { NONE, AI, DI };
   enum { R_BLANK = 1, R_AI, R_DI_0, R_DI_1 };

   void initData();
   void updateDisplay();

   mixr::base::safe_ptr<mixr::base::AbstractIoHandler> ioHandler;   // The I/O data handler

   // Item/Channel mapping
   int item{};
   std::array<Type, TBL_SIZE> types{{Type::NONE}};
   std::array<int, TBL_SIZE> channels {};
   std::array<bool, TBL_SIZE> labelFlags {};

   std::array<std::string, TBL_SIZE> labels;
   std::array<std::string, TBL_SIZE> labelBuffs;

   // Table data
   std::array<const char*, TBL_SIZE> table_Label {};
   std::array<int, TBL_SIZE> table_typeRo {};
   std::array<double, TBL_SIZE> table_ai {};
   std::array<SendData, TBL_SIZE> table_LabelSD;
   std::array<SendData, TBL_SIZE> table_typeRoSD;
   std::array<SendData, TBL_SIZE> table_aiSD;

private:
   // slot table helper methods
   bool setSlotIoHandler(mixr::base::AbstractIoHandler* const);
   bool setSlotItem(const mixr::base::Number* const);
   bool setSlotAiChannel(const mixr::base::Number* const);
   bool setSlotDiChannel(const mixr::base::Number* const);
   bool setSlotLabel(const mixr::base::String* const);
};

#endif
