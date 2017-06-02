include ../makedefs

PGM = testRecorderRead

OBJS = main.o DataRecordTest.o factory.o PrintMyData.o

LDFLAGS += -lmxrp_models -lJSBSim
LDFLAGS += -lxrecorder
LDFLAGS += -lmxrp_recorder -lmxrp_simulation
LDFLAGS += -lmxrp_terrain -lmxrp_base
LDFLAGS += -lprotobuf
LDFLAGS += -lrt -lpthread

CPPFLAGS += -I/usr/local/include

EPPFLAGS +=  -I.

all: $(PGM)

edl:
	cpp configs/test.epp >test.edl   $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) 

clean:
	-rm -f *.o
	-rm -f $(PGM)
