
CC = g++
CPPFLAGS = -Wall -std=c++17

TARGETS = algebra.x
OBJS = main.o mat2.o

all: $(TARGETS)

algebra.x: $(OBJS)
	$(CC) $^ -o $@

main.o: main.cpp
mat2.o: mat2.h mat2.cpp

clean:
	-rm *.o algebra.x

recompile: clean all

run: algebra.x
	./$^
