#include "TextProcessing.hpp"
#include "Patricia.hpp"
using namespace std;

void testPatricia();

int main(){
    testPatricia();
    /*
	Processor *processor = new Processor("/home/paloma/Documents/Personal/C++/Tarea2/input/", 100);
    processor->setTexts();/*Inserta en estructura en particular*/
    //processor->printWords(processor->getT1words());
    /*processor->searchInLPH(processor->getT1words());
    processor->destroyLHP();*/
    //processor->getLPH()->printTable();

	return 0;
}
/*Numero de experimento n */
void iteration(string path){

    Processor *processor = new Processor(path, 100);
    processor->listFilesInDir();
}

void testPatricia(){

    Patricia* paty = new Patricia();
    paty->insert("hola$", 1);
    paty->insert("holanda$", 4);
    paty->insert("chaooo$", 34);
    paty->insert("nicoso$", 10);
    paty->insert("nicos$", 14);
    paty->insert("nicosa$", 9);
    paty->insert("niza$", 16);
    paty->insert("nini$", 18);
    paty->insert("nini$", 20);
    paty->insert("nicosa$", 32);
    paty->insert("nicosa$", 43);
    vector<unsigned int> v =paty->search("holanda$");
    cout << v.size() << endl;

    for(int i=0; i<v.size(); i++)
        cout << v[i] << endl;


}