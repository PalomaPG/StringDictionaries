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


#include "Patricia.hpp"
#include "LinearProbingHashing.hpp"
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
        string DirPath;
        vector <string> files;
        vector <string> t1_words;
        vector <string> t2_words;
        /*T1 y T2 en texts*/
        vector <string> texts;
        unsigned int n_words;
        Patricia patricia;
        /**
         *Funciones para remover
         */
        string toLowerCase(string);
        string removePunctuationAndStuff(string);
        string removeNumbers(string);
        int countWords();

    public:
        Processor(string, unsigned int n_w);
        ~Processor();
        /**
         * Dos archivos con largo similar
         */
        void listFilesInDir();

        /**
         * Retorna string de archivo preprocesado
         * Recibe 0 o 1 como parametro para representar
         * texto.
         */
        string getText(unsigned int i);
        void setTexts();
        double similarityPatricia();
        double similarityHLP();
        double similarityTernary();
        void selectWords(string line, unsigned int i);
        //string getDir();


};




#endif