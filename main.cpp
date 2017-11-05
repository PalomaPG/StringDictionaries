#include "Patricia.hpp"
#include "TextProcessing.hpp"

int main(){
	Processor *processor = new Processor("/home/paloma/Documents/Personal/C++/Tarea2/input/");
    processor->getFilesInDir(0);

	/*
	Patricia* patricia = new Patricia();
	patricia->insert("Hola");
	std::cout << patricia->getIndex() <<std::endl;
	patricia->printTree(patricia->root);*/
	//delete patricia;
	return 0;
}