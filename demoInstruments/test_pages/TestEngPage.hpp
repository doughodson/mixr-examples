
#ifndef __TestEngPage_H__
#define __TestEngPage_H__

#include "mixr/graphics/Page.hpp"
#include "mixr/instruments/engines/EngPage.hpp"

//------------------------------------------------------------------------------
// Class: TestEngPage
//
// Description: Tests the engine page
//------------------------------------------------------------------------------
class TestEngPage final: public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestEngPage, mixr::graphics::Page )

public:
    TestEngPage();

    void updateData(const double dt = 0.0) final;

private:
    // engine 1 n1
    double n1[mixr::instruments::EngPage::NUM_ENG]{};
    double n1Rate[mixr::instruments::EngPage::NUM_ENG]{};

    // engine 1 n2
    double n2[mixr::instruments::EngPage::NUM_ENG]{};
    double n2Rate[mixr::instruments::EngPage::NUM_ENG]{};

    // engine 1 tit
    double tit[mixr::instruments::EngPage::NUM_ENG]{};
    double titRate[mixr::instruments::EngPage::NUM_ENG]{};

    // engin1 1 fuel flow
    double ff[mixr::instruments::EngPage::NUM_ENG]{};
    double ffRate[mixr::instruments::EngPage::NUM_ENG]{};
};

#endif
