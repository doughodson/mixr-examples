#
include ../makedefs

PGM = tutorial07

OBJS = main.o Worm.o

LDFLAGS += -lmixr_ui_glut -lmixr_graphics -lmixr_base
LDFLAGS += -lpthread -lftgl -lfreetype -lglut -lGLU -lGL -lrt

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	@echo "No input files to process"

clean:
	-rm -f *.o
	-rm -f $(PGM)
