#include "doctest.h"

#include "ajuda.h"
#include "ajudaCartas.h"
#include "ajudaUniversitarios.h"
#include "ajudaConhecido.h"
#include "pergunta.h"
#include "repositorio.h"

#include <typeinfo>
#include <string.h>
#include <iostream>

TEST_CASE("01 - Testando Ajuda Default") {
    string *alternativas = new string[4];
    alternativas[0] = "altA";
    alternativas[1] = "altB";
    alternativas[2] = "altC";
    alternativas[3] = "altD";
    Pergunta *p = new Pergunta("pergunta", alternativas, 1, 1);
    Ajuda ajuda(p);
    CHECK(ajuda.get_options().compare("") == 0);
    Ajuda ajudaUndefined;
    CHECK(ajudaUndefined.isUndefined);
}

TEST_CASE("02 - Testando Ajuda Cartas") {
    string *alternativas = new string[4];
    alternativas[0] = "altA";
    alternativas[1] = "altB";
    alternativas[2] = "altC";
    alternativas[3] = "altD";
    Pergunta *p = new Pergunta("pergunta", alternativas, 1, 1);
    AjudaCartas ajudaCartas(p);
    CHECK(ajudaCartas.get_options().compare("Existem 4 cartas na mesa, para virar uma digite um número de 1 a 4") == 0);
    CHECK_THROWS(ajudaCartas.choose_option(0));
    CHECK_THROWS(ajudaCartas.choose_option(5));

    ajudaCartas.choose_option(2);
    PerguntaComAjuda* perguntaComAjuda = ajudaCartas.get_perguntaComAjuda();

    int eliminadas = 0;
    for(int i = 0; i < 4; i++){
        string alt = perguntaComAjuda->get_alternativa(i);
        if (alt.find("[Alternativa Eliminada]") != std::string::npos) {
            eliminadas ++;
        }
    }
    CHECK(eliminadas >= 1);
    CHECK(eliminadas <= 3);
}

TEST_CASE("02 - Testando Ajuda Cartas") {
    string *alternativas = new string[4];
    alternativas[0] = "altA";
    alternativas[1] = "altB";
    alternativas[2] = "altC";
    alternativas[3] = "altD";
    Pergunta *p = new Pergunta("pergunta", alternativas, 1, 1);
    AjudaCartas ajudaCartas(p);
    CHECK(ajudaCartas.get_options().compare("Existem 4 cartas na mesa, para virar uma digite um número de 1 a 4") == 0);
    CHECK_THROWS(ajudaCartas.choose_option(0));
    CHECK_THROWS(ajudaCartas.choose_option(5));

    ajudaCartas.choose_option(2);
    PerguntaComAjuda* perguntaComAjuda = ajudaCartas.get_perguntaComAjuda();

    int eliminadas = 0;
    for(int i = 0; i < 4; i++){
        string alt = perguntaComAjuda->get_alternativa(i);
        if (alt.find("[Alternativa Eliminada]") != std::string::npos) {
            eliminadas ++;
        }
    }
    CHECK(eliminadas >= 1);
    CHECK(eliminadas <= 3);
}

TEST_CASE("03 - Testando Ajuda Universitários") {
    string *alternativas = new string[4];
    alternativas[0] = "altA";
    alternativas[1] = "altB";
    alternativas[2] = "altC";
    alternativas[3] = "altD";
    Pergunta *p = new Pergunta("pergunta", alternativas, 1, 1);
    AjudaUniversitarios ajudaUniversitarios(p);
    CHECK(ajudaUniversitarios.get_options().compare("") == 0);

    PerguntaComAjuda* perguntaComAjuda = ajudaUniversitarios.get_perguntaComAjuda();
    CHECK(perguntaComAjuda->get_ajuda().find("Votos dos universitários:") != std::string::npos);
}

