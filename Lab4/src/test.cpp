#include <iostream>
#include <algorithm>
#include "struktura.hh"
#include "algorytmy.hh"
#include "queue.hh"
#include "queue1.hh"

int main() {
srand(time(NULL));
Timer *tim = new Timer();
int size_of_queue;
std::cout<<"Podaj ile liczb wpisac do tablicy: ";
std::cin>>size_of_queue;

while(std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(50, '\n');
    std::cout << "Wpisujemy tylko liczby typu int! ";
    std::cin >> size_of_queue;
}

Queue<int>* que_1 = new Queue<int>(size_of_queue);

int size_of_arr;
size_of_arr=que_1->size();

Arr_second_type *arr_1 = new Arr_second_type(size_of_arr);

delete que_1;

for(int i=0; i<size_of_arr; i++)
arr_1->add_num((std::rand()%100)+5);

   std::cout<<"Elementy przed posortowaniem: "<<std::endl;
    arr_1->show_arr();
   std::cout<<std::endl;
   std::cout<<std::endl;



delete tim;


    arr_1->quick_sort(0, size_of_arr-1);

    std::cout<<"Elementy po posortowaniu: "<<std::endl;
    arr_1->show_arr();
    std::cout<<std::endl;

delete arr_1;
}
