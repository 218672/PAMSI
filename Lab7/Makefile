CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

test: obj obj/main.o obj/graph.o obj/test.o
	g++ -Wall -pedantic -std=c++0x -o test obj/main.o obj/graph.o obj/test.o

obj/main.o: src/main.cpp inc/test.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/graph.o: inc/graph.hh src/graph.cpp
	g++ -c ${CXXFLAGS} -o obj/graph.o src/graph.cpp

obj/test.o: inc/test.hh inc/graph.hh inc/timer.hh src/test.cpp
	g++ -c ${CXXFLAGS} -o obj/test.o src/test.cpp

clean:
	rm obj/*.o test

