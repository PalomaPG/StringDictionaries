#ifndef TEXTPROCESSING_H_
#define TEXTPROCESSING_H_

#include <cmath>
#include <cstdio>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <dirent.h>


#include "LinearProbingHashing.hpp"
#include "Patricia.hpp"
#include "Ternary.hpp"

using namespace std;

const char Sigma[] =
        {
                'a', 'b', 'c', 'd', 'e',
                'f', 'g', 'h', 'i', 'j',
                'k', 'l', 'm', 'n', 'o',
                'p', 'r', 's', 't', 'u',
                'v', 'w', 'x', 'y', 'z'
        };

class Processor{

    private:

        string file_path;
        vector <string> words;
        vector <string> sample;
        unsigned int n_words;
        unsigned int count=0;
        Patricia* patricia;
        LinearProbingHashing* lph;
        TST* tst;
        /**
         *Funciones para remover
         */
        string toLowerCase(string);
        string removePunctuationAndStuff(string);
        string removeNumbers(string);

        public:
        Processor(string, unsigned int n_w);
        ~Processor();


        /**
         * Retorna string de archivo preprocesado
         * Recibe 0 o 1 como parametro para representar
         * texto.
         */
        void readText();
        vector<string> getSample();
        void verifyNofWords();
        void selectWords(string line);
        void printWords(vector<string> v);

        /**
         * Inizializa diccionarios
         */
        void initPatricia();
        void initLPH();
        void initTernary();

        void destroyTST();
        void destroyLHP();
        void destroyPaty();


        void searchSampleLPH();
        void insertWordsPatricia();
        void searchSamplePatricia();
        void insertWordsLPH();

        double getPatriciaInsertTime();
        unsigned int getPatriciaSize();
};




#endif