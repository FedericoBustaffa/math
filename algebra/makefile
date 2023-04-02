
CC = g++
CPPFLAGS = -Wall -std=c++17

TARGETS = algebra.x
OBJS = main.o

all: $(TARGETS)

algebra.x: $(OBJS)
	$(CC) $^ -o $@

main.o: mat.hpp core.hpp utility.hpp operations.hpp properties.hpp main.cpp

clean:
	-rm *.o algebra.x

recompile: clean all

run: algebra.x
	./$^

valrun: algebra.x
	valgrind -s --track-origins=yes ./algebra.x
