#
include ../makedefs

PGM = testMetaObject
OBJS =  main.o

LDFLAGS += -lmixr_base

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	@echo "No input files to process"

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
