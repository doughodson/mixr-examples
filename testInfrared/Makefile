#
include ../makedefs

PGM = testInfrared

OBJS =	factory.o TestComputer.o TestDisplay.o TestStation.o main.o

LDFLAGS += -lmixr_interop_dis -lmixr_interop
LDFLAGS += -lmixr_models_jsbsim -lmixr_models -lJSBSim
LDFLAGS += -lmixr_simulation -lmixr_instruments
LDFLAGS += -lmixr_linkage
LDFLAGS += -lmixr_ighost_cigi -lmixr_ighost_flightgear
LDFLAGS += -lmixr_terrain
LDFLAGS += -lmixr_ui_glut -lmixr_graphics -lmixr_graphics_ftgl
LDFLAGS += -lmixr_base -lftgl -lfreetype -lcigicl
LDFLAGS += -lglut -lGLU -lGL -lX11
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lpthread -lrt

CPPFLAGS += -I/usr/local/include

EPPFLAGS += -I.

all: edl $(PGM)

edl:
	cpp configs/test1.epp > test1.edl $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
