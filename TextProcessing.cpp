#include "TextProcessing.hpp"

template <typename T, int sz>
int len(T(&)[sz]){
    return sz;
}


Processor::Processor(std::string dirPath) {
    DirPath = dirPath.c_str();
    //std::cout << dirPath << std::endl;
    //std::cout << DirPath << std::endl;

    patricia = NULL;
}

Processor::~Processor() {
    //delete DirPath;
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
    struct dirent *ent;
    std::cout << DirPath << std::endl;

    if((dir=opendir(DirPath.c_str())) !=NULL){
        while((ent = readdir(dir)) !=NULL){

            if(ent->d_type==DT_REG) {
                printf("%s\n", ent->d_name);
                files.push_back(DirPath+std::string(ent->d_name));
            }
        }
        closedir(dir);
    }else{
        std::cout << DirPath << std::endl;
        perror("Error al leer");
        return;
    }

}

std::string Processor::getText(int i) {


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

std::string Processor::getDir() {
    return DirPath;
}