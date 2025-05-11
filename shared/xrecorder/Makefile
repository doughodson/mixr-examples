#
include ../../makedefs

LIB = $(MIXR_SHARED_LIB_PATH)/libxrecorder.a

OBJS += \
	proto/DataRecord.pb.cc \
	XDataRecorder.o \
	factory.o

.PHONY: all clean

all: $(LIB)

$(LIB) : $(OBJS)
	ar rs $@ $(OBJS)

clean:
	-rm -f proto/*.o
	-rm -f *.o
	-rm -f $(LIB)
