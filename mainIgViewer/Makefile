#
include ../makedefs

PGM = mainIgViewer

OBJS = \
	SimpleIGen.o \
	SimStation.o \
	main.o \
	factory.o


CPPFLAGS += -DOSG_LIBRARY_STATIC

LDFLAGS += -lmixr_models_jsbsim -lmixr_models -lJSBSim
LDFLAGS += -lmixr_simulation -lmixr_terrain
LDFLAGS += -lmixr_ui_glut -lmixr_graphics -lmixr_base -lmixr_ighost_pov

LDFLAGS += -losgdb_txp -losgText -losgSim -losgViewer -losgUtil -losgGA -losgDB -losg -lOpenThreads -ldl

LDFLAGS += -lfontconfig -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

all: edl $(PGM)

edl:
	cpp configs/test.epp > test.edl $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)

