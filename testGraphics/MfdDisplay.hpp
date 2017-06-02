
#ifndef __MfdDisplay_H__
#define __MfdDisplay_H__

#include "mxrp/gui/glut/GlutDisplay.hpp"

//------------------------------------------------------------------------------
// Class: MfdDisplay
//
// Description: Example display pages (e.g., MFD, CDU, etc).  Manages the
//              display's pages.
//              -- All it really does for this example is accept the ESC event.
//
//------------------------------------------------------------------------------
class MfdDisplay : public oe::graphics::Display
{
   DECLARE_SUBCLASS(MfdDisplay, oe::graphics::Display)

public:
   MfdDisplay();
};

#endif
