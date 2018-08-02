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

include $(ROOT)/core.mk


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
#RELEASE :

RELEAS_DIR = release_$(NAME)

.PHONY : release
release :
	if ! [ -d $(RELEASE_DIR) ];\
	then mkdir $(RELEASE_DIR);\
	else rm -rf $(RELEASE_DIR)/;\
	fi
	cp auteur $(RELEASE_DIR)/
	cp Makefile.mk $(RELEASE_DIR)/Makefile
	cp -r $(SRC_DIR)/ $(RELEASE_DIR)/


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
	git reset --hard && make CFLAGS_MORE=-g
