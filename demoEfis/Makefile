#
include ../makedefs

PGM = demoEfis

OBJS = TestElectronic.o TestMechanical.o main.o

LDFLAGS += -lmxrp_gui_glut -lmxrp_instruments -lmxrp_graphics -lmxrp_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

all: $(PGM)

edl:
	cpp configs/glutdisplay.epp > glutdisplay.edl   $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
