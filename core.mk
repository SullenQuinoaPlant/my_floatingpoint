ifndef ROOT
 ROOT := .
 include $(ROOT)/make_vars.mk
endif

all : $(OUT_DIR_LIB)/$(LIBNAME).a header

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))


.PHONY : header
header : $(OUT_DIR_H)/$(LIBNAME).h

$(OUT_DIR_H)/$(LIBNAME).h : $(INC_DIR)/$(NAME).h 
	sed \
		-e '4s/\(myfloatingpoint\)/lib\1/' \
		-e '13,14s/\(FLOATING\)/LIB\1/' \
		$(INC_DIR)/$(NAME).h > $@

$(OUT_DIR_LIB)/$(LIBNAME).a : $(OBJS)
	-ar rcs $@ $^

#compilation :
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)\
		-I $(LIBS_I)\
		-o $@ -c $<


.PHONY : re fclean clean all
clean :
	-rm $(OBJS)
	-rm $(OBJ_DIR)/$(NAME).o

fclean : clean
	-rm $(OUT_DIR_LIB)/$(LIBNAME).a
	-rm $(OUT_DIR_H)/$(LIBNAME).h

re : fclean all
