#
include ../makedefs

PGM = tutorial04

OBJS =	\
	rngs/AbstractRng.o \
	rngs/Exponential.o \
	rngs/Lognormal.o \
	rngs/Uniform.o \
	main.o

LDFLAGS += -lmixr_base -lpthread -lrt

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	@echo "No input files to process"

clean:
	-rm -f rngs/*.o
	-rm -f *.o
	-rm -f $(PGM)
