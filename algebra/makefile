
CC = g++
CPPFLAGS = -Wall -std=c++17

TARGETS = algebra.x
OBJS = main.o vec.o mat.o

all: $(TARGETS)

algebra.x: $(OBJS)
	$(CC) $^ -o $@

main.o: main.cpp
vec.o: vec.hpp vec.cpp
mat.o: mat.hpp mat.cpp

clean:
	-rm *.o algebra.x

recompile: clean all

run: algebra.x
	./$^
