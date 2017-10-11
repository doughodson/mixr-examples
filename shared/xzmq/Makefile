#
include ../../makedefs

LIB = $(MIXR_EXAMPLES_LIB_PATH)/libxzmq.a

OBJS += \
	factory.o \
	ZeroMQContext.o \
	ZeroMQHandler.o

.PHONY: all clean

all: $(LIB)

$(LIB) : $(OBJS)
	ar rs $@ $(OBJS)

clean:
	-rm -f *.o
	-rm -f $(LIB)
	-rm -f *~
