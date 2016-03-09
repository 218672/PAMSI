#include <iostream>
#include <string>
#include "palindrom.hh"
#define PAL_SIZE 30

using namespace std;

string palindroms[PAL_SIZE]= {};
int counter=0;

void make_permutations(string original, string permutation) {

    if(original.empty()) {
    bool if_pal=is_pal(permutation);
        if(if_pal) {
        palindroms[counter]=permutation;
        counter++;
        }
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

void delete_duplicates() {
    for(int help_counter=0; help_counter<PAL_SIZE; help_counter++) {
        string pal_copy=palindroms[help_counter];
            for(int i=help_counter+1; i<PAL_SIZE; i++) {
                if(pal_copy==palindroms[i])
                palindroms[i]="kopia";
            }
            for(int i=help_counter-1;i>=0; i--) {
                if(pal_copy==palindroms[i])
                palindroms[i]="kopia";
            }
    }
}

int main() {

    string perm, word="ABC";
    make_permutations(word,perm);

}
