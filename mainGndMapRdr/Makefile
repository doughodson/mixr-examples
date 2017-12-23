#
include ../makedefs

PGM = mainGndMapRdr
OBJS = Display.o factory.o main.o RealBeamRadar.o TestStation.o

LDFLAGS += -lmixr_models -lJSBSim
LDFLAGS += -lmixr_terrain -lmixr_simulation
LDFLAGS += -lmixr_ui_glut -lmixr_graphics
LDFLAGS += -lmixr_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

all: edl $(PGM)

edl:
	cpp configs/test.epp >test.edl $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
