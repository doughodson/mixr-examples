#
include ../makedefs

PGM = demoSubDisplays

OBJS =  \
	test_pages/TestAdi2.o \
	test_pages/TestAdi.o \
	test_pages/TestAlt.o \
	test_pages/TestButtons.o \
	test_pages/TestCas.o \
	test_pages/TestCompass.o \
	test_pages/TestDigitalGauge.o \
	test_pages/TestEngineDial.o \
	test_pages/TestEngPage.o \
	test_pages/TestFtitDial.o \
	test_pages/TestGauge1.o \
	test_pages/TestGMeterDial.o \
	test_pages/TestHsi.o \
	test_pages/TestLandingGear.o \
	test_pages/TestNozzle.o \
	test_pages/TestOilPressure.o \
	test_pages/TestRpmDial.o \
	test_pages/TestSpeedBrake.o \
	test_pages/TestVVI.o \
	main.o


LDFLAGS += -lmixr_instruments -lmixr_ui_glut -lmixr_graphics -lmixr_graphics_ftgl -lmixr_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/test.epp >test.edl $(EPPFLAGS)

clean:
	-rm -f test_pages/*.o
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
