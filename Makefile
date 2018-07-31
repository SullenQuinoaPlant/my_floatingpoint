.PHONY : def
def : targets
	$(MAKE) all


############
#VARIABLES :

ifndef ROOT
 ROOT := .
endif

include $(ROOT)/make_vars.mk


#######
#CORE :

include $(ROOT)/Makefile.mk


##########
#TARGETS :

include $(SRC_DIR)/Makefile


#######
#LIBS :

include $(LIB_DIR)/Makefile

########
#TESTS :
	
include $(UTEST_DIR)/Makefile


#########
#OUTPUT :

OUT = out_$(NAME)

.PHONY : clean-ft_printf
clean-ft_printf :
	if ! [ -d $(OUT) ]; then mkdir $(OUT); fi
	cp auteur $(OUT)/
	git clone -b the_lib --single-branch https://github.com/SullenQuinoaPlant/Libft.git $(OUT)/libft
	cp Makefile.mk $(OUT)/Makefile
	cp -r $(SRC_DIR)/ $(OUT)/


################
#MISCELLANEOUS :

.PHONY : gc
gc :
	git commit -a -m i

.PHONY : gcp
gcp :
	git commit -a -m i; git push;

.PHONY : grm
grm :
	git reset --hard && make
