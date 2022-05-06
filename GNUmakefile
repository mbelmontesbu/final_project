# get all the sources and the headers
SOURCE := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)

# create the list of objects by replacing the .cpp with .o for the
# sources
OBJECTS := $(SOURCE:.cpp=.o)

# we have 2 targets here, which means two main() functions.  We need
# to exclude these from the general list of sources / objects, so we
# filter them out
MAINS := wordle_project.o
OBJECTS := $(filter-out $(MAINS), $(OBJECTS))

# by default, debug mode will be disabled
DEBUG ?= FALSE

CXXFLAGS := -Wall -Wextra -Wpedantic -Wshadow -g

ifeq (${DEBUG}, TRUE)
   CXXFLAGS += -g -DDEBUG
else
   CXXFLAGS += -DNDEBUG -O3
endif


# general rule for compiling a .cpp file to .o
%.o : %.cpp ${HEADERS}
	g++ ${CXXFLAGS} -c $<

wordle_project: wordle_project.o ${OBJECTS}
	g++ -o $@ wordle_project.o ${OBJECTS}

gen_random_word: gen_random_word.o $(OBJECTS)
	g++ -o $@ gen_random_word.o ${OBJECTS}

get_entry: get_entry.o $(OBJECTS)
	g++ -o $@ get_entry.o $(OBJECTS)

# 'make clean' will erase all the intermediate objects
clean:
	rm -f *.o wordle_project gen_random_word get_entry