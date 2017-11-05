#ifndef TEXTPROCESSING_H_
#define TEXTPROCESSING_H_

#include <cmath>
#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <dirent.h>


#include "Patricia.hpp"
#include "LinearProbingHashing.hpp"
#include "Ternary.hpp"

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
        std::string DirPath;
        std::vector <std::string> files;
        Patricia patricia;
        /**
         *Funciones para remover
         */
        std::string toLowerCase(std::string);
        std::string removePunctuationAndStuff(std::string);
        std::string removeNumbers(std::string);
        int countWords();

    public:
        Processor(std::string);
        ~Processor();
        /**
         * Dos archivos con largo similar
         */
        void getFilesInDir(int pow);

        /**
         * Retorna string de archivo preprocesado
         * Recibe 0 o 1 como parametro para representar
         * texto.
         */
        std::string getText(int i);
        double similarityPatricia();
        double similarityHLP();
        double similarityTernary();
        std::string getDir();


};




#endif