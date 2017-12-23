#
include ../makedefs

PGM = testRecordData

OBJS  = SimStation.o TestDisplay.o
OBJS += TestIoHandler.o
OBJS += factory.o main.o

LDFLAGS += -lmixr_interop_dis -lmixr_interop
LDFLAGS += -lmixr_models
LDFLAGS += -lxrecorder -lxpanel
LDFLAGS += -lmixr_recorder -lmixr_terrain
LDFLAGS += -lmixr_simulation -lmixr_instruments
LDFLAGS += -lmixr_linkage
LDFLAGS += -lmixr_ighost_cigi -lmixr_ighost_pov
LDFLAGS += -lmixr_ui_glut -lmixr_graphics -lmixr_base
LDFLAGS += -lprotobuf -lJSBSim
LDFLAGS += -lftgl -lfreetype -lcigicl
LDFLAGS += -lglut -lGLU -lGL -lX11
LDFLAGS += -lpthread -lrt

CPPFLAGS += -I/usr/local/include

EPPFLAGS += -I.

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/test.epp >test.edl   $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
