#
include ../makedefs

PGM = tutorial08

OBJS = main.o Worm.o MyPager.o

LDFLAGS += -lmixr_ui_glut -lmixr_graphics -lmixr_base
LDFLAGS += -lpthread -lftgl -lfreetype -lglut -lGLU -lGL -lrt

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/file0.epp >file0.edl  $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
