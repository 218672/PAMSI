CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

test: obj obj/main.o obj/list.o obj/hasharray.o obj/asarray.o obj/runnable.o
	g++ -Wall -pedantic -std=c++0x -o test obj/main.o obj/list.o obj/hasharray.o obj/asarray.o obj/runnable.o

obj/main.o: src/main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/asarray.o: src/asarray.cpp inc/list.hh inc/hasharray.hh inc/asarray.hh inc/timer.hh
	g++ -c ${CXXFLAGS} -o obj/asarray.o src/asarray.cpp

obj/hasharray.o: src/hasharray.cpp inc/hasharray.hh inc/list.hh inc/asarray.hh
	g++ -c ${CXXFLAGS} -o obj/hasharray.o src/hasharray.cpp

obj/list.o: src/list.cpp inc/list.hh
	g++ -c ${CXXFLAGS} -o obj/list.o src/list.cpp

obj/runnable.o: inc/runnable.hh inc/asarray.hh inc/list.hh inc/hasharray.hh inc/asarray.hh inc/timer.hh
	g++ -c ${CXXFLAGS} -o obj/runnable.o src/runnable.cpp

clean:
	rm obj/*.o test

