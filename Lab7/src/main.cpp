#include "test.hh"
#include <cstdlib>
#include <ctime>

int main(int Argc, char* Argv[]) {

srand(time(NULL));

Test start;

start.run(Argc, Argv);

return 0;
}
