
#ifndef __TestTwo_H__
#define __TestTwo_H__

#include "mixr/graphics/Graphic.hpp"

//------------------------------------------------------------------------------
// Class: TestTwo
//
// Description: Control and Send values 'v1' and 'v2' to components
//------------------------------------------------------------------------------
class TestTwo final: public mixr::graphics::Graphic
{
    DECLARE_SUBCLASS(TestTwo, mixr::graphics::Graphic)

public:
    TestTwo();

    bool event(const int event, mixr::base::Object* const obj = nullptr) final;
    void updateTC(const double dt = 0.0) final;
    void updateData(const double dt = 0.0) final;
    void reset() final;

private:
    double v1{}, v1Rate{};
    double v1Max{1.0}, v1Min{};

    double v2{}, v2Rate{};
    double v2Max{1.0}, v2Min{};

    double iv1{}, iv1Rate{0.1};
    double iv2{}, iv2Rate{0.1};

    SendData v1SD;
    SendData v2SD;
    SendData v1TitleSD;
    SendData v2TitleSD;

private:
    // slot table helper methods
    bool setV1(const mixr::base::Number* const);
    bool setV1Rate(const mixr::base::Number* const);
    bool setV1Max(const mixr::base::Number* const);
    bool setV1Min(const mixr::base::Number* const);
    bool setV2(const mixr::base::Number* const);
    bool setV2Rate(const mixr::base::Number* const);
    bool setV2Max(const mixr::base::Number* const);
    bool setV2Min(const mixr::base::Number* const);
};

#endif
