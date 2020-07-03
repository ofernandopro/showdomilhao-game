#include <iostream>
#include <string>
#include "ajuda.h"

using namespace std;


Ajuda::Ajuda(Pergunta *pergunta){    
    this->pergunta = pergunta;
}

Ajuda::Ajuda(){    
    this->isUndefined = true;
}

string Ajuda::get_options(){
    return "";
}

void Ajuda::choose_option(int option){

}

PerguntaComAjuda* Ajuda::get_perguntaComAjuda(){	
    return this->perguntaComAjuda;
}