#include <iostream>
#include "list.hh"
#include "hasharray.hh"
#include "asarray.hh"


int main() {

AsArray nowa(10);
nowa.insert("Marek", 123);
nowa.insert("Wojtek", 321);
nowa.remove("Marek");
nowa.remove("Wojtek");

return 0;
}
