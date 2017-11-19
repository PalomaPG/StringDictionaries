#include "TextProcessing.hpp"

template <typename T, int sz>
int len(T(&)[sz]){
    return sz;
}

vector<string> split(string line){
    vector<string> w;
    string delimiter = " ";
    size_t pos =0;
    string token;

    while((pos = line.find(delimiter))!=string::npos){
        token = line.substr(0,pos);
        w.push_back(token);
        //cout<< token << endl;
        line.erase(0, pos + delimiter.length());
    }
    return w;
}

void checkWords(vector<string> vec){
    for(unsigned int i=0; i<vec.size();i++)
        cout<< vec.at(i) <<endl;
}

void Processor::selectWords(string line){
    if(count>=n_words) return;
    /*Splitea line en un arreglo de strings*/
    vector<string> ws =split(line);
    double r;
    /*Selecciona las palabras de acuerdo a criterio azaroso*/
    for(unsigned int j=0; j<ws.size(); j++){
        words.push_back(ws[j]);
        count++;
        r = ((double) rand() / (RAND_MAX));
        if(r>0.5) {
            if(sample.size()<n_words && (ws.at(j)).length()>0)
                sample.push_back(ws[j]);

            else break;
        }
    }

}

Processor::Processor(string file_path, unsigned int n_w) {
    this->file_path=file_path;
    n_words = (int) pow(2, n_w);

}

Processor::~Processor() {
    //delete DirPath;
}

string Processor::toLowerCase(string line) {

    int i=0;
    while(line[i]){
        line[i] = tolower(line[i]);
        i++;
    }
    return line;
}

string Processor::removeNumbers(string line) {
    const char numbers[]={'1','2', '3', '4', '5', '6',
    '7', '8', '9', '0'};
    for(int i=0; i<len(numbers) ; i++)
        line.erase(remove(line.begin(), line.end(), numbers[i]), line.end());

    return line;
}

string Processor::removePunctuationAndStuff(string line) {

    const char punctuations[] = {'-','.', ',', ':', ';', '\'',
                                 '\n', '\"', '/', '@', '(', ')',
                                '\'', '$', '%', '#', '?', '\"',
                                 '!', '*', '\t', '[', ']'};

    for(int i=0; i<len(punctuations) ; i++)
        line.erase(remove(line.begin(), line.end(), punctuations[i]), line.end());

    return line;
}




void Processor::readText() {

    string line;
    ifstream infile (file_path);
    if(infile.is_open()){
        while(getline(infile, line)){
            if(count>=n_words) break;
            line = this->toLowerCase(line);
            line = this->removePunctuationAndStuff(line);
            line = this->removeNumbers(line);
            //cout << line <<endl;
            selectWords(line);
        }
        infile.close();
    }else{
        cout << "unable to open file" << endl;
    }
 }

void Processor::verifyNofWords(){

    unsigned int i=0;
    while(count<n_words){

        words.push_back(words[i]);
        count++;
        i=i%n_words;
    }
    return;
}


void Processor::initLPH() {

    lph = new LinearProbingHashing();
}



void Processor::initPatricia() {
    patricia = new Patricia();

}


vector<string> Processor::getSample() {
    return this->sample;
}




void Processor::printWords(vector<string> v) {
    for(unsigned int i=0; i<v.size(); i++){
        cout << v.at(i) << endl;
    }
}

/*
void Processor::searchInLPH(vector<string> v) {
    for(unsigned int i=0;i<v.size(); i++){
        cout << lph->search(v.at(i)) << endl;
    }
}*/

void Processor::destroyLHP() {
    delete lph;
}

void Processor::destroyPaty() {
    delete patricia;
}

void Processor::searchSampleLPH() {

}

void Processor::insertWordsPatricia() {

    for(unsigned int i=0; i<words.size(); i++)
        patricia->insert(words[i], i);

}

void Processor::searchSamplePatricia() {

    for(unsigned int i=0; i<sample.size(); i++)
        patricia->search(sample[i]);
}

void Processor::insertWordsLPH() {

}

double Processor::getPatriciaInsertTime() {
    return patricia->getTotalInsertTime();
}

unsigned int Processor::getPatriciaSize(){
    return patricia->patySize(patricia->getRoot());
}
