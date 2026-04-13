
#ifndef __TestDisplay_HPP__
#define __TestDisplay_HPP__

#include "mixr/ui/glut/IGlutDisplay.hpp"

namespace mixr {
   namespace graphics { class Graphic; }
}

//------------------------------------------------------------------------------
// TestDisplay
//------------------------------------------------------------------------------
class TestDisplay final: public mixr::glut::IGlutDisplay
{
   DECLARE_SUBCLASS(TestDisplay, mixr::glut::IGlutDisplay)

public:
   TestDisplay();

   void drawIt() final;
   void mouseEvent(const int button, const int state, const int x, const int y) final;
   bool event(const int event, mixr::base::IObject* const obj = nullptr) final;

   bool onFrameBufferKey();

private:
   // select/pick test
   mixr::graphics::Graphic* selected{};
};

#endif
