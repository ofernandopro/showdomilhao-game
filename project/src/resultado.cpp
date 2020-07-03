#include <iostream>
#include <string>
#include "resultado.h"

using namespace std;

Resultado::Resultado(string nomePessoa, int pontuacao, int dia, int mes, int ano){
    this->nomePessoa = nomePessoa;
    this->pontuacao = pontuacao;
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

string Resultado::get_nomePessoa(){
    return this->nomePessoa;
}

int Resultado::get_pontuacao(){
    return this->pontuacao;
}

int Resultado::get_dia(){
    return this->dia;
}

int Resultado::get_mes(){
    return this->mes;
}

int Resultado::get_ano(){
    return this->ano;
}

void Resultado::set_nomePessoa(string nomePessoa){
    this->nomePessoa = nomePessoa;
}

void Resultado::set_pontuacao(int pontuacao){
    this->pontuacao = pontuacao;
}

void Resultado::set_dia(int dia){
    this->dia = dia;
}

void Resultado::set_mes(int mes){
    this->mes = mes;
}

void Resultado::set_ano(int ano){
    this->ano = ano;
}
