#include <iostream>

using namespace std;

int Potega(int x, int p) {
    if(p==0)
    return 1;
    else
    return x*Potega(x, --p);
}

int Silnia(int x) {
    if(x<2)
    return 1;
    else
    return x*Silnia(x-1);
}

int main() {

    int x, p;
    cout<<"Podaj liczbe: ";
    cin>>x;
    cout<<"Do ktorej potegi podniesc? ";
    cin>>p;
    cout<<"Silnia liczby: "<<Silnia(x)<<endl;
    cout<<"Potega liczby: "<<Potega(x,p)<<endl;


return 0;
}
