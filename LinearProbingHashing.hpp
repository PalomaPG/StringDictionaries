#ifndef LINPROBHASH_H_
#define LINPROBHASH_H_
const unsigned int SIZE=611671;

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class LinearProbingHashing{

    private:
        //unsigned int size;
        string *table;

    public:
        LinearProbingHashing();
        unsigned int h(string s);
        vector<unsigned int> search(string s);
        void insert(string word);
        void printTable();
        ~LinearProbingHashing();

};



#endif