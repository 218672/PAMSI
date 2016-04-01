CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

test: obj/test.o obj/stos.o 
	g++ -Wall -pedantic -std=c++0x -o test obj/test.o obj/stos.o

obj/test.o: inc/list.hh inc/stos.hh src/test.cpp 
	g++ -c ${CXXFLAGS} -o obj/test.o src/test.cpp

obj/stos.o: inc/list.hh inc/stos.hh src/stos.cpp 
	g++ -c ${CXXFLAGS} -o obj/stos.o src/stos.cpp

clean:
	rm obj/*.o stos
