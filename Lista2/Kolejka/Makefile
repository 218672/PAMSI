CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

test: test.o
	g++ -Wall -pedantic -std=c++0x -o test test.o

test.o: test.cpp kolejka.hh
	g++ -c ${CXXFLAGS} -o test.o test.cpp

clean:
	rm *.o test
