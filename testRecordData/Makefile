#
include ../makedefs

PGM = testRecordData

OBJS  = SimStation.o TestDisplay.o
OBJS += TestIoHandler.o
OBJS += factory.o main.o

LDFLAGS += -lmxrp_interop_dis -lmxrp_interop
LDFLAGS += -lmxrp_models
LDFLAGS += -lxrecorder -lxpanel
LDFLAGS += -lmxrp_recorder -lmxrp_terrain
LDFLAGS += -lmxrp_simulation -lmxrp_instruments
LDFLAGS += -lmxrp_iodevice -lmxrp_otw
LDFLAGS += -lmxrp_gui_glut -lmxrp_graphics -lmxrp_base
LDFLAGS += -lprotobuf -lJSBSim
LDFLAGS += -lftgl -lfreetype -lcigicl
LDFLAGS += -lglut -lGLU -lGL -lX11
LDFLAGS += -lpthread -lrt

CPPFLAGS += -I/usr/local/include

EPPFLAGS += -I.

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/test.epp >test.edl   $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
