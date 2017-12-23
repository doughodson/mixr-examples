
include ../makedefs

PGM = mainSim2

OBJS = \
	factory.o \
	InstrumentPanel.o \
	SimStation.o \
	SimIoHandler.o \
	SimPlayer.o \
	main.o

LDFLAGS += -lxzmq -l:libzmq.a
LDFLAGS += -lmixr_interop_dis -lmixr_interop -lmixr_models -lmixr_simulation -lJSBSim
LDFLAGS += -lmixr_instruments -lmixr_linkage
LDFLAGS += -lmixr_ighost_cigi -lmixr_ighost_pov
LDFLAGS += -lmixr_terrain
LDFLAGS += -lmixr_ui_glut -lmixr_graphics -lmixr_base -lrt -lcigicl
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lpthread

CPPFLAGS += -I/usr/local/include

EPPFLAGS +=  -I.

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/test0.epp >test0.edl $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
