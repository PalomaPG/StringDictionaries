#include "Patricia.hpp"

/*Node*/
Node::Node(){}

Node::~Node(){
   delete this;

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

    Leaf* leaf = fakeSearch(node, s); /*busqueda*/

    if(leaf==NULL){/*Si no existe en este arbol*/
        cout << "no existe por tanto lo agrego "+s << endl;

        NonLeaf* current = dynamic_cast<NonLeaf*>(node);/* Asumimos que comenzamos en nodo no hoja*/

        if(current!=NULL){

            vector<string> labels = current->getLabels();
            int i;
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
                string new_label = getMaxPref(label, s);
                vector<Node*> children = current->getChildren();

                NonLeaf* child = dynamic_cast<NonLeaf*>(children[i]);

                if(child!=NULL){
                    cout << "AHORA SI? "+label << endl;






                }else{/*El siguiente hijo es una hoja*/
                    Leaf* child_leaf = dynamic_cast<Leaf*>(children[i]);
                    NonLeaf* new_child = new NonLeaf(); /*Se crea hoja interna nueva*/
                    /*Actualizamos etiquetas del nodo en que estmos parados*/
                    labels[i] = new_label;
                    current->setLabels(labels);
                    children[i] = new_child;
                    current->setChildren(children);


                    /*configuramos nuevo nodo interno*/
                    vector<Node*> child_children;
                    /*El nuevo nodo interno recibe hoja*/
                    child_children.push_back(child_leaf);/*Recibe hoja con indices de 1era palabra*/
                    vector<string> child_labels;
                    child_labels.push_back(label.substr(new_label.size(), label.size()-new_label.size()));

                    Leaf* new_leaf = new Leaf();
                    new_leaf->insert(s, index);
                    child_labels.push_back(s.substr(new_label.size(), s.size()-new_label.size()));
                    child_children.push_back(new_leaf);

                    new_child->setChildren(child_children);
                    new_child->setLabels(child_labels);
                    return;
                }
                //labels[i] = new_label;
                //nonleaf->setLabels(labels);
                //nonleaf->setChildren(labels.erase(children.begin()+i));






            }
        }

    }else{
        vector<unsigned int> new_indices = leaf->getIndices();
        new_indices.push_back(index);
        leaf->setIndices(new_indices);
    }

}

Leaf* NonLeaf::fakeSearch(Node *node, string s) {

    NonLeaf* nonleaf = dynamic_cast<NonLeaf*>(node);

    if(nonleaf!=NULL){
        vector<string> labels= nonleaf->getLabels();

        int i;
        for(i=0; i<labels.size(); i++){
            if(labels[i][0]==s[0]){
                break;
            }
        }
        if(i==labels.size()) return NULL;
        else{
            string label = labels[i];
            cout << label << endl;
            vector<Node*> children = nonleaf->getChildren();
            if(label.compare(s)==0 && dynamic_cast<Leaf*>(children[i])) {
                cout << "son iguales "+s << endl;
                return dynamic_cast<Leaf*>(children[i]);
            }
            else{

                if(label.size()>=s.size()) {
                    cout << "holaaaaa" << endl;
                    return NULL;
                }
                else{
                    //indexof label... if not return NULL
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

    int i;
    for(i=0; i<word.size();i++){
        if(label[i]!=word[i]) break;
    }

    return word.substr(0, i);
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

Patricia::Patricia(){
    this->root = new NonLeaf();
}

void Patricia::insert(string s, unsigned int i) {
    this->root->insert(s, i);
}

vector<unsigned int> Patricia::search(string s) {

    Leaf* leaf = this->root->search(s);
    if(leaf==NULL) return vector<unsigned int>();
    else return leaf->getIndices();
}