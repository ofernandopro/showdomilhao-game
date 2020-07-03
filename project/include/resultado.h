#ifndef RESULTADO_H
#define RESULTADO_H

using namespace std;
#include <string>       /* string */

class Resultado{

    private:
        string nomePessoa;
        int pontuacao;
        int dia, mes, ano;

    public:
        Resultado(string, int, int, int, int);

        string get_nomePessoa();
        int get_pontuacao();
        int get_dia();
        int get_mes();
        int get_ano();

        void set_nomePessoa(string nomePessoa);
        void set_pontuacao(int pontuacao);
        void set_dia(int dia);
        void set_mes(int mes);
        void set_ano(int ano);

};


#endif // RESULTADO_H