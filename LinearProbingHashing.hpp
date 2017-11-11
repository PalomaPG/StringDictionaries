#ifndef LINPROBHASH_H_
#define LINPROBHASH_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class HashNode{

    private:
        unsigned int key;
        string value;
        HashNode* next;

    public:
        HashNode(unsigned int key, string value);
        unsigned int getKey();
        string getValue();
        void setValue(string s);
        void setKey(unsigned int k);
        HashNode* getNext();
        void setNext(HashNode* n);
};



class LinearProbingHashing{

    private:
        unsigned int size;

    public:
        LinearProbingHashing(unsigned int size);
        unsigned int h(string s);
        void createTable();
        vector<unsigned int> search(string s);
        void insert(string word);
        ~LinearProbingHashing();

};



#endif