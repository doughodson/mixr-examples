#
include ../makedefs

PGM = testGraphics

OBJS = TdAzPtr.o TdElevPtr.o TestOne.o TestRotator.o TestTwo.o TestDisplay.o main.o

LDFLAGS += -lmixr_instruments -lmixr_ui_glut -lmixr_graphics -lmixr_base -lpthread
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11
#LDFLAGS += -lXi -lXmu
LDFLAGS += -lrt

EPPFLAGS += -DFONT_11_19_PATH="\"$(DATA_DIR)/fonts/11x19/normal/\""

all: edl $(PGM)

edl:
	cpp configs/test1.epp >test1.edl $(EPPFLAGS)
	cpp configs/test2.epp >test2.edl $(EPPFLAGS)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
