#include "runnable.hh"
#include <iostream>
#include <algorithm>
#include "struktura.hh"
#include "algorytmy.hh"
#include "queue1.hh"

void Runnable::run() {

srand(time(NULL));
int size_of_queue[]={10, 100, 1000, 1000000};
Queue<int>* que_1=NULL;
Array *arr_1 = NULL;
int size_of_arr;

for(int k=0; k<4; k++) {


Timer *tim = new Timer();

for(int state=1; state<=4; state++) {

    switch(state) {
    case 1:

    que_1 = new Queue<int>(size_of_queue[k]);

    size_of_arr=que_1->size();

    delete que_1;

    arr_1 = new Array(size_of_arr);

    for(int i=0; i<size_of_arr; i++)
    arr_1->add_num((std::rand()%1000)+0);

    tim->tim_start();
    arr_1->quick_sort_random(0, size_of_arr-1);
    tim->tim_stop();

    std::cout<<"Czas sortowania quicksort z wybraniem środkowego elementu dla "<<size_of_arr<<" elementów wynosi "<<tim->return_time()<<"ms"<<std::endl<<std::endl;

    delete arr_1;

    break;

    case 2:

    que_1 = new Queue<int>(size_of_queue[k]);

    size_of_arr=que_1->size();

    delete que_1;

    arr_1 = new Array(size_of_arr);

    for(int i=0; i<size_of_arr; i++)
    arr_1->add_num((std::rand()%1000)+0);

    tim->tim_start();
    arr_1->quick_sort_last(0, size_of_arr-1);
    tim->tim_stop();

    std::cout<<"Czas sortowania quicksort z wybraniem skrajnego elementu dla "<<size_of_arr<<" elementów wynosi "<<tim->return_time()<<"ms"<<std::endl<<std::endl;

    delete arr_1;

    break;

    case 3:

    que_1 = new Queue<int>(size_of_queue[k]);

    size_of_arr=que_1->size();

    delete que_1;

    arr_1 = new Array(size_of_arr);

    for(int i=0; i<size_of_arr; i++)
    arr_1->add_num((std::rand()%1000)+0);

    tim->tim_start();
    arr_1->quick_sort_mean(0, size_of_arr-1);
    tim->tim_stop();

    std::cout<<"Czas sortowania quicksort z wybraniem elementu jako mediany dla "<<size_of_arr<<" elementów wynosi "<<tim->return_time()<<"ms"<<std::endl<<std::endl;

    delete arr_1;

    break;

    case 4:

    que_1 = new Queue<int>(size_of_queue[k]);

    size_of_arr=que_1->size();

    delete que_1;

    arr_1 = new Array(size_of_arr);

    for(int i=0; i<size_of_arr; i++)
    arr_1->add_num((std::rand()%1000)+0);

    tim->tim_start();
    arr_1->merge_sort(0, size_of_arr-1);
    tim->tim_stop();

    std::cout<<"Czas sortowania mergesort dla "<<size_of_arr<<" elementów wynosi "<<tim->return_time()<<"ms"<<std::endl<<std::endl;

    delete arr_1;

    break;

    default:
    std::cout<<"Nie ma takiej opcji!"<<std::endl;
    break;
    }

}

}

}
