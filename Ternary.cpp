#include "Ternary.hpp"


TSTNode::TSTNode() {

}
TSTNode::TSTNode(char label) {
    this->label=label;
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

void TSTNode::setRigth(TSTNode* node) {
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

        node->setLabel(s[0]);
        node->setMid(new TSTNode());
        if(s.size()==1) {
            node->setEnd(true);
            return;
        }
        else insert(node->getMid(), s.substr(1, s.size()-1));

    }
    else if(s[0]==node->getLabel()){
        insert(node->getMid(), s.substr(1, s.size()-1));
    }
    else{
        if(s[0]<node->getLabel()){
            TSTNode* left = node->getLeft();
            if(left==NULL) {
                left = new TSTNode(s[0]);

                if(s.size()==1) {
                    left->setEnd(true);
                    return;
                }

                else insert(left, s.substr(1, s.size()-1));
            }
            else insert(left, s);
        }

        else{
            TSTNode* right = node->getRight();
            if(right==NULL) {
                right = new TSTNode(s[0]);

                if(s.size()==1) {
                    right->setEnd(true);
                    return;
                }

                else insert(right, s.substr(1, s.size()-1));
            }
            else insert(right, s);
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
    return this->root->insert(this->root, s);
}

bool TST::search(string s) {
    return this->root->search(this->root,s)->getEnd();
}