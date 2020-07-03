#include <iostream>
#include <string>
#include "perguntaComAjuda.h"

using namespace std;

// Construtor vazio
PerguntaComAjuda::PerguntaComAjuda() : Pergunta() {}

PerguntaComAjuda::PerguntaComAjuda(Pergunta *pergunta, string ajuda) : Pergunta(pergunta->get_pergunta(), pergunta->get_alternativas(), pergunta->get_respostaCorreta(), pergunta->get_dificuldade()) {    
    this->ajuda = ajuda;    
}

string PerguntaComAjuda::get_ajuda(){
    return this->ajuda;
}

void PerguntaComAjuda::mostraAlternativas(){
	Pergunta::mostraAlternativas();
    cout << ajuda << endl;
}