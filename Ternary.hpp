#ifndef TERNARY_H_
#define TERNARY_H_

#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class TSTNode{
private:
    char label='\0';
    bool end=false;
    TSTNode* left = NULL;
    TSTNode* mid = NULL;
    TSTNode* right = NULL;

public:
    TSTNode();
    TSTNode(char label);
    TSTNode* search(TSTNode* node,string s);
    void insert(TSTNode* node, string s);
    TSTNode* getLeft();
    TSTNode* getRight();
    TSTNode* getMid();
    void setLeft(TSTNode* node);
    void setRight(TSTNode* node);
    void setMid(TSTNode* node);
    void setLabel(char label);
    char getLabel();
    bool getEnd();
    void setEnd(bool end);
};


class TST{
private:
    TSTNode* root;

public:
    TST();
    bool search(string s);
    void insert(string s);


};
#endif