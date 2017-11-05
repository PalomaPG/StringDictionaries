#include "Patricia.hpp"

/* Node */
Node::Node(){}

/* Root */
Root::Root(){
}

std::vector<Node*> Root::getChildren(){
	return children;
}

bool Root::insertWord(const char *s, int i){

	if(children.size()==0){
		/*Vacio*/
		Leaf* leaf = new Leaf(i);
		leaf->insertWord(s);
		children.push_back(leaf);
		return true;
	}
	else return false;
	/*
	else{

	}*/


}

/*Leaf*/
Leaf::Leaf(int i){
	label=NULL;
	index=i;
}


bool Leaf::insertWord(const char* s){
	label=s;
	/*Verificar si el label es null ya esta definido*/
	return true;
}

int Leaf::getIndex(){
	return index;
}


const char* Leaf::getLabel(){
	return label;
}
/*Patricia Trie*/

Patricia::Patricia(){
	root=new Root();
	index=0;

}

Patricia::Patricia(const char* s){
	root=new Root();
	root->insertWord(s, index+1);
	index++;
}
int Patricia::getIndex(){
	return index;
}

void Patricia::insert(const char* s){

	root->insertWord(s, index+1);
	index++;
}

void Patricia::printTree(Node* node){

	if(dynamic_cast<Leaf*>(node)!=nullptr)
		std::cout << dynamic_cast<Leaf*>(node)->getLabel() << std::endl;

	else if(node == root)
		std::cout << "sfasfafdfadsfs" << std::endl;
	//else std::cout << node.getLabel << std.endl;
	/*else{
		for(int i=0; i<root.size(); i++){

		}
	}*/
}

Patricia::~Patricia(){

}
