#
include ../makedefs

PGM = mainUbf1

#
OBJS = main.o
OBJS += SimStation.o TestDisplay.o
OBJS += TestIoHandler.o factory.o

LDFLAGS += -lmxrp_models -lJSBSim
LDFLAGS += -lxbehaviors -lxpanel
LDFLAGS += -lmxrp_interop_dis -lmxrp_interop -lmxrp_graphics -lmxrp_gui_glut -lmxrp_instruments -lmxrp_simulation
LDFLAGS += -lmxrp_iodevice -lmxrp_otw -lmxrp_terrain
LDFLAGS += -lJSBSim -lmxrp_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11
LDFLAGS += -lcigicl
LDFLAGS += -lpthread -lrt

CPPFLAGS += -I../
LDFLAGS  += -L$(MXRP_LIB_DIR)

EPPFLAGS += -I.

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/test00.epp > test00.edl $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
