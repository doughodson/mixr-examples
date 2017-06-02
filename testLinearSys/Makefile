#
include ../makedefs

PGM = testLinearSys
OBJS = main.o

LDFLAGS += -lmxrp_linearsystem -lmxrp_base

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:

clean:
	-rm -f *.o
	-rm -f $(PGM)
