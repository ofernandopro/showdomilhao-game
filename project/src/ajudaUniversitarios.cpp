#include <iostream>
#include <string>
#include "ajudaUniversitarios.h"
#include <stdlib.h>

//#include "util.h"

using namespace std;


AjudaUniversitarios::AjudaUniversitarios(Pergunta *pergunta) : Ajuda(pergunta){

}


PerguntaComAjuda* AjudaUniversitarios::get_perguntaComAjuda(){	
	int *percentual = new int[4];
	int correta = pergunta->get_respostaCorreta();
	

	for(int i = 0; i < 4; i++){		
		percentual[i] = 0;		
	}

	percentual[correta] = 20 + (rand() % 90);
	int total = 100-percentual[correta];

	for(int i = 0; i < 4; i++){
		int descontar = rand() % total;
		percentual[i] += descontar;
		total -= descontar;
	}

	percentual[(rand()%3)] += total;

	string ajuda = "";
	for(int i = 0; i < 4; i++){
		ajuda += "\nAlternativa " + get_letra(i+1) + ": " + to_string(percentual[i]) + "%";
	}

	this->perguntaComAjuda = new PerguntaComAjuda(pergunta, "Votos dos universitários: " + ajuda);
	return this->perguntaComAjuda;
}

