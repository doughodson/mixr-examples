
include ../makedefs

PGM = mainNonRT2

OBJS = main.o

EDLS  = test1.edl
EDLS += test2.edl
EDLS += test3.edl

LDFLAGS += -lmixr_models
LDFLAGS += -lmixr_simulation
LDFLAGS += -lmixr_instruments -lmixr_terrain
LDFLAGS += -lmixr_base
LDFLAGS += -lrt -lX11
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lpthread

CPPFLAGS += -I/usr/local/include

all: $(EDLS) $(PGM)

run: all
	echo "mainNonRT2 -f test1.edl"
	./$(PGM) -f test1.edl
	echo "mainNonRT2 -f test2.edl"
	./$(PGM) -f test2.edl
	echo "mainNonRT2 -f test3.edl"
	./$(PGM) -f test3.edl

$(EDLS):
	cpp configs/$(basename $@).epp > $@ $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
