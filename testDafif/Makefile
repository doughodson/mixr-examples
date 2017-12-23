#
include ../makedefs

PGM = testDafif

OBJS =  \
	models/NavRadios.o \
	models/WorldModel.o \
	AirportTests.o \
	NavaidTests.o \
	WaypointTests.o \
	main.o
    
LDFLAGS += -lmixr_models -lmixr_simulation -lmixr_dafif -lmixr_terrain -lmixr_base 
LDFLAGS += -lpthread -lrt

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	@echo "No input files to process"

clean:
	-rm models/*.o
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
