
#include <stdio.h>  /* defines FILENAME_MAX */

#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

#ifndef REPOSITORIO_H
#define REPOSITORIO_H

#include "pergunta.h"
#include "resultado.h"
#include <iostream>
#include <fstream>      /* ofstream */
#include <string>       /* string */
#include <stdlib.h>     /* srand, rand */
#include <sstream>      /* stringstream */
#include <ctime>
#include <vector>

using namespace std;

class Repositorio{

    private:
        string caminhoPerguntas;
        string caminhoResultados;
        string sequenciaSeparadora = "****";

        // Resultado
        string resultadoToString(Resultado);
        Resultado stringToResultado(string);
        
        // Pergunta
        string perguntaToString(Pergunta*);
        Pergunta* stringToPergunta(string);

    public:
        Repositorio(); 
        vector<Pergunta*> sortearPerguntas(int);
        vector<Resultado> buscarResultados();
        void salvarResultado(Resultado);
};

#endif