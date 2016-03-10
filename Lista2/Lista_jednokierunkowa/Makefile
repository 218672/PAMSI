CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

test: test.o lista_jednokierunkowa.o
	g++ -Wall -pedantic -std=c++0x -o perm test.o lista_jednokierunkowa.o

test.o: test.cpp lista_jednokierunkowa.hh
	g++ -c ${CXXFLAGS} -o test.o test.cpp

lista_jednokierunkowa.o: lista_jednokierunkowa.cpp lista_jednokierunkowa.hh
	g++ -c ${CXXFLAGS} -o lista_jednokierunkowa.o lista_jednokierunkowa.cpp

clean:
	rm *.o test
