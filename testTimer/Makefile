#
include ../makedefs

PGM = testTimer

OBJS = main.o Tester.o

LDFLAGS += -lmixr_base
LDFLAGS += -lpthread -lrt

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	@echo "No input files to process"

clean:
	-rm -f *.o
	-rm -f $(PGM)
