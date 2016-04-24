CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

test: obj obj/main.o obj/tree.o obj/test.o
	g++ -Wall -pedantic -std=c++0x -o test obj/main.o obj/tree.o obj/test.o

obj/main.o: src/main.cpp inc/test.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/tree.o: inc/tree.hh src/tree.cpp
	g++ -c ${CXXFLAGS} -o obj/tree.o src/tree.cpp

obj/test.o: inc/test.hh inc/tree.hh inc/timer.hh src/test.cpp
	g++ -c ${CXXFLAGS} -o obj/test.o src/test.cpp

clean:
	rm obj/*.o test

