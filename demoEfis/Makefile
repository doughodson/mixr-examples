#
include ../makedefs

PGM = demoEfis

OBJS = TestElectronic.o TestMechanical.o main.o

LDFLAGS += -lmixr_ui_glut -lmixr_instruments -lmixr_graphics -lmixr_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

all: edl $(PGM) 

edl:
	cpp configs/glutdisplay.epp > glutdisplay.edl   $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
