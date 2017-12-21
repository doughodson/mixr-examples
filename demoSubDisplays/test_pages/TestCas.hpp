
#ifndef __TestCas_H__
#define __TestCas_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestCas
//
// Description: Example Analog Dial Page
// This page will supply test data to a generic calibrated air speed
//------------------------------------------------------------------------------
class TestCas final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestCas, mixr::graphics::Page)

public:
    TestCas();

    void updateData(const double dt = 0) final;

private:
    double tas{};                   // our cas dial rotation position (1 - 900)
    SendData tasSD;
    double  tasRate{50.0};          // rate which are going (up or down)
    SendData tasPointerRotationSD;  // cas pointer rotation (1 - 900)
    SendData tasROSD;
};

#endif
