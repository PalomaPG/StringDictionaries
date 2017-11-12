#include "TextProcessing.hpp"

int main(){
	Processor *processor = new Processor("/home/paloma/Documents/Personal/C++/Tarea2/input/", 100);
    processor->setTexts();/*Inserta en estructura en particular*/
    //processor->printWords(processor->getT1words());
    processor->searchInLPH(processor->getT1words());
    processor->destroyLHP();
    //processor->getLPH()->printTable();

	return 0;
}
/*Numero de experimento n */
void iteration(std::string path){

    Processor *processor = new Processor(path, 100);
    processor->listFilesInDir();
}