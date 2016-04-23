CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

test: obj/main.o obj/algorytmy.o obj/test.o
	g++ -Wall -pedantic -std=c++0x -o test obj/main.o obj/algorytmy.o obj/test.o

obj/main.o: inc/test.hh src/main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/algorytmy.o: inc/struktura.hh inc/algorytmy.hh src/algorytmy.cpp
	g++ -c ${CXXFLAGS} -o obj/algorytmy.o src/algorytmy.cpp

obj/test.o: inc/struktura.hh inc/algorytmy.hh src/test.cpp
	g++ -c ${CXXFLAGS} -o obj/test.o src/test.cpp

clean:
	rm obj/*.o test
