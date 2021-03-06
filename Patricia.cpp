#include "Patricia.hpp"

/*Node*/
Node::Node(){}

Node::~Node(){

}

NonLeaf::NonLeaf() {}


/*NonLeaf*/
void NonLeaf::insert(string s, unsigned int index) {
    fakeInsert(this, s, index);
}

Leaf* NonLeaf::search(string s) {
    return fakeSearch(this, s);
}

void NonLeaf::fakeInsert(Node *node, string s, unsigned int index) {



        NonLeaf* current = dynamic_cast<NonLeaf*>(node);/* Asumimos que comenzamos en nodo no hoja*/

        if(current!=NULL){

            vector<string> labels = current->getLabels();
            unsigned int i;
            /*REvisar labels*/
            for(i=0; i<labels.size(); i++){
                if(labels[i][0]==s[0]) break;
            }
            /*Si no existe un label q comience con la primera letra, se agrega como */
            if(i==labels.size()){
                labels.push_back(s);
                current->setLabels(labels);
                Leaf* new_leaf = new Leaf();
                new_leaf->insert(s, index);
                vector<Node*> children = current->getChildren();
                children.push_back(new_leaf);
                current->setChildren(children);
                return;
            }else{
                /*Antecedentes*/
                string label = labels[i];
                string lcp = getMaxPref(label, s);
                vector<Node*> children = current->getChildren();

                NonLeaf* child = dynamic_cast<NonLeaf*>(children[i]);

                if(child!=NULL){

                    /*Label corresponde a longest common pref */
                    if(label.compare(lcp)==0){

                        return fakeInsert(child, s.substr(label.size(), s.size()-label.size()),index);
                    }

                    /*Label no corresponde a longest common pref*/
                    else{
                        /*crear nuevo nodo interno*/

                        labels[i] = lcp;
                        NonLeaf* newInner = new NonLeaf();
                        current->setLabels(labels);
                        children[i] = newInner;
                        current->setChildren(children);

                        vector<string> newInner_labels;
                        newInner_labels.push_back(label.substr(lcp.size(), label.size()-lcp.size()));
                        newInner_labels.push_back(s.substr(lcp.size(), s.size()-lcp.size()));

                        vector<Node*> newInner_children;
                        newInner_children.push_back(child);

                        Leaf* newLeaf = new Leaf();
                        newLeaf->insert(s, index);
                        newInner_children.push_back(newLeaf);

                        newInner->setChildren(newInner_children);
                        newInner->setLabels(newInner_labels);
                        return;
                    }


                }else{/*El siguiente hijo es una hoja*/
                    Leaf* child_leaf = dynamic_cast<Leaf*>(children[i]);
                    NonLeaf* new_child = new NonLeaf(); /*Se crea hoja interna nueva*/
                    /*Actualizamos etiquetas del nodo en que estmos parados*/
                    labels[i] = lcp;
                    current->setLabels(labels);
                    children[i] = new_child;
                    current->setChildren(children);


                    /*configuramos nuevo nodo interno*/
                    vector<Node*> child_children;
                    /*El nuevo nodo interno recibe hoja*/
                    child_children.push_back(child_leaf);/*Recibe hoja con indices de 1era palabra*/
                    vector<string> child_labels;
                    child_labels.push_back(label.substr(lcp.size(), label.size()-lcp.size()));

                    Leaf* new_leaf = new Leaf();
                    new_leaf->insert(s, index);
                    child_labels.push_back(s.substr(lcp.size(), s.size()-lcp.size()));
                    child_children.push_back(new_leaf);

                    new_child->setChildren(child_children);
                    new_child->setLabels(child_labels);
                    return;
                }

            }
        }
}

Leaf* NonLeaf::fakeSearch(Node *node, string s) {

    NonLeaf* nonleaf = dynamic_cast<NonLeaf*>(node);

    if(nonleaf!=NULL){
        vector<string> labels= nonleaf->getLabels();

        unsigned int i;
        for(i=0; i<labels.size(); i++){
            if(labels[i][0]==s[0]){
                break;
            }
        }
        if(i==labels.size()) return NULL;
        else{
            string label = labels[i];
            vector<Node*> children = nonleaf->getChildren();
            if(label.compare(s)==0 && dynamic_cast<Leaf*>(children[i])) {
                return dynamic_cast<Leaf*>(children[i]);
            }
            else{

                if(label.size()>=s.size()) {
                    return NULL;
                }
                else{
                    if(s.find(label)==0){

                        Node* child = children[i];
                        return fakeSearch(child, s.substr(label.size(), s.size()-label.size()));

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

    unsigned int i;
    for(i=0; i<word.size();i++){
        if(label[i]!=word[i]) break;
    }

    return word.substr(0, i);
}

void NonLeaf::destroyMe(Node* node) {

    if(node!=NULL){
        NonLeaf* current = dynamic_cast<NonLeaf*>(node);
        if(current!=NULL){
            vector<Node*> childs = current->getChildren();

            for(unsigned int i=0; i<childs.size(); i++){

                destroyMe(childs[i]);
            }
            current->setLabels(vector<string>());
            free(current);


        }else{
            Leaf* current = dynamic_cast<Leaf*>(node);
            current->setIndices(vector<unsigned int>());
            free(current);

        }
    }
}

Leaf::Leaf(){

}

vector<unsigned int> Leaf::getIndices() {
    return this->indices;
}

void Leaf::setIndices(vector<unsigned int> new_indices){
    this->indices = new_indices;
}

void Leaf::insert(string s, unsigned int index) {
    this->indices.push_back(index);
}

Leaf* Leaf::search(string s){
    return this;
}

void Leaf:: destroyMe(Node* node){

}

Patricia::Patricia(){
    this->root = new NonLeaf();
}

void Patricia::insert(string s, unsigned int i) {

    Leaf* leaf = this->root->search(s); /*busqueda*/

    if(leaf==NULL) {/*Si no existe en este arbol*/

        auto start = high_resolution_clock::now();


        this->root->insert(s, i);

        auto end = high_resolution_clock::now();
        auto dur = end - start;
        //auto i_millis = duration_cast<milliseconds>(dur);
        auto f_secs = duration_cast<duration<float>>(dur);

        this->setTotalInsertTime(this->getTotalInsertTime()+(f_secs.count()));
    }
    else{
        vector<unsigned int> new_indices = leaf->getIndices();
        new_indices.push_back(i);
        leaf->setIndices(new_indices);
    }

}

vector<unsigned int> Patricia::search(string s) {

    Leaf* leaf=  this->root->search(s);
    return leaf==NULL? vector<unsigned int>() : leaf->getIndices();

}

Patricia::~Patricia() {

        this->root->destroyMe(this->root);
        this->root=NULL;
}

float Patricia::getTotalInsertTime() {
    return this->totalInsertTime;
}

void Patricia::setTotalInsertTime(float new_time) {
    this->totalInsertTime=new_time;
}

unsigned int Patricia::patySize(Node* node) {

    unsigned int node_size = sizeof(node);
    NonLeaf* current = dynamic_cast<NonLeaf*>(node);

    if(current!=NULL) {
        vector<Node *> childs = current->getChildren();
        for (unsigned int i = 0; i < childs.size(); i++) {
            node_size += patySize(childs[i]);
        }
        return node_size;
    }
    else sizeof(node);
}

NonLeaf* Patricia::getRoot() {
    return this->root;
}


