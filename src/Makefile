######################################################################
#  Project
######################################################################

BINARY		= firmware
SRCFILES	= main.c

DEVICES = stm32f070f6p6

VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=../libopencm3

all: elf bin

include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-config.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
# End