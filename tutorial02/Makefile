#
include ../makedefs

PGM = tutorial02

OBJS = main.o Rng.o

LDFLAGS += -lmixr_base -lpthread

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	@echo "No input files to process"

clean:
	-rm -f *.o
	-rm -f $(PGM)
