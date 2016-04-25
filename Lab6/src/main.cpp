#include "test.hh"
#include <ctime>
#include <cstdlib>

int main(int Argc, char* Argv[]) {

srand(time(NULL));

Test start;

start.run(Argc, Argv);

}
