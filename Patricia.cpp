#include "Patricia.hpp"

Node::Node(){}

NonLeaf::NonLeaf() {}

void NonLeaf::insert(string s) {
    fakeInsert(this, s);
}

Leaf* NonLeaf::search(string s) {
    return fakeSearch(this, s);
}

void NonLeaf::fakeInsert(Node *node, string s) {

}

Leaf* NonLeaf::fakeSearch(Node *node, string s) {

}

vector<string> NonLeaf::getLabels() {
    return this->labels;
}

void NonLeaf::setLabels(vector<string> newLabels) {
    this->labels=newLabels;
}

vector<Node*> NonLeaf::getChildren() {
    return this->children;
}

void NonLeaf::setChildren(vector<Node *> newChildren) {
    this->children=newChildren;
}



string NonLeaf::getMaxPref(string s1, string s2) {

}