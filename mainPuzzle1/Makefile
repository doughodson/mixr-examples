#
include ../makedefs

PGM = mainPuzzle1

OBJS =  Blocks.o PuzzleBoard.o factory.o main.o Controller.o State.o

EDLS = puzzle.edl

LDFLAGS += -lmixr_ui_glut -lmixr_graphics -lmixr_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

all: $(EDLS) $(PGM)

run: all
	echo "mainPuzzle1 -f puzzle.edl"
	./$(PGM) -f puzzle.edl

$(EDLS):
	cpp configs/$(basename $@).epp > $@ $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
