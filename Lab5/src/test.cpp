#include <iostream>
#include <string>
#include "list.hh"
#include "hasharray.hh"
#include "asarray.hh"
#include "timer.hh"


int main() {

AsArray nowa(100);
//Timer *tim = new Timer();

nowa.insert("Marek", 123);
nowa.insert("Marian", 321);

std::cout<<nowa["Marek"];

return 0;
}
