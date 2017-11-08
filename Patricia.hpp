#ifndef PATRICIA_H_
#define PATRICIA_H_

#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Node{
	public:
		Node();
		virtual ~Node(){};
		virtual void insertWord(Node* node, string word, unsigned int i)=0;
		virtual Leaf* search(Node* node, string word)=0;
        virtual vector<unsigned int> getPositions()=0;

    virtual void destroyNode(Node* node)=0;


};

class Leaf:public Node{

	private:
		vector<unsigned int> positions;

	public:
		Leaf(unsigned int i);
        vector<unsigned int> getPositions();

    void addPositions(unsigned int i);
};

class Root: public Node{

	private:
		vector<Node*> children;
		vector<string> labels;

	public:
		Root();
		vector<Node*> getChildren();
		vector<Node*> getLabels();
		void setChildren();
		void setLabels();
        void insertWord(Node* node, string word, unsigned int i);
        Leaf*search(Node* node,string word);
};

class InnerNode: public Node{

	private:
		vector<Node*> children;
		vector<string> labels;
	public:
		InnerNode();
		vector<Node*> getChildren();
		vector<Node*> getLabels();
		void setChildren();
		void setLabels();


};

class Patricia
{
	public:
		Root* root;
		Patricia();
		~Patricia();


	/**
	 * Busca string word en arbol
	 * @param word palabra a buscar. Es un string
	 * @return vector de posiciones donde se encuentra string
	 */
		vector<unsigned int> search(string word);
	/**
	 * inserta palabra
	 * @param word Palabra a insertar
	 * @param i posicion en arreglo
	 */
		void insert(string word, unsigned int i);

	/**
	 * Espacio ocupado por el trie
	 * @return devuelve tamano en Kilobytes
	 */

		float space();

		/*Prints the tree */
		void printTree(Node* node);


		/*Destroy this trie*/
		void destroy();


};


#endif