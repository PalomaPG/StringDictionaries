#include "TextProcessing.hpp"

template <typename T, int sz>
int len(T(&)[sz]){
    return sz;
}


Processor::Processor(string dirPath, unsigned int n_w) {
    DirPath = dirPath.c_str();
    n_words = n_w;
    //cout << dirPath << endl;
    //cout << DirPath << endl;

    patricia = NULL;
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
        //remove_copy(line.begin(), line.end(), back_inserter(line), numbers[i]);

    return line;

}

string Processor::removePunctuationAndStuff(string line) {

    const char punctuations[] = {'-','.', ',', ':', ';', '\'',
                                 '\n', '\"', '/', '@', '(', ')',
                                '\'', '$', '%', '#', '?', '\"',
                                 '!', '*', 34};

    for(int i=0; i<len(punctuations) ; i++)
        line.erase(remove(line.begin(), line.end(), punctuations[i]), line.end());
        //remove_copy(line.begin(), line.end(), back_inserter(line), punctuations[i]);

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
            cout << line <<endl;
            text = text+line;
        }
        infile.close();
    }else{
        cout << "unable to open file" << endl;
    }

    return line;

}

double Processor::similarityPatricia() {
    return 0;
}

double Processor::similarityHLP() {
    return 0;
}

double Processor::similarityTernary() {
    return 0;
}

string Processor::getDir() {
    return DirPath;
}