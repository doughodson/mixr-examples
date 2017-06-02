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

LDFLAGS += -lmxrp_interop_dis -lmxrp_interop
LDFLAGS += -lmxrp_models -lJSBSim
LDFLAGS += -lxzmq -l:libzmq.a
LDFLAGS += -lmxrp_simulation -lmxrp_models -lmxrp_terrain
LDFLAGS += -lmxrp_gui_glut -lmxrp_instruments -lmxrp_graphics -lmxrp_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
LDFLAGS += -lrt

all: $(PGM)

edl:
	cpp configs/test.epp >test.edl $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
