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
    char label;
    TSTNode* left = NULL;
    TSTNode* mid = NULL;
    TSTNode* right = NULL;

public:
    TSTNode();
    TSTNode(char label);
    TSTNode(char label, TSTNode* mid);
    bool search(TSTNode* node,string s);
    void insert(TSTNode* node, string s);
    TSTNode* getLeft();
    TSTNode* getRight();
    TSTNode* getMid();
    void setLeft(TSTNode* node);
    void setRigth(TSTNode* node);
    void setMid(TSTNode* node);
    void setLabel(char label);
    char getLabel();
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