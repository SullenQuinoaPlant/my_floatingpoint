ifndef ROOT
 ROOT := ..
 include $(ROOT)/Makefile
endif

TEST_SRCS := $(wildcard $(UTEST_DIR)/*.test.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
#BUILD_STAMPS := $(TEST_OBJS:.o=.build.stamp)
EXECUTION_STAMPS := $(TEST_OBJS:.o=.execution.stamp)

CFLAGS_UTEST = -fno-builtin -g
CFLAGS_UTEST += $(CFLAGS_MORE) #$(CFLAGS) were annoying the hell out of me




############
#BUILD TESTS

.PHONY : build_tests
build_tests : set_utest_flags def cmocka $(TEST_OBJS)

.PHONY : set_utest_flags
set_utest_flags :
	$(eval CFLAGS += $(CFLAGS_UTEST))

.PHONY : cmocka
cmocka : 
	@if $(CC) $(CFLAGS_UTEST)\
		-I $(LIBS_I) -L $(LIBS_L)\
	 	$(UTEST_DIR)/cmocka/check_install.c\
		 -lcmocka_shared -o test.o\
		-Wl,-rpath=$$(readlink -e $(LIBS_L))\
		&& ./test.o .;\
	then\
		@rm ./test.o;\
		echo "cmocka already installed";\
	else\
		echo "installing cmocka";\
		$(MAKE) -C $(UTEST_DIR)/cmocka/;\
		-mv $(UTEST_DIR)/cmocka/libcmocka_shared.* \
			$(LIBS_L)/;\
		mv $(UTEST_DIR)/cmocka/cmocka.h $(LIBS_I)/;\
		echo "cmocka installed";\
	fi


$(UTEST_DIR)/%.test.o :\
$(UTEST_DIR)/%.test.c $(LIBS_L)/$(LIBNAME).a
	$(CC) $(CFLAGS_UTEST)\
		-I $(SRC_DIR) -I $(INC_DIR)\
		-I $(LIBS_I)\
		-D $(ARCH)\
		$<\
		-L $(LIBS_L)\
		-l$(NAME)\
		-lcmocka_shared -lft\
		-lm\
		-o $@\
		-Wl,-rpath=$(LIBS_L)




############
#RUN TESTS :

.PHONY : unit-tests ut
unit-tests ut : list_tests build_tests run_tests

.PHONY : run_tests
run_tests : $(EXECUTION_STAMPS)

%.execution.stamp : %.o
	-./$*.o "$(UTEST_DIR)" \
	&& touch $@
#argument used to be
#	"$$(readlink -e $(UTEST_DIR))" \



###############
#MISCELLANEOUS:

.PHONY : all_unit_tests aut
all_unit_tests aut : clean-tests ut



.PHONY : clean-tests
clean-tests :
	-rm $(UTEST_DIR)/*.o
	-rm $(UTEST_DIR)/*.stamp



.PHONY : list_tests
list_tests :
	@echo "source dir is : $(SRC_DIR)"
	@echo "list of test sources:"
	@echo $(TEST_SRCS)
	@echo "list of test objects:"
	@echo $(TEST_OBJS)
