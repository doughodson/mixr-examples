
#ifndef __TestDisplay_H__
#define __TestDisplay_H__

#include "mixr/gui/glut/GlutDisplay.hpp"

namespace mixr {
   namespace graphics { class Graphic; }
}

//------------------------------------------------------------------------------
// TestDisplay
//------------------------------------------------------------------------------
class TestDisplay : public mixr::glut::GlutDisplay
{
   DECLARE_SUBCLASS(TestDisplay, mixr::glut::GlutDisplay)

public:
   TestDisplay();

   virtual void drawIt() override;
   virtual void mouseEvent(const int button, const int state, const int x, const int y) override;
   virtual bool event(const int event, mixr::base::Object* const obj = nullptr) override;

   bool onFrameBufferKey();

private:
   // select/pick test
   mixr::graphics::Graphic* selected {};
};

#endif
