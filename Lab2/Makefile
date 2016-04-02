CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

test: obj/test.o obj/algorytmy.o 
	g++ -Wall -pedantic -std=c++0x -o test obj/test.o obj/algorytmy.o

obj/test.o: inc/struktura.hh inc/algorytmy.hh src/test.cpp 
	g++ -c ${CXXFLAGS} -o obj/test.o obj/test.cpp

obj/algorytmy.o: inc/struktura.hh inc/algorytmy.hh src/algorytmy.cpp
	g++ -c ${CXXFLAGS} -o inc/algorytmy.o src/algorytmy.cpp

clean:
	rm obj/*.o test
