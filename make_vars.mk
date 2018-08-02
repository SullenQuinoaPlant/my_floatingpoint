NAME = myfloatingpoint
LIBNAME = libmyfloatingpoint

CALL_DIR := $(shell pwd)
SRC_DIR	:= $(ROOT)/
OBJ_DIR := $(ROOT)/
LIB_DIR := $(ROOT)/
LIBS_L := $(LIB_DIR)/
LIBS_I := $(LIB_DIR)/
OUT_DIR_LIB := $(LIBS_L)
OUT_DIR_H := $(LIBS_I)

include $(SRC_DIR)/targets.mk

CC := gcc
ifndef ARCH
	ARCH := ARCH_A
endif
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -D $(ARCH)
endif
CFLAGS += $(CFLAGS_MORE)
