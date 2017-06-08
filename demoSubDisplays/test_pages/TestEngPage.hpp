
#ifndef __TestEngPage_H__
#define __TestEngPage_H__

#include "mxrp/graphics/Page.hpp"
#include "mxrp/instruments/engines/EngPage.hpp"

//------------------------------------------------------------------------------
// Class: TestEngPage
//
// Description: Tests the engine page
//------------------------------------------------------------------------------
class TestEngPage : public mxrp::graphics::Page
{
   DECLARE_SUBCLASS(TestEngPage, mxrp::graphics::Page )

public:
    TestEngPage();

    virtual void updateData(const double dt = 0.0) override;

private:
    // engine 1 n1
    double n1[mxrp::instruments::EngPage::NUM_ENG] {};
    double n1Rate[mxrp::instruments::EngPage::NUM_ENG] {};

    // engine 1 n2
    double n2[mxrp::instruments::EngPage::NUM_ENG] {};
    double n2Rate[mxrp::instruments::EngPage::NUM_ENG] {};

    // engine 1 tit
    double tit[mxrp::instruments::EngPage::NUM_ENG] {};
    double titRate[mxrp::instruments::EngPage::NUM_ENG] {};

    // engin1 1 fuel flow
    double ff[mxrp::instruments::EngPage::NUM_ENG] {};
    double ffRate[mxrp::instruments::EngPage::NUM_ENG] {};
};

#endif
