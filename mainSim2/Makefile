
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
LDFLAGS += -lmxrp_interop_dis -lmxrp_interop -lmxrp_models -lmxrp_simulation -lJSBSim
LDFLAGS += -lmxrp_instruments -lmxrp_iodevice -lmxrp_otw -lmxrp_terrain
LDFLAGS += -lmxrp_gui_glut -lmxrp_graphics -lmxrp_base -lrt -lcigicl
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lpthread

CPPFLAGS += -I/usr/local/include

EPPFLAGS +=  -I.

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/test0.epp >test0.edl $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
