#names
OUT=eflevator
LIBDYOUT=lib$(OUT).so
LIBSTAOUT=lib$(OUT).a
CC=gcc

#flags
CPPFLAGS= -std=c11
CXXFLAGS= -W -Wall
DFLAGS= -O0 -g -g3
GCOVFLAGS= -O0 --coverage -ftest-coverage -fprofile-arcs
OPTIFLAGS= -O3
GTEST_LIBS= -lgtest_main -lgtest -lpthread

#links
LAPINLINKS=-L. -leflevator -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm -ldl -lpthread -lopencv_imgproc -lopencv_objdetect -lopencv_highgui -lopencv_video -lopencv_core -lavcall -lusb -lopencv_videoio

#options
LIBLAPIN=1
ifeq ($(DEBUG), 1)
	OPTFLAGS = $(DFLAGS)
endif
ifeq ($(GCOV), 1)
	OPTFLAGS += $(GCOVFLAGS)
endif
ifeq ($(OPTFLAGS),)
	OPTFLAGS = $(OPTIFLAGS)
endif

#others
INCLUDE=-I./include/
TESTINCLUDE=-I./test/include/

FLAGS=$(CPPFLAGS) $(CXXFLAGS) $(OPTFLAGS)

SRC=$(shell find src/ -name "*.c")
TESTSRC=$(shell find test/ -name "*.c")

OBJ=$(SRC:.c=.o)
TESTOBJ=$(TESTSRC:.c=.o)
TESTOUT=$(TESTOBJ:.o=.test)

MAKE=make re
##Rules##

all: cc

cc: $(OUT)

$(OUT): $(OBJ)
ifeq ($(LIBLAPIN), 1)
	$(CC) $(OBJ) $(INCLUDE) $(FLAGS) $(LAPINLINKS) -o $(OUT)
else
	$(CC) $(OBJ) $(INCLUDE) $(FLAGS) -o $(OUT)
endif

lib: $(LIBSTAOUT) $(LIBDYOUT)

$(LIBSTAOUT): $(OBJ)
	ar cr $(LIBSTAOUT) $(OBJ)

$(LIBDYOUT): $(OBJ)
	$(CC) -shared -o $(LIBDYOUT) $(OBJ)

test: $(LIBSTAOUT) $(TESTOBJ) $(TESTOUT)
ifeq ($(GCOV), 1)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
endif

report:
	gcov $(SRC)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report

.c.o:
	$(CC) -c $< $(INCLUDE) -o $@ $(FLAGS) -fPIC

%.test: %.o
ifeq ($(GTEST), 1)
ifeq ($(LIBLAPIN), 1)
	$(CC) $(INCLUDE) $< $(FLAGS) $(GTEST_LIBS) $(LIBSTAOUT) $(LAPINLINKS) -o $@
else
	$(CC) $(INCLUDE) $< $(FLAGS) $(GTEST_LIBS) $(LIBSTAOUT) -o $@
endif
else
ifeq ($(LIBLAPIN), 1)
	$(CC) $(INCLUDE) $< $(FLAGS) $(LIBSTAOUT) $(LAPINLINKS) -o $@
else
	$(CC) $(INCLUDE) $< $(FLAGS) $(LIBSTAOUT) -o $@
endif
endif
	./$@
ifeq ($(GCOV), 1)
	gcov $@
endif

clean:
	@rm -f $(OBJ)
	@rm -f $(TESTOBJ)
	@rm -f $(shell find ./ -name "*~")
	@rm -f $(shell find ./ -name "*.gcno")
	@rm -f $(shell find ./ -name "*.gcda")
	@rm -f $(shell find ./ -name "*.gcov")
	@rm -f vgcore*
	@rm -f coverage.info
	@rm -f -r report

fclean: clean
	@rm -f $(OUT)
	@rm -f test/test$(OUT)
	@rm -f $(LIBSTAOUT)
	@rm -f $(LIBDYOUT)
	@rm -f $(TESTOUT)

testclean:
	@rm -f test/*.test

re: fclean all

relib: fclean lib

retest: testclean test

resUpdate:
	@rm -f -r realClient/resours
	@rm -f -r realServer/resours
	cp -r ./resours realClient/resours
	cp -r ./resours realServer/resours

