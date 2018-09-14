ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif


.PHONY : libft
libft : $(LIB_DIR)/libft

$(LIB_DIR)/libft :
	git clone \
		--single-branch \
		-b release \
		--depth 1 \
		https://github.com/SullenQuinoaPlant/Libft.git $@
	$(MAKE) -C $@/
	cp $@/libft.a $(LIBS_L)
	cp $@/includes/libft.h $(LIBS_I)

.PHONY : clean-libft
clean-libft :
	-rm -rf libft
	-rm $(LIBS_I)/libft.h
	-rm $(LIBS_L)/libft.a
