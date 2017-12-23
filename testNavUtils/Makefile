#
include ../makedefs

PGM = testNavUtils
OBJS =  main.o

LDFLAGS += -lmixr_base

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
