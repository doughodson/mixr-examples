#
include ../makedefs

PGM = mainCockpit

OBJS  = SimStation.o TestDisplay.o
OBJS += TestIoHandler.o
OBJS += factory.o main.o

LDFLAGS += -lmixr_interop_dis -lmixr_interop
LDFLAGS += -lmixr_models -lJSBSim
LDFLAGS += -lxzmq -l:libzmq.a
LDFLAGS += -lxpanel
LDFLAGS += -lmixr_recorder -lmixr_models
LDFLAGS += -lmixr_simulation -lmixr_instruments
LDFLAGS += -lmixr_linkage
LDFLAGS += -lmixr_ighost_cigi -lmixr_ighost_viewpoint
LDFLAGS += -lmixr_terrain
LDFLAGS += -lmixr_ui_glut -lmixr_graphics -lmixr_base
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
	cpp configs/test1.epp >test1.edl $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
