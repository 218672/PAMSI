#include <iostream>
#include <fstream>

using namespace std;

void load_from_txt(int tab[], int n) {
ifstream plik;
string nazwa_pliku;

cout<<"Podaj nazwe pliku z ktorego chcesz wczytac dane: ";
cin>>nazwa_pliku;
plik.open(nazwa_pliku.c_str(), ios::in);
    if(plik.good()) {
        for(int i=0; i<n; i++)
        plik>>tab[i];
    plik.close();
    }
    else {
        cout<<"Nie udalo sie wczytac pliku "<<nazwa_pliku<<".txt"<<endl;
    }

}

void save_to_txt(int tab[], int n) {
fstream plik;
string nazwa_pliku;

cout<<"Podaj nazwe pliku do ktorego chcesz zapisac dane: ";
cin>>nazwa_pliku;
plik.open(nazwa_pliku.c_str(), ios::out | ios::trunc);
    if(plik.good()) {
        for(int i=0; i<n; i++)
        plik<<tab[i]<<" ";
    } else {
        cout<<"Nie uzyskano dostepu do pliku "<<nazwa_pliku<<".txt"<<endl;
    }

}

void load_from_bin(int tab[], int n) {
ifstream plik;
string nazwa_pliku;

cout<<"Podaj nazwe pliku z ktorego chcesz wczytac dane: ";
cin>>nazwa_pliku;
plik.open(nazwa_pliku.c_str(), ios::binary);
    if(plik.good()) {
        for(int i=0; i<n; i++)
        plik>>tab[i];
    plik.close();
    }
    else {
        cout<<"Nie udalo sie wczytac pliku "<<nazwa_pliku<<".txt"<<endl;
    }

}

void save_to_bin(int tab[], int n) {
fstream plik;
string nazwa_pliku;

cout<<"Podaj nazwe pliku do ktorego chcesz zapisac dane: ";
cin>>nazwa_pliku;
plik.open(nazwa_pliku.c_str(), ios::out | ios::binary | ios::trunc);
    if(plik.good()) {
        for(int i=0; i<n; i++)
        plik<<tab[i]<<" ";
    } else {
        cout<<"Nie uzyskano dostepu do pliku "<<nazwa_pliku<<".txt"<<endl;
    }

}

void show_tab(int tab[], int n) {
    for(int i=0; i<n; i++)
    cout<<tab[i]<<" ";
    cout<<endl;
}

void show_menu() {
    cout<<endl;
    cout<<"Co chcesz zrobić?"<<endl<<endl;
    cout<<"1 - Wczytaj plik txt do tablicy"<<endl;
    cout<<"2 - Zapisz tablice do pliku txt"<<endl;
    cout<<"3 - Wczytaj plik binarny do tablicy"<<endl;
    cout<<"4 - Zapisz tablice do pliku binarnego"<<endl;
    cout<<"5 - Wyswietl tablice"<<endl;
    cout<<"6 - Zakoncz dzialanie"<<endl;
    cout<<"Twoj wybor: ";
}

int main() {

int state=0; // zmienna stanu
int n; // kolumny

cout<<"Podaj wymiar tablicy: ";
cin>>n;

int *tab = new int [n];

    while(1) {
    show_menu();
    cin>>state;

        switch(state) {
            case 1:
            load_from_txt(tab, n);
            break;
            case 2:
            save_to_txt(tab, n);
            break;
            case 3:
            load_from_bin(tab, n);
            break;
            case 4:
            save_to_bin(tab, n);
            break;
            case 5:
            show_tab(tab, n);
            break;
            case 6:
            delete []tab;
            cout<<"Do widzenia!"<<endl;
            return 0;
            break;
            default:
            cout<<"Bledna opcja, sprobuj ponownie!"<<endl;
            break;
        }

    }

}
