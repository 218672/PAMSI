CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

test: obj/main.o obj/array1.o obj/array2.o obj/array3.o obj/test.o
	g++ -Wall -pedantic -std=c++0x -o test obj/main.o obj/array1.o obj/array2.o obj/array3.o obj/test.o

obj/main.o: inc/test.hh src/main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/array1.o: inc/iarray.hh inc/array1.hh src/array1.cpp
	g++ -c ${CXXFLAGS} -o obj/array1.o src/array1.cpp

obj/array2.o: inc/iarray.hh inc/array2.hh src/array2.cpp
	g++ -c ${CXXFLAGS} -o obj/array2.o src/array2.cpp

obj/array3.o: inc/iarray.hh inc/array3.hh src/array3.cpp
	g++ -c ${CXXFLAGS} -o obj/array3.o src/array3.cpp

obj/test.o: inc/array1.hh inc/array2.hh inc/array3.hh inc/timer.hh inc/test.hh src/test.cpp
	g++ -c ${CXXFLAGS} -o obj/test.o src/test.cpp

clean:
	rm obj/*.o test

