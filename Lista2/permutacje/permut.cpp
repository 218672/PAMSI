#include <iostream>
#include <string>
#include "palindrom.hh"

using namespace std;

void make_permutations(string original, string permutation) {

    if(original.empty()) {
        cout<<permutation<<endl;
        return;
    }

    for(unsigned int i=0; i<original.size(); i++) {

        string original_copy=original;
        original_copy.erase(i,1);
        string permutation_copy=permutation;
        permutation_copy+=original.at(i);
        make_permutations(original_copy, permutation_copy);
    }

}

int main() {

    string perm, word="ABC";
    make_permutations(word,perm);

}
