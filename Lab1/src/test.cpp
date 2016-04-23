#include "test.hh"
#include "array1.hh"
#include "array2.hh"
#include "array3.hh"
#include "timer.hh"
#include <iostream>

using namespace std;

void Test::run(int Argc, char* Argv[]) {
	    int numbers[]={10, 100, 1000, 10000, 100000};

	Arr_1 *array_1=new Arr_1(10);
	Arr_2 *array_2=new Arr_2(10);
	Arr_3 *array_3=new Arr_3(10);
	Timer *tim = new Timer();


for(int k=0; k<5; k++) {

    array_1=new Arr_1(10);
	array_2=new Arr_2(10);
	array_3=new Arr_3(10);

	tim->tim_start();
    for(int i=0; i<numbers[k]; i++)
    array_1->add_num(0);
	tim->tim_stop();

    cout<<"Czas wykonania dla algorytmu n=n+1 dla "<<numbers[k]<<" liczb wynosi "<<tim->return_time()<<"ms"<<endl;

    delete array_1;


	tim->tim_start();
    for(int i=0; i<numbers[k]; i++)
    array_2->add_num(0);
	tim->tim_stop();

    cout<<"Czas wykonania dla algorytmu n=n*2 dla "<<numbers[k]<<" liczb wynosi "<<tim->return_time()<<"ms"<<endl;

    delete array_2;

	tim->tim_start();
    for(int i=0; i<numbers[k]; i++)
    array_3->add_num(0);
	tim->tim_stop();

    cout<<"Czas wykonania dla algorytmu n=n+100 dla "<<numbers[k]<<" liczb wynosi "<<tim->return_time()<<"ms"<<endl;

    delete array_3;
}
	delete tim;

}
