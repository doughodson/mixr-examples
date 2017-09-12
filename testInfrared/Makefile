#
include ../makedefs

PGM = testInfrared

OBJS =	factory.o TestComputer.o TestDisplay.o TestStation.o main.o

LDFLAGS += -lmixr_interop_dis -lmixr_interop
LDFLAGS += -lmixr_models -lmixr_simulation -lmixr_instruments -lJSBSim
LDFLAGS += -lmixr_iodevice
LDFLAGS += -lmixr_ig_cigi -lmixr_ig_viewpoint -lmixr_ig
LDFLAGS += -lmixr_terrain
LDFLAGS += -lmixr_ui_glut -lmixr_graphics -lmixr_base -lftgl -lfreetype -lcigicl
LDFLAGS += -lglut -lGLU -lGL -lX11
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lpthread -lrt

CPPFLAGS += -I/usr/local/include

EPPFLAGS += -I.

all: $(PGM)

edl:
	cpp configs/test1.epp > test1.edl $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
