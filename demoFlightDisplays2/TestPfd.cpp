
#include "TestPfd.hpp"
#include "mxrp/base/Pair.hpp"
#include "Pfd.hpp"

using namespace mxrp;

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(TestPfd, "TestPfd")
EMPTY_SERIALIZER(TestPfd)
EMPTY_DELETEDATA(TestPfd)

TestPfd::TestPfd()
{
    STANDARD_CONSTRUCTOR()
}

void TestPfd::copyData(const TestPfd& org, const bool)
{
    // Always copy base class stuff first
    BaseClass::copyData(org);

    // pitch and roll
    pitch = org.pitch;
    pitchRate = org.pitchRate;
    roll = org.roll;
    rollRate = org.rollRate;

    // hdg and nav
    trueHdg = org.trueHdg;
    tHdgRate = org.tHdgRate;
    cmdHdg = org.cmdHdg;
    cmdHdgRate = org.cmdHdgRate;

    // airspeed
    airSpd = org.airSpd;
    airSpdRate = org.airSpdRate;

    // altitude
    alt = org.alt;
    altRate = org.alt;

    // side slip
    slip = org.slip;
    slipRate = org.slipRate;

    // glideslope
    gSlope = org.gSlope;
    gSlopeRate = org.gSlopeRate;

    // lateral deviation
    latDev = org.latDev;
    ldRate = org.ldRate;

    // commanded speed
    cmdSpd = org.cmdSpd;

    // commanded alt
    cmdAlt = org.cmdAlt;
    vvi = org.vvi;
    vviRate = org.vviRate;

    // flight director (command bars)
    fDirBank = org.fDirBank;
    fDirBankRate = org.fDirBankRate;
    fDirPitch = org.fDirPitch;
    fDirPitchRate = org.fDirPitchRate;

    // selected barometric pressure
    baro = org.baro;
    baroRate = org.baroRate;
}

void TestPfd::updateData(const double dt)
{
    // update our BaseClass
    BaseClass::updateData(dt);

    // pitch
    pitch += pitchRate * dt;
    if (pitch > 90) {
        pitch = 90;
        pitchRate = -pitchRate;
    }
    if (pitch < -90) {
        pitch = -90;
        pitchRate = -pitchRate;
    }

    // roll
    roll  += rollRate * dt;
    if (roll > 90.0f) {
        roll = 90.0f;
        rollRate = -rollRate;
    }
    if (roll < -90.0f) {
        roll = -90.0f;
        rollRate = -rollRate;
    }

    // heading
    trueHdg += tHdgRate * dt;
    if (trueHdg > 360) trueHdg = 0;

    // selected heading
    cmdHdg += cmdHdgRate * dt;
    if (cmdHdg > 360) {
        cmdHdg = 0;
    }

    // here is sideslip
    slip += slipRate * dt;
    if (slip > 21) {
        slip = 21;
        slipRate = -slipRate;
    }
    if (slip < -21) {
        slip = -21;
        slipRate = -slipRate;
    }

    // airspeed
    airSpd += airSpdRate * dt;
    if (airSpd > 200) {
        airSpd = 200;
        airSpdRate = -airSpdRate;
    }
    if (airSpd < 50) {
        airSpd = 50;
        airSpdRate = -airSpdRate;
    }

    // test data
    double mach = airSpd / 600;

    // commanded speed
    cmdSpd = 150;

    // altitude
    alt += altRate * dt;
    if (alt > 55800) {
        alt = 55800;
        altRate = -altRate;
    }
    if (alt < 0) {
        alt = 0;
        altRate = -altRate;
    }

    // commanded alt
    cmdAlt = 1500;

    // glideslope
    gSlope += gSlopeRate * dt;
    if (gSlope > 2) {
        gSlope = 2;
        gSlopeRate = -gSlopeRate;
    }
    if (gSlope < -2) {
        gSlope = -2;
        gSlopeRate = -gSlopeRate;
    }

    // lat dev
    latDev += ldRate * dt;
    if (latDev > 2) {
        latDev = 2;
        ldRate = -ldRate;
    }
    if (latDev < -2) {
        latDev = -2;
        ldRate = -ldRate;
    }

    // vvi tape gauge test
    vvi += vviRate * dt;
    if (vvi > 7000) {
        vvi = 7000;
        vviRate = -vviRate;
    }
    if (vvi < -7000) {
        vvi = -7000;
        vviRate = -vviRate;
    }

    // flight director stuff
    // flight director bank angle
    fDirBank += fDirBankRate * dt;
    if (fDirBank > 90) {
        fDirBank = 90;
        fDirBankRate = -fDirBankRate;
    }
    if (fDirBank < -90) {
        fDirBank = -90;
        fDirBankRate = -fDirBankRate;
    }

    // flight director pitch angle
    fDirPitch += fDirPitchRate * dt;
    if (fDirPitch > 90) {
        fDirPitch = 90;
        fDirPitchRate = -fDirPitchRate;
    }
    if (fDirPitch < -90) {
        fDirPitch = -90;
        fDirPitchRate = -fDirPitchRate;
    }

    // barometric pressure (selected)
    baro += baroRate * dt;
    if (baro > 999) {
        baro = 999;
        baroRate = -baroRate;
    }
    if (baro < 0) {
        baro = 0;
        baroRate = -baroRate;
    }


    base::Pair* pair = findByType(typeid(Pfd));
    if (pair != nullptr) {
        const auto p = static_cast<Pfd*>(pair->object());
        if (p != nullptr) {
            p->setPitchDeg(pitch);
            p->setRollDeg(roll);
            p->setTrueHeading(trueHdg);
            p->setCmdHdg(cmdHdg);
            p->setAirSpeedKts(airSpd);
            p->setAltitudeFt(alt);
            p->setMach(mach);
            p->setSideSlip(slip);
            p->setGlideslope(gSlope);
            p->setLatDev(latDev);
            p->setCmdAirSpdKts(cmdSpd);
            p->setCmdAltFt(cmdAlt);
            p->setVVI(vvi);
            p->setFltDirBankDeg(fDirBank);
            p->setFltDirPitchDeg(fDirPitch);
            p->setBaroPress(baro);
        }
    }
}
