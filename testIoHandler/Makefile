#
include ../makedefs

PGM = testIoHandler

OBJS = Display.o Table.o factory.o main.o

LDFLAGS += -lmixr_iodevice -lmixr_ui_glut -lmixr_graphics -lmixr_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/test1.epp >test1.edl $(EPPFLAGS)
	cpp configs/test2.epp >test2.edl $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
