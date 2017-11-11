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
    //cout << line << endl;
    return w;
}

void checkWords(vector<string> vec){
    for(unsigned int i=0; i<vec.size();i++)
        cout<< vec.at(i) <<endl;
}

void Processor::selectWords(string line, unsigned int i){
    /*Splitea line en un arreglo de strings*/
    vector<string> ws =split(line);
    double r;
    /*Selecciona las palabras de acuerdo a criterio azaroso*/

    for(unsigned int j=0; j<ws.size(); j++){
        r = ((double) rand() / (RAND_MAX));
        if(r>0.5) {
            if(i==0 && t1_words.size()<n_words && (ws.at(j)).length()>0)
                t1_words.push_back(ws.at(j));

            else if(i==1 && t2_words.size()<n_words && (ws.at(j)).length()>0)
                t2_words.push_back(ws.at(j));
            else break;
        }
    }

}

Processor::Processor(string dirPath, unsigned int n_w) {
    DirPath = dirPath.c_str();
    n_words = n_w;
    //patricia = NULL;
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


void Processor::listFilesInDir(){


    DIR *dir;
    struct dirent *ent;
    cout << DirPath << endl;

    if((dir=opendir(DirPath.c_str())) !=NULL){
        while((ent = readdir(dir)) !=NULL){

            if(ent->d_type==DT_REG) {
                printf("%s\n", ent->d_name);
                files.push_back(DirPath+string(ent->d_name));
            }
        }
        closedir(dir);
    }else{
        cout << DirPath << endl;
        perror("Error al leer");
        return;
    }
}

string Processor::getText(unsigned int i) {

    string line;
    string text="";
    ifstream infile (files.at(i));
    if(infile.is_open()){
        while(getline(infile, line)){
            line = this->toLowerCase(line);
            line = this->removePunctuationAndStuff(line);
            line = this->removeNumbers(line);
            //cout << line <<endl;
            selectWords(line, i);
            text = text+line;
        }
        infile.close();
    }else{
        cout << "unable to open file" << endl;
    }
    /*Asumimos que siempre se agregan en orden, primero 0 (T1) y despues
     * 1 (T2)*/
    //checkWords(t1_words);
    return text;

}

void Processor::setTexts() {

    listFilesInDir();
    texts.push_back(getText(0));
    //texts.push_back(getText(1));
}

void Processor::initLPH() {

    cout << "inciando LPH" << endl;
    lph = new LinearProbingHashing();
    cout << "end init LPH" << endl;
}

void Processor::insertIntoLPH(vector<string> v){
    for(int i=0; i<v.size(); i++)
        lph->insert(v.at(i));
}
/*
void Processor::initPatricia() {
    patricia = new Patricia();

}*/

double Processor::similarityPatricia() {
    return 0;
}

double Processor::similarityHLP() {
    return 0;
}

double Processor::similarityTernary() {
    return 0;
}

vector<string> Processor::getT1words() {
    return this->t1_words;
}

vector<string> Processor::getT2words() {
    return this->t2_words;
}

LinearProbingHashing* Processor::getLPH() {
    return lph;
}

void Processor::printWords(vector<string> v) {
    for(int i=0; i<v.size(); i++){
        cout<< v.at(i) << endl;
    }
}
