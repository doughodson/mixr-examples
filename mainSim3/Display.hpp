
#ifndef __Display_H__
#define __Display_H__

#include "mixr/ui/glut/GlutDisplay.hpp"

// -------------------------------------------------------------------------------
// Class: Display
//
// Description:
//      Derived Display that will make our map page move.
// -------------------------------------------------------------------------------
class Display final: public mixr::glut::GlutDisplay
{
    DECLARE_SUBCLASS(Display, mixr::glut::GlutDisplay)

public:
    Display();

    void mouseMotionEvent(const int x, const int y) final;
    void mouseEvent(const int button, const int state, const int x, const int y) final;
    void passiveMotionEvent(const int x, const int y) final;
    void buttonEvent(const int b) final;
    void updateData(const double dt = 0.0) final;

private:
    int startX{};         // startX of our last mouse position
    int startY{};         // startY of our last mouse position
    bool dragging{};      // are we dragging the map?
    int range{};          // range of our map
    SendData rangeSD;
};

#endif
