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
    if(this->children.size()==0) NULL;

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
    }
    else{
        /*Agregar nueva palabra*/

    }

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
