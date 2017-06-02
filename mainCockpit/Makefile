#
include ../makedefs

PGM = mainCockpit

OBJS  = SimStation.o TestDisplay.o
OBJS += TestIoHandler.o
OBJS += factory.o main.o

LDFLAGS += -lmxrp_interop_dis -lmxrp_interop
LDFLAGS += -lmxrp_models -lJSBSim
LDFLAGS += -lxzmq -l:libzmq.a
LDFLAGS += -lxpanel
LDFLAGS += -lmxrp_recorder -lmxrp_models
LDFLAGS += -lmxrp_simulation -lmxrp_instruments
LDFLAGS += -lmxrp_iodevice -lmxrp_otw -lmxrp_terrain
LDFLAGS += -lmxrp_gui_glut -lmxrp_graphics -lmxrp_base
LDFLAGS += -lprotobuf -lJSBSim
LDFLAGS += -lftgl -lfreetype -lcigicl
LDFLAGS += -lglut -lGLU -lGL -lX11
LDFLAGS += -lpthread -lrt

CPPFLAGS += -I/usr/local/include
LDFLAGS  += -L../lib/linux -L$(MXRP_LIB_DIR)

EPPFLAGS += -I.

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/test1.epp >test1.edl   $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
