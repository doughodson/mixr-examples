#
include ../makedefs

PGM = testVmap

OBJS = \
		TestDisplay.o \
		main.o

LDFLAGS += -lmixr_map_vpf -lmixr_instruments -lmixr_ui_glut
LDFLAGS += -lmixr_graphics -lmixr_graphics_ftgl -lmixr_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11
#LDFLAGS += -lXmu -lXi
LDFLAGS += -lrt -lpthread

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $(PGM) $(OBJS) $(LDFLAGS)

edl:
	cpp configs/test.epp > test.edl   $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
