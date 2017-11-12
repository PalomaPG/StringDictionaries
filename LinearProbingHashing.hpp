#ifndef LINPROBHASH_H_
#define LINPROBHASH_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>

const unsigned int PRIME_VALUES[] = {611671, 856021,1069307};

using namespace std;

class LinearProbingHashing{

    private:
        unsigned int size;
        string *table;
        const double load_factor=0.4;
        int count;
        int prime_index=0;

    public:
        LinearProbingHashing();
        unsigned int h(string s);
        int search(string s);
        void insert(string word);
        void doubleTable();
        void printTable();
        ~LinearProbingHashing();

};



#endif