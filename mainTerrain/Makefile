#
include ../makedefs

PGM = mainTerrain
OBJS = Display.o factory.o main.o

LDFLAGS += -lmxrp_terrain -lmxrp_simulation
LDFLAGS += -lmxrp_gui_glut -lmxrp_graphics -lmxrp_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/test.epp >test.edl  $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
