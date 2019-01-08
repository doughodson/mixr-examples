#
include ../../makedefs

LIB = $(MIXR_EXAMPLES_LIB_PATH)/libxbehaviors.a

OBJS += \
	factory.o \
	PlaneAction.o \
	PlaneBehaviors.o \
	PriorityArbiter.o \
	PlaneState.o

.PHONY: all clean

all: $(LIB)

$(LIB) : $(OBJS)
	ar rs $@ $(OBJS)

clean:
	-rm -f *.o
	-rm -f $(LIB)
