CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

test: algorytmy.o
	g++ -Wall -pedantic -std=c++0x -o test algorytmy.o

algorytmy.o: algorytmy.cpp struktura.hh
	g++ -c ${CXXFLAGS} -o algorytmy.o algorytmy.cpp

clean:
	rm *.o test
