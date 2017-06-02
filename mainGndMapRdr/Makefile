#
include ../makedefs

PGM = mainGndMapRdr
OBJS = Display.o factory.o main.o RealBeamRadar.o TestStation.o

LDFLAGS += -lmxrp_models -lJSBSim
LDFLAGS += -lmxrp_terrain -lmxrp_simulation
LDFLAGS += -lmxrp_gui_glut -lmxrp_graphics
LDFLAGS += -lmxrp_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

all: $(PGM)

edl:
	cpp configs/test.epp >test.edl $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
