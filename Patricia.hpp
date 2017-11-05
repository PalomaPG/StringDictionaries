#ifndef PATRICIA_H_
#define PATRICIA_H_

#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

class Node{
	public:
		virtual ~Node(){};
		Node();
};

class Leaf:public Node{

	private:
		int index;
		const char* label;

	public:
		Leaf(int i);
		bool insertWord(const char* word);
		int getIndex();
		void setIndex();
		void destroyNode();
		const char* getLabel();

};

class Root: public Node{

	private:
		std::vector<Node*> children;

	public:
		Root();
		std::vector<Node*> getChildren();
		bool insertWord(const char* word, int i);
		void destroyNode();
};

class InnerNode: public Node{

	private:
		std::vector<Node*> children;
		const char *label;

	public:
		InnerNode(char* word);
		std::vector<Node*> getChildren();
		bool insertWord(char* word);
		void destroyNode();

};

class Patricia
{

	//char *regis_file;
	

	public:
		Root* root;
		int index;


		Patricia();
		Patricia(const char* s);
		~Patricia();

		/*True if word exists*/
		bool search();
		
		/*The space occupied by the tree*/
		float space();

		/*Prints the tree */
		void printTree(Node* node);

		/*insert new word*/
		void insert(const char* word);

		/*Destroy this trie*/
		void destroy();

		int getIndex();

};


#endif