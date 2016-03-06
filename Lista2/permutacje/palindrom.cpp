#include <iostream>
#include <string>

using namespace std;

bool is_pal(string test) {
    if(test.size()!=1 && test.at(0)==test.at(test.size()-1)) {
    test.erase(0, 1);
    test.erase(test.size()-1,1);
    return is_pal(test);
    }
    else if (test.size()==1)
    return true;
    else
    return false;
}

int main() {

}
