#include <iostream>
#include <string>
#include "ajudaConhecido.h"
#include <stdlib.h>

//#include "util.h"

using namespace std;


AjudaConhecido::AjudaConhecido(Pergunta *pergunta) : Ajuda(pergunta){}


PerguntaComAjuda* AjudaConhecido::get_perguntaComAjuda(){	
	return this->perguntaComAjuda;
}


string AjudaConhecido::get_options() {
    return "1- Ajuda do Irmão\n2- Ajuda do Pai\n3- Ajuda da Mãe\n4- Ajuda do Amigo";
}

void AjudaConhecido::choose_option(int option){
	string conhecido = "";
	switch(option){
		case 1: {
			conhecido = "do Irmão";
			break;
		}
		case 2: {
			conhecido = "do Pai";
			break;
		}
		case 3: {
			conhecido = "da Mãe";
			break;
		}
		case 4: {
			conhecido = "do Amigo";
			break;
		}
		default: throw invalid_argument("Opção inválida");
	}

	int alternativa;

	int correta = (rand() % 4) == 3 ? 0 : 1; //80% de chance de acerto
	if(correta){
		alternativa = this->pergunta->get_respostaCorreta();
	}else{
		do{
			alternativa = rand() % 4;
		} while(alternativa == this->pergunta->get_respostaCorreta());
	}

	this->perguntaComAjuda = new PerguntaComAjuda(this->pergunta, "Dica " + conhecido + ": Alternativa " + get_letra(alternativa+1));
}

