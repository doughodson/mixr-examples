#
include ../makedefs

PGM = testSlots

OBJS =  \
	Base.o \
	Derived.o \
	main.o

LDFLAGS += -lmixr_base -lpthread -lrt

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	@echo "No input files to process"

clean:
	-rm -f *.o
	-rm -f $(PGM)
