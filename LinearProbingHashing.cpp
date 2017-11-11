#include "LinearProbingHashing.hpp"


/**
 * LINEAR PROBING HASH
 * **/

LinearProbingHashing::LinearProbingHashing() {
    table= new string[SIZE];
}
unsigned int LinearProbingHashing::h(string s) {

    unsigned int calc_val=0;

    for(int i=0; i<s.size(); i++){
        unsigned char c = s[i];

        calc_val+= (unsigned int)(c*pow((double)SIZE, (double)i));
    }

    return calc_val % SIZE;
}

void LinearProbingHashing::insert(string word) {

    unsigned int init_index =  this->h(word);

    unsigned int index = init_index;
    string aux = table[index];

    if(aux.compare("")==0){
        table[index] = word;
        return;
    }
    while(aux.compare("")!=0 && init_index!=index){/*La ultima condicion indica que da vuelta*/
        index = index+1;
        aux = table[index % SIZE];
    }

    if(aux.compare("")==0 && init_index!=index){
        table[index] = word;
        return;
    }
    return;
}


vector<unsigned int> LinearProbingHashing::search(string s) {


    return vector<unsigned int>();
}

void LinearProbingHashing::printTable() {

    for(int i=0; i<SIZE; i++){
        string aux = table[i];

        if(aux.compare("")!=0){
            cout <<  aux <<endl;
        }
    }
}
