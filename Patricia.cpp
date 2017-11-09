//
// Created by paloma on 07-11-17.
//
#include "Patricia.hpp"
/**
 * Constructor de Node
 */
Node::Node(){}

/***
 * ROOT
 */

/**
 * Constructor de Root
 */
Root::Root() {}

/**
 * Busca palabra en diccionario
 * @param node
 * @param word
 * @return Hoja con indices de posicion
 */
Leaf* Root::search(Node* node,string word) {

    /*Si este nodo no tiene hijos*/
    if(this->children.empty()) NULL;

    /*Si tiene hijos...*/
    else{
        char c = word[0];
        for(unsigned int j=0; j<(this->children.size()); j++){
            string label = this->labels.at(j);
            char c_aux = label[0];
            /*Posibilidades de encontrar word*/
            if(c==c_aux){
                /*palabras iguales, incluyendo delimitador,
                 * por lo que el hijo es una hoja*/
                if(word.compare(label)==0){
                    Node* node = this->children.at(j);
                    Leaf* leaf = dynamic_cast<Leaf*>(node);
                    return leaf;
                }
                else{

                    if(word.size() < label.size()) NULL;
                    else{
                        string q_label=word.substr(0, label.size());
                        Node* node = this->children.at(j);
                        if(q_label.compare(label)!=0) NULL;
                        else{
                            /*Llamado recursivo sobre nodo interno*/
                            return search( dynamic_cast<InnerNode*>(node), word.substr(label.size()));
                        }

                    }
                }
            }

        }
        return NULL;
    }
}


/**
 * Inserta palabra en arbol
 * @param word Palabra a insertar
 * @param i posicion de palabra en texto
 */
void Root::insertWord(Node* node, string word, unsigned int i) {

    Leaf* result = this->search(node, word);
    if(result!=NULL){
        result->addPositions(i);
        return;
    }
    else{
        /*Agregar nueva palabra*/
        char c = word[0];

        for(int j=0;j<this->children.size(); j++){
            string q_label = this->labels.at(j);
            /*Si existe label que comience con tal letra*/
            if(c==q_label[0]){
                /*Verificar hijo del nodo: hoja o interno*/
                Node* child = this->children.at(j);
                Leaf* leaf;
                if((leaf=dynamic_cast<Leaf*>(child))==NULL){
                    /*Si se trata de un nodo interno*/

                    /*Extraer el maximo prefijo comumn
                     * antes de llegar al nodo*/


                }
                else{
                    /*Si es una hoja*/
                    /*Calcular maximo prefijo comun*/

                }


            }
        }

        this->labels.push_back(word);
        this->children.push_back(new Leaf(i));
        return;

    }

}
/**
 * @return
 */
vector<Node*>Root::getChildren(){
    return this->children;
}

/**
 * @return
 */
vector<string> Root::getLabels(){
    return this->labels;
}


void Root::setChildren(vector<Node*> new_children){
    this->children = new_children;
}
void Root::setLabels(vector<string> new_labels){
    this->labels = new_labels;
}


InnerNode::InnerNode() {}

void InnerNode::insertWord(Node* node, string word, unsigned int i){

}

Leaf* InnerNode::search(Node* node,string word){
    return NULL;
}

/**
 * @return
 */
vector<Node*>InnerNode::getChildren(){
    return this->children;
}

/**
 * @return
 */
vector<string> InnerNode::getLabels(){
    return this->labels;
}



void InnerNode::setChildren(vector<Node*> new_children){
    this->children = new_children;
}
void InnerNode::setLabels(vector<string> new_labels){
    this->labels = new_labels;
}


/**
 *
 * @return vector de posiciones de string en texto
 */
vector<unsigned int> Leaf::getPositions() {
    return this->positions;
}

void Leaf::addPositions(unsigned int i) {
    this->positions.push_back(i);
}



Patricia::Patricia() {
    this->root = new Root();
}

vector<unsigned int> Patricia::search(string word){
    return this->root->search(NULL, word)->getPositions();
}

void Patricia::insert(string word, unsigned int i){
    this->root->insertWord(this->root, word, i);
}

float Patricia::space() {
    /*Calcular recursivamente*/
    return 0;
}