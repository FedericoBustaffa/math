
CC = g++
CPPFLAGS = -Wall -std=c++17

TARGETS = algebra.x
OBJS = main.o vec.o

all: $(TARGETS)

algebra.x: $(OBJS)
	$(CC) $^ -o $@

main.o: main.cpp
vec.o: vec.h vec.cpp

clean:
	-rm *.o algebra.x

recompile: clean all

run: algebra.x
	./$^
