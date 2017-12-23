#
include ../makedefs

PGM = mainLaero

OBJS =  \
	main.o \
	AdiDisplay.o \
	factory.o \
	MapDisplay.o \
	MapPage.o \
	TestStation.o

LDFLAGS += -lmixr_interop_dis -lmixr_interop
LDFLAGS += -lmixr_models -lJSBSim
LDFLAGS += -lxzmq -l:libzmq.a
LDFLAGS += -lmixr_simulation -lmixr_models -lmixr_terrain
LDFLAGS += -lmixr_ui_glut -lmixr_instruments -lmixr_graphics -lmixr_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
LDFLAGS += -lrt

all: edl $(PGM)

edl:
	cpp configs/test.epp >test.edl $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
