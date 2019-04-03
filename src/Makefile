######################################################################
#  Project
######################################################################
PROJECT 	= firmware
BINARY		= firmware
BUILD_DIR	= ../dist

CFILES	= $(wildcard *.c)
DEVICE = stm32f070f6p6

VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
# End