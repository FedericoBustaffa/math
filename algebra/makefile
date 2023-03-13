
CC = g++
CPPFLAGS = -Wall -std=c++17

TARGETS = algebra
OBJS = main.o mat.o vec.o 

all: $(TARGETS)

algebra: $(OBJS)
	$(CC) $^ -o $@

main.o: main.cpp 
mat.o: mat.h mat.cpp
vec.o: vec.h vec.cpp

clean:
	-rm *.o algebra 

recompile: clean all

run:
	./algebra
