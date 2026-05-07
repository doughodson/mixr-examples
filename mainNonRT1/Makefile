
include ../makedefs

PGM = mainNonRT1

OBJS = main.o

EDLS  = test1.edl
EDLS += test2.edl

LDFLAGS += -lmixr_models_jsbsim -lmixr_models -lJSBSim
LDFLAGS += -lmixr_simulation
LDFLAGS += -lmixr_instruments -lmixr_terrain
LDFLAGS += -lmixr_base
LDFLAGS += -lrt -lX11
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lpthread

CPPFLAGS += -I/usr/local/include

all: $(EDLS) $(PGM)

run: all
	./$(PGM) -f test1.edl
	./$(PGM) -f test2.edl

$(EDLS):
	cpp configs/$(basename $@).epp > $@ $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
