#
include ../makedefs

PGM = testDafif

OBJS =  \
	models/NavRadios.o \
	models/WorldModel.o \
	AirportTests.o \
	NavaidTests.o \
	WaypointTests.o \
	testDafif.o
    
LDFLAGS += -lmxrp_models -lmxrp_simulation -lmxrp_dafif -lmxrp_terrain -lmxrp_base 
LDFLAGS += -lpthread -lrt

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm models/*.o
	-rm -f *.o
	-rm -f $(PGM)
