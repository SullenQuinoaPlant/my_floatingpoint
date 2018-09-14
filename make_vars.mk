NAME = myfloatingpoint
LIBNAME = libmyfloatingpoint
GIT_REPO = https://github.com/SullenQuinoaPlant/my_floatingpoint.git

CALL_DIR := $(shell pwd)
SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/objects
LIB_DIR := $(ROOT)/libs
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes
OUT_DIR_LIB := $(LIBS_L)
OUT_DIR_H := $(LIBS_I)

include $(ROOT)/targets.mk

CC := gcc
ifndef ARCH
	ARCH := ARCH_A
endif
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -D $(ARCH) -I $(INC_DIR)
endif
CFLAGS += $(CFLAGS_MORE)

DEPENDENCIES = libft

UTEST_DIR := $(ROOT)/unit-tests
DEBUG_DIR := $(ROOT)/debug
