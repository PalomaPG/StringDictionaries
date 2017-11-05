#include "TextProcessing.hpp"

template <typename T, int sz>
int len(T(&)[sz]){
    return sz;
}


Processor::Processor(std::string dirPath) {
    DirPath = dirPath;
    patricia = NULL;
}

Processor::~Processor() {
    delete DirPath;
}

std::string Processor::toLowerCase(std::string line) {

    int i=0;
    while(line[i]){
        line[i] = tolower(line[i]);
    }
    return line;
}

std::string Processor::removeNumbers(std::string line) {
    const char numbers[]={'1','2', '3', '4', '5', '6',
    '7', '8', '9', '0'};
    for(int i=0; i<len(numbers) ; i++)
        std::remove_copy(line.begin(), line.end(), std::back_inserter(line), numbers[i]);

    return line;

}

std::string Processor::removePunctuationAndStuff(std::string line) {

    const char punctuations[] = {'.', ',', ':', ';', '\'', '\n', '\"'};

    for(int i=0; i<len(punctuations) ; i++)
        std::remove_copy(line.begin(), line.end(), std::back_inserter(line), punctuations[i]);

    return line;
}

void Processor::getFilesInDir(int pow){

    DIR *dir;
    class dirent *ent;
    class stat st;


}

std::string Processor::getText() {

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