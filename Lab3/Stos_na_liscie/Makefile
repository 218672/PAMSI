CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

test: obj/test.o
	g++ -Wall -pedantic -std=c++0x -o test obj/test.o

obj/test.o: inc/list.hh inc/stack1.hh src/test.cpp 
	g++ -c ${CXXFLAGS} -o obj/test.o src/test.cpp

clean:
	rm obj/*.o test
