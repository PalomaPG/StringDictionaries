#include "Ternary.hpp"


TSTNode::TSTNode() {
 this->label = '\0';
    this->end = false;
}
TSTNode::TSTNode(char label) {
    this->label=label;
    this->end=false;
}


char TSTNode::getLabel() {
    return this->label;
}

void TSTNode::setLabel(char label){
    this->label=label;
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

void TSTNode::setRight(TSTNode* node) {
    this->right=node;
}

TSTNode* TSTNode::search(TSTNode *node, string s) {
    if(node->getLabel()=='\0') return node;
    else if(s[0]==node->getLabel() && s.size()==1){
        return node;
    }
    else if(s[0]==node->getLabel() && s.size()>1){
        return search(node->getMid(), s.substr(1, s.size()-1));

    }
    else{
        if(s[0]<node->getLabel()){
            TSTNode* left = node->getLeft();
            if(left==NULL) return node;
            else return search(left, s);

        }
        else{
            TSTNode* right = node->getRight();
            if(right==NULL) return node;
            else return search(right, s);
        }

    }


}

void TSTNode::insert(TSTNode *node, string s) {

    if(node->getLabel()=='\0'){
        /*Label no inicializada*/
        node->setLabel(s[0]);
        if(s.size()==1){
            node->setEnd(true);
            return;
        }
        else {
            TSTNode *new_mid = new TSTNode();
            node->setMid(new_mid);
            return insert(new_mid, s.substr(1, s.size()-1));
        }
    }
    else if(node->getLabel()==s[0]){
        return insert(node->getMid(), s.substr(1, s.size()-1));
    }

    else if(node->getLabel()>s[0]){

        if(node->getLeft()==NULL){
            TSTNode* new_left = new TSTNode();
            node->setLeft(new_left);
            return insert(new_left, s);

        }else{
            return insert(node->getLeft(), s);
        }
    }
    else{

        if(node->getRight()==NULL){
            TSTNode* new_right = new TSTNode();
            node->setRight(new_right);
            return insert(new_right, s);

        }else{
            return insert(node->getRight(), s);
        }
    }

}

void TSTNode::setEnd(bool end) {
    this->end=end;
}

bool TSTNode::getEnd() {
    return this->end;
}

TST::TST(){
    this->root = new TSTNode();
}

void TST::insert(string s) {
    //TSTNode* node = (this->root->search(this->root,s));
    if(!search(s))
        this->root->insert(this->root, s);
}

bool TST::search(string s) {
    return this->root->search(this->root,s)->getEnd();
}