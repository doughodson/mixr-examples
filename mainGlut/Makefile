#
include ../makedefs

PGM = mainGlut

OBJS = main.o

EDLS = alignmentPattern.edl
EDLS += textDisplay.edl

LDFLAGS += -lmixr_ui_glut -lmixr_graphics_ftgl -lmixr_graphics -lmixr_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

all: $(EDLS) $(PGM)

run: all
	echo "mainGlut -f alignmentPattern.edl"
	./$(PGM) -f alignmentPattern.edl
	echo "mainGlut -f textDisplay.edl"
	./$(PGM) -f textDisplay.edl

$(EDLS):
	cpp configs/$(basename $@).epp > $@ $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)

