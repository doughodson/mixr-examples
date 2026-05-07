#
include ../makedefs

PGM = mainCockpit

EDLS  = test1.edl

OBJS  = SimStation.o TestDisplay.o
OBJS += TestIoHandler.o
OBJS += factory.o main.o

LDFLAGS += -lmixr_interop_dis -lmixr_interop
LDFLAGS += -lxzmq -l:libzmq.a
LDFLAGS += -lxpanel
LDFLAGS += -lmixr_models_jsbsim -lmixr_models -lJSBSim
LDFLAGS += -lmixr_simulation -lmixr_instruments
LDFLAGS += -lmixr_linkage
LDFLAGS += -lmixr_ighost_cigi -l:libcigicl.a -lmixr_ighost_flightgear -lmixr_ighost_pov
LDFLAGS += -lmixr_terrain
LDFLAGS += -lmixr_ui_glut -lmixr_graphics -lmixr_graphics_ftgl -lmixr_base
LDFLAGS += -lprotobuf
LDFLAGS += -lftgl -lfreetype -lcigicl
LDFLAGS += -lglut -lGLU -lGL -lX11
LDFLAGS += -lpthread -lrt

CPPFLAGS += -I/usr/local/include

EPPFLAGS += -I.

all: $(EDLS) $(PGM)

run: all
	./$(PGM) -f test1.edl

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

$(EDLS):
	cpp configs/$(basename $@).epp > $@ $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
