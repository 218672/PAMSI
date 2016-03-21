CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

test: test.o algorytmy.o 
	g++ -Wall -pedantic -std=c++0x -o test test.o algorytmy.o

test.o: struktura.hh algorytmy.hh test.cpp 
	g++ -c ${CXXFLAGS} -o test.o test.cpp

algorytmy.o: struktura.hh algorytmy.hh algorytmy.cpp
	g++ -c ${CXXFLAGS} -o algorytmy.o algorytmy.cpp

clean:
	rm *.o test
