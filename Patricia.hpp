#ifndef PATRICIA_H_
#define PATRICIA_H_

#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Node{

public:
    Node();
    virtual void insert(string s);
    virtual Leaf* search(string s);
};

class NonLeaf: public Node{

private:
    vector<string> labels;
    vector<Node*> children;

public:
    NonLeaf();
    vector<string> getLabels();
    vector<Node*> getChildren();
    void setChildren(vector<Node*> newChildren);
    void setLabels(vector<string> newLabels);
    void fakeInsert(Node* node, string s);
    Leaf* fakeSearch(Node* node, string s);
    string getMaxPref(string s1, string s2);
};



class Leaf: public Node{

private:
    vector<unsigned int> indices;
public:
    Leaf();
    vector<unsigned int> getIndices();
    void setIndices(vector<unsigned int> newIndices);
};
#endif