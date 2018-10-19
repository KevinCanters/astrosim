CC := g++
CCFLAGS := -std=c++11 -O3
RM := rm -f

all: simulation

debug: CCFLAGS += -g
debug: simulation

simulation: help-functions.o fileio.o drivers.o star.o integrators.o main.o
	$(CC) -o simulation help-functions.o fileio.o drivers.o star.o integrators.o main.o

drivers.o: headers/drivers.cpp headers/drivers.h
	$(CC) -c headers/drivers.cpp $(CCFLAGS)

fileio.o: headers/fileio.cpp headers/fileio.h
	$(CC) -c headers/fileio.cpp $(CCFLAGS)

help-functions.o: headers/help-functions.cpp headers/help-functions.h
	$(CC) -c headers/help-functions.cpp $(CCFLAGS)

star.o: headers/star.cpp headers/star.h
	$(CC) -c headers/star.cpp $(CCFLAGS)

integrators.o: headers/integrators.cpp headers/integrators.h
	$(CC) -c headers/integrators.cpp $(CCFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp $(CCFLAGS)

clean:
	$(RM) simulation *.o
