
CC = g++
CPPFLAGS = -Wall -std=c++17

TARGETS = algebra.x
OBJS = main.o mat.o

all: $(TARGETS)

algebra.x: $(OBJS)
	$(CC) $^ -o $@

main.o: main.cpp
mat.o: mat.hpp mat.cpp

clean:
	-rm *.o algebra.x

recompile: clean all

run: algebra.x
	./$^
