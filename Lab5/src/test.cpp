#include <iostream>
#include <string>
#include "list.hh"
#include "hasharray.hh"
#include "asarray.hh"


int main() {

AsArray *nowa = new AsArray(10);
nowa->insert("Marek", 123);
nowa->insert("Wojtek", 321);

delete nowa;

return 0;
}
