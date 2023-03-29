
CC = g++
CPPFLAGS = -Wall -std=c++20

TARGETS = algebra.x
OBJS = main.o

all: $(TARGETS)

algebra.x: $(OBJS)
	$(CC) $^ -o $@

main.o: mat.hpp main.cpp

clean:
	-rm *.o algebra.x

recompile: clean all

run: algebra.x
	./$^

