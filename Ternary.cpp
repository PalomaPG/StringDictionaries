#include "Ternary.hpp"

TSTNode::TSTNode() {

}

TSTNode::TSTNode(char label) {
    this->label=label;

}

TSTNode::TSTNode(char label, TSTNode* mid) {

    this->label = label;
    this->mid = mid;
}

char TSTNode::getLabel() {
    return this->label;
}

void TSTNode::setLabel(char c){
    this->label=c;
}

TSTNode* TSTNode::getLeft() {
    return this->left;
}

TSTNode* TSTNode::getMid() {
    return this->mid;
}

TSTNode* TSTNode::getRight() {
    return this->right;
}

void TSTNode::setLeft(TSTNode* node) {
    this->left=node;
}
void TSTNode::setMid(TSTNode* node) {
    this->mid=node;
}

void TSTNode::setRigth(TSTNode* node) {
    this->right=node;
}

bool TSTNode::search(TSTNode *node, string s) {

    if(node==NULL && s.size()>0) return false;
    else if(node!=NULL && s.size()==0) return true;
    else{
        char c = s[0];
        if(s[0]==node->getLabel()) return search(node->getMid(), s.substr(1, s.size()-1));
        else{
            if(s[0]<node->getLabel()){
                return search(node->getLeft(), s);
            }
            else return search(node->getRight(), s);
        }
    }

}

void TSTNode::insert(TSTNode *node, string s) {

}

TST::TST(){
    this->root = new TSTNode();
}

void TST::insert(string s) {

}

bool TST::search(string s) {

}