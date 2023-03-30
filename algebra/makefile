
CC = g++
CPPFLAGS = -Wall -std=c++17

TARGETS = algebra.x
OBJS = main.o

all: $(TARGETS)

algebra.x: $(OBJS)
	$(CC) $^ -o $@

main.o: mat.hpp mat_core.hpp mat_utility.hpp mat_operations.hpp mat_properties.hpp main.cpp

clean:
	-rm *.o algebra.x

recompile: clean all

run: algebra.x
	./$^

