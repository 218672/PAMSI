#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void show_menu() {
    cout<<"Co chcesz zrobić?"<<endl<<endl;
    cout<<"1 - Wypelnij tablice losowymi liczbami z przedzialu (0,x)"<<endl;
    cout<<"2 - Wyswietl zawartosc tablicy"<<endl;
    cout<<"3 - Wyswietl wartosc maksymalna w tablicy"<<endl;
    cout<<"4 - Zakoncz dzialanie"<<endl;
    cout<<"Twoj wybor: ";
}

void fill_tab(int *tab[], int m, int n) {
    int x;
    cout<<"Podaj wartosc koncowa przedzialu: ";
    cin>>x;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
        tab[i][j]=(rand()%x)+0;
        }
    }
}

void show_tab(int *tab[], int m, int n) {
    int number;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
        number=tab[i][j];
        cout<<number<<" ";
        }
        cout<<endl;
    }
}

int find_max(int *tab[], int m, int n) {
    int number_1=0;
    int number_2;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
        number_2=tab[i][j];
        if(number_2>number_1)
        number_1=number_2;
        }
    }
    return number_1;
}

int main() {
srand(time(NULL));

int m,n; // wymiary tablicy
int state=0; // zmienna stanu

cout<<"Podaj wymiary tablicy:"<<endl;
cout<<"Wiersze: "; cin>>m;
cout<<"Kolumny: "; cin>>n; cout<<endl;

int **tab_2d = new int *[n];
for(int i=0; i<n; i++)
    tab_2d[i]=new int[m];

while(1) {
    show_menu();
    cin>>state;
    switch(state) {
    case 1:
        fill_tab(tab_2d, m, n);
        break;
    case 2:
        show_tab(tab_2d, m, n);
        break;
    case 3:
        int number;
        cout<<"Najwieksza liczba w tablicy to: ";
        number=find_max(tab_2d, m, n);
        cout<<number<<endl;
        break;
    case 4:
        for(int i=0; i<n; i++)
        delete []tab_2d[i];
        delete []tab_2d;
        cout<<"Do widzenia!"<<endl;
        return 0;
    default:
        cout<<"Bledna opcja!"<<endl;
        break;
    }
}

}
