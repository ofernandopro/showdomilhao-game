#ifndef PERGUNTA_H
#define PERGUNTA_H

using namespace std;
#include <stdexcept>
#include <string>       /* string */

class Pergunta{

    private:
        string pergunta;
        string *alternativas;
        int respostaCorreta;
        int dificuldade;        

    public:
        Pergunta(string, string*, int, int);
        Pergunta();
        
        virtual ~Pergunta(){
            alternativas = nullptr;
            delete alternativas;
        }

        int get_respostaCorreta();
        int get_dificuldade();
        string get_pergunta();
        string get_alternativa(int);

        string* get_alternativas();

        void set_respostaCorreta(int respostaCorreta);
        void set_dificuldade(int dificuldade);
        void set_pergunta(string pergunta);
        void set_alternativa(int, string);
        bool tem_alternativa(int);
        void remover_alternativa(int);

        bool verificaAcerto(char respostaCorreta);
        virtual void mostraAlternativas();

};

#endif // PERGUNTA_H