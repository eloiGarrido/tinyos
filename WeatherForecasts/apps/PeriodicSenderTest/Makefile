COMPONENT=periodicSenderC

CC2420POWER=31
#CC2420POWER=15
#CC2420POWER=7

include $(MAKERULES)
include ../Makefile.radioconfig

CFLAGS += -DDISABLE_SYNCED_MICRO
CFLAGS += -DORINOCO_DEBUG_STATISTICS
#CFLAGS += -DORINOCO_DEBUG_PRINTF

CFLAGS += -DUSE_PRINTF

CFLAGS += \
	-I . \
	-I ../../../Orinoco/interfaces \
	-I ../../../Orinoco/lib/net/orinoco \
	-I ../../lib \
	-I ../../interfaces \
	-I ../../../Orinoco/LocalTimeSyncedMicro/lib \
	-I ../../../EAJobs/interfaces \
	-I ../../../EAJobs/lib \
	-I ../../../Tools \
	-I ../../../Reporting \
	-I $(TOSDIR)/lib/net \
	-I $(TOSDIR)/lib/printf \

ifeq ($(findstring $(PLATFORM),iris), iris)
CFLAGS += \
	-I ../../../Orinoco/chips/rf230  \
	-I ../../../Orinoco/platforms/iris \
	-I ../../../Orinoco/lib/rfxlink/layers \
	-I ../../../LocalTimeSyncedMicro/chips/atm1281 \
	-I ../../../LocalTimeSyncedMicro/chips/atm1281/timer
else ifeq ($(findstring $(PLATFORM),telosb), telosb)
CFLAGS += \
	-I ../../../Orinoco/chips/cc2420  \
	-I ../../../Orinoco/platforms/telosb \
	-I ../../../LocalTimeSyncedMicro/chips/msp430 \
	-I ../../../LocalTimeSyncedMicro/chips/msp430/timer
else ifeq ($(PLATFORM),)
	# No target, no worries.
else
$(error Platform "$(PLATFORM)" is not supported)
endif

LDFLAGS += ../../../Tools/Statistics.c
