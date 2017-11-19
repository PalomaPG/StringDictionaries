#ifndef PATRICIA_H_
#define PATRICIA_H_

#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Leaf;

class Node{

public:
    Node();
    ~Node();
    virtual void insert(string s, unsigned int index)=0;
    virtual Leaf* search(string s)=0;
    virtual void destroyMe(Node* node)=0;
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
    void fakeInsert(Node* node, string s, unsigned int index);
    Leaf* fakeSearch(Node* node, string s);
    string getMaxPref(string s1, string s2);
    void destroyMe(Node* node);
    void insert(string s, unsigned int index);
    Leaf* search(string s);
};



class Leaf: public Node{

private:
    vector<unsigned int> indices;
public:
    Leaf();
    vector<unsigned int> getIndices();
    void setIndices(vector<unsigned int> newIndices);
    void destroyMe(Node* node);
    void insert(string s, unsigned int index);
    Leaf* search(string s);

};



class Patricia{
private:
    NonLeaf* root;
    float totalInsertTime;

public:
    Patricia();
    ~Patricia();
    float getTotalInsertTime();
    void setTotalInsertTime(float new_time);
    void insert(string s, unsigned int i);
    vector<unsigned int> search(string s);
    unsigned int patySize(Node* node);

    NonLeaf *getRoot();
};
#endif