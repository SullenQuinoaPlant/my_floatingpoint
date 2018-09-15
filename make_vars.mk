TARGETS := \
	composition1 \
	composition2 \
	decomposition \
	decomposition_predicates \
	exp_bias \
	floorl \
	make_double \
	make_ldouble \
	predicates
NAME = myfloatingpoint
LIBNAME = libmyfloatingpoint

CALL_DIR := $(shell pwd)
SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/
LIB_DIR := $(ROOT)/
LIBS_L := $(LIB_DIR)/
LIBS_I := $(LIB_DIR)/includes
OUT_DIR_LIB := $(LIBS_L)
OUT_DIR_H := $(LIBS_I)/includes

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

CC := gcc
ifndef ARCH
	ARCH := ARCH_A
endif
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -D $(ARCH) -I $(INC_DIR)
endif
CFLAGS += $(CFLAGS_MORE)
