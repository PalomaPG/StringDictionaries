#include "LinearProbingHashing.hpp"


/**
 * LINEAR PROBING HASH
 * **/

LinearProbingHashing::LinearProbingHashing() {
    size = PRIME_VALUES[prime_index];
    table= new string[size];
    count =0;
}

LinearProbingHashing::~LinearProbingHashing() {

    for(unsigned int i=0; i<size; i++)
        delete &table[i];
    size=NULL;
    delete size;
    delete count;
    delete prime_index;
    delete[] table;
}

unsigned int LinearProbingHashing::h(string s) {

    unsigned int calc_val=0;

    for(unsigned int i=0; i<s.size(); i++){
        unsigned char c = s[i];

        calc_val+= (unsigned int)(c*pow((double)size, (double)i));
    }

    return calc_val % size;
}

void LinearProbingHashing::insert(string word) {

    unsigned int init_index =  this->h(word);

    unsigned int index = init_index;
    string aux = table[index];

    if(aux.compare("")==0){
        count++;

        if((((double)count)/((double) size))>load_factor)
            doubleTable();

        table[index] = word;
        return;
    }
    while(aux.compare("")!=0 && init_index!=index){/*La ultima condicion indica que da vuelta*/
        index = index+1;
        aux = table[index % size];
    }

    if(aux.compare("")==0 && init_index!=index){
        count++;

        if((((double)count)/((double) size))>load_factor)
            doubleTable();

        table[index] = word;
        return;
    }
    return;
}


int LinearProbingHashing::search(string word) {

    unsigned int init_index =  this->h(word);
    string aux = table[init_index];
    if(aux.compare(word)==0) return init_index;
    unsigned int index;

    while(aux.compare(word)!=0 && index!=init_index){
        index = index+1;
        aux = table[index % size];
    }
    if(index==init_index) return -1;
    else return index;

}

void LinearProbingHashing::printTable() {

    for(unsigned int i=0; i<size; i++){
        string aux = table[i];

        if(aux.compare("")!=0){
            cout <<  aux <<endl;
        }
    }
}

void LinearProbingHashing::doubleTable() {
    prime_index++;
    size = PRIME_VALUES[prime_index];
    string* aux_table = table;
    delete []table;
    table = new string[size];

    for(unsigned int i=0; i<aux_table->size(); i++){
        string s = aux_table[i];
        insert(s);
    }
    delete[] aux_table;
}
