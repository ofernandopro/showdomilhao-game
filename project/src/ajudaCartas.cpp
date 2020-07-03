#include <iostream>
#include <string>
#include "ajudaCartas.h"
#include <stdlib.h>

using namespace std;


AjudaCartas::AjudaCartas(Pergunta *pergunta) : Ajuda(pergunta){
	cartas = new int[4];
	for(int i = 0; i < 4; i++){
		cartas[i] = (rand() % 3) + 1;		
	}
}

string AjudaCartas::get_options() {
    return "Existem 4 cartas na mesa, para virar uma digite um número de 1 a 4";
}

void AjudaCartas::choose_option(int option){
	if(option < 1 || option > 4) throw invalid_argument("Opção inválida");
	option--;
	int qtdExcluir = cartas[option];
	int qtdExcluirFinal = qtdExcluir;
	while(qtdExcluir > 0){
		int excluir = rand() % 4;				
		if(pergunta->tem_alternativa(excluir) && pergunta->get_respostaCorreta() != excluir){
			pergunta->remover_alternativa(excluir);
			qtdExcluir--;
		}
	}
	this->perguntaComAjuda = new PerguntaComAjuda(this->pergunta, to_string(qtdExcluirFinal) + " alternativas foram eliminadas");
}

PerguntaComAjuda* AjudaCartas::get_perguntaComAjuda(){
	return this->perguntaComAjuda;
}


