#
include ../makedefs

PGM = testNetHandler

OBJS = Sender.o main.o Endpoint.o Echo.o ServerTcpMultiple.o

LDFLAGS += -lxzmq -l:libzmq.a
LDFLAGS += -lmixr_base -lftgl -lfreetype -lglut -lGLU -lGL -lX11 -lpthread
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	@echo "No input files to process"

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
