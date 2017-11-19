#include "TextProcessing.hpp"
#include "Patricia.hpp"
using namespace std;

void testInsertion(int i);
void PatriciaInsertAndSearch(Processor* processor);
void LPHInsertAndSearch(Processor *processor);

int main(){

    for(int i=10; i<=20; i++){
        testInsertion(i);
    }


	return 0;
}

void testInsertion(int i){

    Processor *processor = new Processor("/home/paloma/Documents/Personal/C++/Tarea2/input/anna_karenina.txt", i);
    processor->readText();
    processor->verifyNofWords();
    PatriciaInsertAndSearch(processor);
    //LPHInsertAndSearch(processor);
}

void PatriciaInsertAndSearch(Processor *processor){

    processor->initPatricia();
    processor->insertWordsPatricia();
    processor->searchSamplePatricia();
    processor->destroyPaty();
}


void LPHInsertAndSearch(Processor *processor){

    processor->initLPH();
    processor->insertWordsLPH();
    processor->searchSampleLPH();
    processor->destroyLHP();

}