CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

perm: permut.o palindrom.o
	g++ -Wall -pedantic -std=c++0x -o perm permut.o palindrom.o

permut.o: permut.cpp palindrom.hh
	g++ -c ${CXXFLAGS} -o permut.o permut.cpp

palindrom.o: palindrom.cpp palindrom.hh
	g++ -c ${CXXFLAGS} -o palindrom.o palindrom.cpp

clean:
	rm *.o perm
