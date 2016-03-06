CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: perm
	./perm

perm: permutacje.o
	g++ -Wall -pedantic -std=c++0x -o perm permutacje.o

permutacje.o: palindrom.cpp palindrom.hh
	g++ -c ${CXXFLAGS} -o permutacje.o palindrom.cpp

clean:
	rm *.o perm
