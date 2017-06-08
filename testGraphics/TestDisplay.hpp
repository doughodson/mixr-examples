
#ifndef __TestDisplay_H__
#define __TestDisplay_H__

#include "mxrp/gui/glut/GlutDisplay.hpp"

namespace mxrp {
   namespace graphics { class Graphic; }
}

//------------------------------------------------------------------------------
// TestDisplay
//------------------------------------------------------------------------------
class TestDisplay : public mxrp::glut::GlutDisplay
{
   DECLARE_SUBCLASS(TestDisplay, mxrp::glut::GlutDisplay)

public:
   TestDisplay();

   virtual void drawIt() override;
   virtual void mouseEvent(const int button, const int state, const int x, const int y) override;
   virtual bool event(const int event, mxrp::base::Object* const obj = nullptr) override;

   bool onFrameBufferKey();

private:
   // select/pick test
   mxrp::graphics::Graphic* selected {};
};

#endif
