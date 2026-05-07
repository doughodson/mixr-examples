
include ../makedefs

PGM = mainSim1

OBJS = main.o

EDLS = test0.edl
EDLS += test1.edl
EDLS += test2.edl
EDLS += test3.edl
EDLS += test4.edl

LDFLAGS += -lxzmq -l:libzmq.a
LDFLAGS += -lmixr_interop_dis -lmixr_interop
LDFLAGS += -lmixr_ighost_cigi -lmixr_ighost_flightgear
LDFLAGS += -lmixr_models_jsbsim -lmixr_models -lJSBSim
LDFLAGS += -lmixr_simulation
LDFLAGS += -lmixr_terrain -lmixr_base
LDFLAGS += -lcigicl
LDFLAGS += -lrt -lpthread

CPPFLAGS += -I/usr/local/include

EPPFLAGS +=  -I.

all: $(EDLS) $(PGM)

run: all
	echo "mainSim1 -f test0.edl"
	./$(PGM) -f test0.edl
	echo "mainSim1 -f test1.edl"
	./$(PGM) -f test1.edl
	echo "mainSim1 -f test2.edl"
	./$(PGM) -f test2.edl
	echo "mainSim1 -f test3.edl"
	./$(PGM) -f test3.edl
	echo "mainSim1 -f test4.edl"
	./$(PGM) -f test4.edl

$(EDLS):
	cpp configs/$(basename $@).epp > $@ $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
