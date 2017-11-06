#include "Patricia.hpp"
#include "TextProcessing.hpp"

int main(){
	Processor *processor = new Processor("/home/paloma/Documents/Personal/C++/Tarea2/input/", 100);
    processor->setTexts();


	/*
	Patricia* patricia = new Patricia();
	patricia->insert("Hola");
	std::cout << patricia->getIndex() <<std::endl;
	patricia->printTree(patricia->root);*/
	//delete patricia;
	return 0;
}
/*Numero de experimento n */
void iteration(std::string path){

    Processor *processor = new Processor(path, 100);
    processor->listFilesInDir();
}