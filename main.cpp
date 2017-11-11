#include "TextProcessing.hpp"

int main(){
	Processor *processor = new Processor("/home/paloma/Documents/Personal/C++/Tarea2/input/", 100);
    processor->setTexts();
    processor->initLPH();
    processor->insertIntoLPH(processor->getT1words());

	return 0;
}
/*Numero de experimento n */
void iteration(std::string path){

    Processor *processor = new Processor(path, 100);
    processor->listFilesInDir();
}