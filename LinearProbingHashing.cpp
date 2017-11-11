#include "LinearProbingHashing.hpp"


HashNode::HashNode(unsigned int key, string value) {

    this->key = key;
    this->value = value;
    this->next = NULL;
}

unsigned int HashNode::getKey() {
    return this->key;
}

string HashNode::getValue() {
    return this->value;
}

HashNode* HashNode::getNext() {
    return this->next;
}

void HashNode::setValue(string s) {
    this->value=s;
}


void HashNode::setKey(unsigned int k) {
    this->key = k;
}

void HashNode::setNext(HashNode *n) {
    this->next=n;
}

LinearProbingHashing::LinearProbingHashing(unsigned int size) {

    this->size = size;


}
unsigned int LinearProbingHashing::h(string s) {

    unsigned int calc_val=0;

    for(int i=0; i<s.size(); i++){
        unsigned char c = s[i];
        calc_val+= (unsigned int)(c*pow(this->size, (double)i));
    }

    return calc_val % this->size;
}

void LinearProbingHashing::insert(string word) {

    cout << this->h(word) << endl;
}

vector<unsigned int> LinearProbingHashing::search(string s) {
    return vector<unsigned int>();
}
