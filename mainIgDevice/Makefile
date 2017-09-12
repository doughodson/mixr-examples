#
include ../makedefs

PGM = mainIgDevice

OBJS = \
	SimpleIGen.o \
	SimStation.o \
	main.o \
	factory.o


LDFLAGS += -lmixr_interop_dis -lmixr_interop
LDFLAGS += -lmixr_models -lJSBSim
LDFLAGS += -lxzmq -l:libzmq.a
LDFLAGS += -lxpanel
LDFLAGS += -lmixr_recorder -lmixr_models
LDFLAGS += -lmixr_simulation -lmixr_instruments
LDFLAGS += -lmixr_iodevice
LDFLAGS += -lmixr_terrain
LDFLAGS += -lmixr_ui_glut -lmixr_graphics -lmixr_base

LDFLAGS += -losgViewer -losgDB -losgGA -losg

LDFLAGS += -lmixr_ig_viewpoint -lmixr_ig
LDFLAGS += -lmixr_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

all: $(PGM)

edl:
	cpp configs/test.epp > test.edl $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)

