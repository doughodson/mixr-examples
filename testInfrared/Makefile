#
include ../makedefs

PGM = testInfrared

OBJS =	factory.o TestComputer.o TestDisplay.o TestStation.o main.o

LDFLAGS += -lmxrp_interop_dis -lmxrp_interop
LDFLAGS += -lmxrp_models -lmxrp_simulation -lmxrp_instruments -lJSBSim
LDFLAGS += -lmxrp_iodevice -lmxrp_otw -lmxrp_terrain
LDFLAGS += -lmxrp_gui_glut -lmxrp_graphics -lmxrp_base -lftgl -lfreetype -lcigicl
LDFLAGS += -lglut -lGLU -lGL -lX11
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lpthread -lrt

CPPFLAGS += -I/usr/local/include

EPPFLAGS += -I.

all: $(PGM)

edl:
	cpp configs/test1.epp > test1.edl $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
