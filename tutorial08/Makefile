#
include ../makedefs

PGM = tutorial08

OBJS = main.o Worm.o MyPager.o

LDFLAGS += -lmxrp_gui_glut -lmxrp_graphics -lmxrp_base
LDFLAGS += -lpthread -lftgl -lfreetype -lglut -lGLU -lGL -lrt

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	@echo "No input files to process"

clean:
	-rm -f *.o
	-rm -f $(PGM)
