CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

test: obj/main.o obj/test.o
	g++ -Wall -pedantic -std=c++0x -o test obj/main.o obj/test.o

obj/main.o: inc/test.hh src/main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/test.o: inc/test.hh inc/stack.hh src/test.cpp
	g++ -c ${CXXFLAGS} -o obj/test.o src/test.cpp

clean:
	rm obj/*.o test
