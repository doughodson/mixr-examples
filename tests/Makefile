
include ../makedefs

PGM = tests

OBJS = main.o test_readout_utils.o

LDFLAGS += -lmixr_base -lmixr_graphics
LDFLAGS += -lrt -lpthread

CPPFLAGS += -I/usr/local/include

EPPFLAGS +=  -I.

all: edl $(PGM)

edl:
	cpp configs/testAngles.epp     > testAngles.edl $(EPPFLAGS)
	cpp configs/testFileReader.epp > testFileReader.edl $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
