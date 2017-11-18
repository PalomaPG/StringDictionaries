#include "Patricia.hpp"

/*Node*/
Node::Node(){}

NonLeaf::NonLeaf() {}


/*NonLeaf*/
void NonLeaf::insert(string s, unsigned int index) {
    fakeInsert(this, s, index);
}

Leaf* NonLeaf::search(string s) {
    return fakeSearch(this, s);
}

void NonLeaf::fakeInsert(Node *node, string s, unsigned int index) {

    Leaf* leaf = fakeSearch(node, s);

    if(leaf==NULL){
        NonLeaf* nonleaf = dynamic_cast<NonLeaf*>(node);
        if(nonleaf!=NULL){
            vector<string> labels = nonleaf->getLabels();
            int i;

            for(i=0; i<labels.size(); i++){
                if(labels.at(i)[0]==s[0]) break;
            }

            if(i==labels.size()){
                labels.push_back(s);
                Leaf* new_leaf = new Leaf();
                new_leaf->setIndices(new_leaf->getIndices().push_back(index));
                nonleaf->setChildren(nonleaf->getChildren().push_back(new_leaf));
            }else{






            }
        }

    }else{
        leaf->setIndices(leaf->getIndices().push_back(index));
    }

}

Leaf* NonLeaf::fakeSearch(Node *node, string s) {

    NonLeaf* nonleaf = dynamic_cast<NonLeaf*>(node);

    if(nonleaf!=NULL){
        vector<string> labels= nonleaf->getLabels();
        char c = s[0];
        int i;
        for(i=0; i<labels.size(); i++){
            if(labels.at(i)[0]==s[0]){
                break;
            }
        }
        if(i==labels.size()) return NULL;
        else{
            string label = labels.at(i);
            vector<Node*> children = nonleaf->getChildren();
            if(label.compare(s)==0) return children.at(i);
            else{
                if(label.size()>=s.size()) return NULL;
                else{
                    //indexof label... if not return NULL
                    if(s.find(label)>0){

                        Node* child = children[i];
                        return fakeSearch(child, s.substr(label.size()-1, s.size()-label.size()));

                    }else return NULL;

                }
            }
        }

    }
    else{/*Era una hoja*/
        return dynamic_cast<Leaf*>(node);

    }

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



string NonLeaf::getMaxPref(string label, string word) {

    int i;
    for(i=0; i<word.size();i++){
        if(label[i]!=word[i]) break;
    }

    return word.substr(0, i);
}