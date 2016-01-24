// ----------------------------------------------------------------------------
// Class: FltkStation
// ----------------------------------------------------------------------------
#include "FltkStation.h"
#include "FltkDisplay.h"

#include "FL/Fl_Window.H"
#include "FL/Fl_Gl_Window.H"

#include "MainWindow.h"

namespace oe {
namespace example {

IMPLEMENT_SUBCLASS(FltkStation,"FltkStation")
EMPTY_SERIALIZER(FltkStation)

// slot table for this class type
BEGIN_SLOTTABLE(FltkStation)
   "display1",      //  1) first display
   "display2",      //  2) second display
END_SLOTTABLE(FltkStation)

//  Map slot table to handles
BEGIN_SLOT_MAP(FltkStation)
   ON_SLOT(1, setSlotDisplay1, FltkDisplay)
   ON_SLOT(2, setSlotDisplay2, FltkDisplay)
END_SLOT_MAP()

FltkStation::FltkStation()
{
   STANDARD_CONSTRUCTOR()
   initData();
}

void FltkStation::initData()
{
   init = false;
   mainWin = nullptr;
   display1 = nullptr;
   display2 = nullptr;
}

//------------------------------------------------------------------------------
// copyData() -- copy our objects data
//------------------------------------------------------------------------------
void FltkStation::copyData(const FltkStation& org, const bool cc)
{
   BaseClass::copyData(org);

   if (cc) {
      initData();
   }

   if (display1 != nullptr) { display1->unref();  display1 = nullptr; }
   if (org.display1 != nullptr) {
      display1 = org.display1->clone();
   }

   if (display2 != nullptr) { display2->unref();  display2 = nullptr; }
   if (org.display2 != nullptr) {
      display2 = org.display2->clone();
   }

   init = false;
}

//------------------------------------------------------------------------------
// deleteData() -- copy our objects data
//------------------------------------------------------------------------------
void FltkStation::deleteData()
{
   if (display1 != nullptr) { display1->unref();  display1 = nullptr; }
   if (display2 != nullptr) { display2->unref();  display2 = nullptr; }
}

//------------------------------------------------------------------------------
// reset() -- reset our values, and setup our displays if needed
//------------------------------------------------------------------------------
void FltkStation::reset()
{
   // setup our displays.
   if (!init) {
      if (display1 != nullptr) {
         mainWin = new MainWindow(200, 200, 800, 500, "FLTK 1 Test Window");
         mainWin->resizable(mainWin);
         mainWin->setupGui(display1);
         mainWin->setupGui(display2);
         init = true;
         mainWin->show();
      }
   }
}

//------------------------------------------------------------------------------
// updateData() --
//------------------------------------------------------------------------------
void FltkStation::updateData(LCreal dt)
{
   BaseClass::updateData(dt);

   if (display1 != nullptr) display1->updateData(dt);
   if (display2 != nullptr) display2->updateData(dt);
}

//------------------------------------------------------------------------------
// setSlotDisplay() - set our display
//------------------------------------------------------------------------------
bool FltkStation::setSlotDisplay1(FltkDisplay* const x)
{
   if (display1 != nullptr) {
      display1->unref();
      display1 = nullptr;
   }
   if (x != nullptr) {
      display1 = x;
      display1->ref();
   }
   return true;
}

//------------------------------------------------------------------------------
// setSlotDisplay2() - set our 2nd display
//------------------------------------------------------------------------------
bool FltkStation::setSlotDisplay2(FltkDisplay* const x)
{
   if (display2 != nullptr) {
      display2->unref();
      display2 = nullptr;
   }
   if (x != nullptr) {
      display2 = x;
      display2->ref();
   }
   return true;
}


//------------------------------------------------------------------------------
// getSlotByIndex()
//------------------------------------------------------------------------------
basic::Object* FltkStation::getSlotByIndex(const int si)
{
   return BaseClass::getSlotByIndex(si);
}

} // end example namespace
} // end oe namespace
