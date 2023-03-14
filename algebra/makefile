
CC = g++
CPPFLAGS = -Wall -std=c++17

TARGETS = algebra.x
OBJS = main.o 

all: $(TARGETS)

algebra.x: $(OBJS)
	$(CC) $^ -o $@

main.o: main.cpp mat.h

clean:
	-rm *.o algebra.x

recompile: clean all

run: algebra.x
	./$^
