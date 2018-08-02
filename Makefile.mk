ifndef ROOT
 ROOT := .
 include $(ROOT)/make_vars.mk
endif

all : $(OUT_DIR_LIB)/$(LIBNAME).a

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))


#packaging :
$(OUT_DIR_LIB)/$(LIBNAME).a : $(OBJ_DIR)/$(NAME).o
	-ar rcs $@ $<
	cp $(SRC_DIR)/$(NAME).h $(OUT_DIR_H)/$(LIBNAME).h

#linking :
$(OBJ_DIR)/$(NAME).o : $(OBJS)
	ld -r $^ -o $@

#compilation :
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | objdir
	$(CC) $(CFLAGS)\
		-I $(LIBS_I)\
		-o $@ -c $<

.PHONY : objdir
objdir :
	@if [ ! -d $(OBJ_DIR) ]; then\
		mkdir $(OBJ_DIR);\
	fi

#specifc file dependencies:

clean :
	-rm $(OBJS)
	-rm $(OBJ_DIR)/$(NAME).o

fclean : clean
	-rm $(OUT_DIR_LIB)/$(LIBNAME).a
	-rm $(OUT_DIR_H)/$(LIBNAME).h

re : fclean all

.PHONY : re fclean clean all