TEST_CASE("04 - Testando Ajuda Conhecido") {
    string *alternativas = new string[4];
    alternativas[0] = "altA";
    alternativas[1] = "altB";
    alternativas[2] = "altC";
    alternativas[3] = "altD";
    Pergunta *p = new Pergunta("pergunta", alternativas, 1, 1);
    AjudaConhecido ajudaConhecido(p);
    CHECK(ajudaConhecido.get_options().compare("1- Ajuda do Irmão\n2- Ajuda do Pai\n3- Ajuda da Mãe\n4- Ajuda do Amigo") == 0);

    CHECK_THROWS(ajudaConhecido.choose_option(0));
    CHECK_THROWS(ajudaConhecido.choose_option(5));

    ajudaConhecido.choose_option(1);
    PerguntaComAjuda* perguntaComAjuda = ajudaConhecido.get_perguntaComAjuda();
    CHECK(perguntaComAjuda->get_ajuda().find("do Irmão") != std::string::npos);

    ajudaConhecido.choose_option(2);
    perguntaComAjuda = ajudaConhecido.get_perguntaComAjuda();
    CHECK(perguntaComAjuda->get_ajuda().find("do Pai") != std::string::npos);

    ajudaConhecido.choose_option(3);
    perguntaComAjuda = ajudaConhecido.get_perguntaComAjuda();
    CHECK(perguntaComAjuda->get_ajuda().find("da Mãe") != std::string::npos);

    ajudaConhecido.choose_option(4);
    perguntaComAjuda = ajudaConhecido.get_perguntaComAjuda();
    CHECK(perguntaComAjuda->get_ajuda().find("do Amigo") != std::string::npos);
}

TEST_CASE("05 - Testando sorteio de perguntas") {
    
    vector<Pergunta *> perguntas = Repositorio().sortearPerguntas(5);
    
    CHECK(perguntas.size() == 5);

    // TESTA SE DIFICULDADE ESTÁ ORDENADA
    CHECK(perguntas[0]->get_dificuldade() == 1);
    CHECK(perguntas[1]->get_dificuldade() == 2);
    CHECK(perguntas[2]->get_dificuldade() == 2);
    CHECK(perguntas[3]->get_dificuldade() == 2);
    CHECK(perguntas[4]->get_dificuldade() == 3);

    // TESTA COM NUMERO MULTIPLO DE 3
    perguntas = Repositorio().sortearPerguntas(3);
    CHECK(perguntas.size() == 3);
    CHECK(perguntas[0]->get_dificuldade() == 1);
    CHECK(perguntas[1]->get_dificuldade() == 2);
    CHECK(perguntas[2]->get_dificuldade() == 3);

    // TESTA SE A ALTERNATIVAS FORAM SORTEADAS DE FORMA CORRETA
    string *alternativas = perguntas[0]->get_alternativas();
    CHECK(alternativas[0].compare(perguntas[0]->get_alternativa(0)) == 0);
    CHECK(alternativas[1].compare(perguntas[0]->get_alternativa(1)) == 0);
    CHECK(alternativas[2].compare(perguntas[0]->get_alternativa(2)) == 0);
    CHECK(alternativas[3].compare(perguntas[0]->get_alternativa(3)) == 0);

    // TESTA SE OS ATRIBUTOS SAO VALIDOS
    CHECK(typeid(perguntas[0]->get_pergunta()) == typeid(string));
    CHECK(typeid(perguntas[0]->get_respostaCorreta()) == typeid(int));

}


TEST_CASE("06 - Testando busca e salvamento resultado") {
    
    Repositorio repositorio = Repositorio();
    int numResultados = repositorio.buscarResultados().size();

    Resultado r = Resultado("teste", 0, 12, 12, 2019);
    repositorio.salvarResultado(r);

    vector<Resultado> resultados = repositorio.buscarResultados();

    // TESTA SE NUMERO DE RESULTADOS ATUALIZOU
    CHECK(resultados.size() == numResultados + 1);

    // TESTA SE O ULTIMO RESULTADO É IGUAL AO RESULTADO SALVO
    CHECK(resultados[numResultados].get_nomePessoa().compare(r.get_nomePessoa()) == 0);
    CHECK(resultados[numResultados].get_pontuacao() == r.get_pontuacao());
    CHECK(resultados[numResultados].get_ano() == r.get_ano());
    CHECK(resultados[numResultados].get_mes() == r.get_mes());
    CHECK(resultados[numResultados].get_dia() == r.get_dia());

}

TEST_CASE("07 - Testando classe Pergunta"){
    string *alternativas = new string[4];
    alternativas[0] = "altA";
    alternativas[1] = "altB";
    alternativas[2] = "altC";
    alternativas[3] = "altD";
    Pergunta *p = new Pergunta("pergunta", alternativas, 1, 1);
    CHECK(p->get_pergunta() == "pergunta");
    CHECK(p->get_respostaCorreta() == 1);
    CHECK(p->get_dificuldade() == 1);
 }
 TEST_CASE("08 - Testando classe Resultado"){
     Resultado *r = new Resultado("fulano", 1000000, 31, 1, 2019);
     CHECK(r->get_nomePessoa() == "fulano");
     CHECK(r->get_pontuacao() == 1000000);
     CHECK(r->get_dia() == 31);
     CHECK(r->get_mes() == 1);
     CHECK(r->get_ano() == 2019);
}