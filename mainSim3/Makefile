
include ../makedefs

PGM = mainSim3

OBJS = \
	Display.o \
	MapPage.o \
	Station.o \
	main.o

LDFLAGS += -lxzmq -l:libzmq.a
LDFLAGS += -lmixr_interop_dis -lmixr_interop -lmixr_models -lmixr_simulation -lJSBSim
LDFLAGS += -lmixr_instruments -lmixr_iodevice
LDFLAGS += -lmixr_ig_cigi -lmixr_ig_viewpoint -lmixr_ig
LDFLAGS += -lmixr_terrain
LDFLAGS += -lmixr_ui_glut -lmixr_graphics -lmixr_base -lrt -lcigicl
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lpthread

CPPFLAGS += -I/usr/local/include

EPPFLAGS +=  -I.

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/test.epp >test.edl $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
