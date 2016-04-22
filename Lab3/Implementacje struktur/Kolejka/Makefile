CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

test: obj/main.o obj/runnable.o
	g++ -Wall -pedantic -std=c++0x -o test obj/main.o obj/runnable.o

obj/main.o: inc/runnable.hh src/main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/runnable.o: inc/runnable.hh inc/queue1.hh src/runnable.cpp
	g++ -c ${CXXFLAGS} -o obj/runnable.o src/runnable.cpp

clean:
	rm obj/*.o test
