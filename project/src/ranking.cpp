#include "ranking.h"
#include "resultado.h"


Ranking::Ranking (vector<Resultado> resultados){
	this->resultados = resultados;
}


void Ranking::set_resultados(vector<Resultado>  resultados){
	this->resultados = resultados;
}


void Ranking::addToListaResultados(Resultado resultado){	//adiciona a lista cada resultado obtido
	resultados.push_back(resultado);
}

bool ordenacaoCrescente(Resultado r1, Resultado r2){		//fun�ao complemetar para ajudar no sort (3� parametro do sort)
	return r1.get_pontuacao() > r2.get_pontuacao();
}

bool ordenacaoDecrescente(Resultado r1, Resultado r2){ 		//fun�ao complemetar para ajudar no sort (3� parametro do sort)
	return r1.get_pontuacao() < r2.get_pontuacao();
}

void Ranking::OrdenarPrimeiros(){
	sort(this->resultados.begin(), this->resultados.end(), ordenacaoCrescente);	//ordenacao crescente
}

void Ranking::PrintResultados(){
	for(Resultado &i : this->resultados){
		cout << i.get_pontuacao() << " " << i.get_nomePessoa() << " \t" << "Data: " << i.get_dia() << "/" << i.get_mes() << "/" << i.get_ano() << endl;
	}
}

void  Ranking::OrdenarUltimos(){
	sort(this->resultados.begin(), this->resultados.end(), ordenacaoDecrescente);		//ordenacao decrescente
}

bool ordenarMap(pair<string, int> elem1 ,pair<string, int> elem2){
	return elem1.second > elem2.second;
	};



void Ranking::OrdenarMilhoes(){
	map <string, int> vencedores;
	typedef function <bool(pair<string, int>, pair<string, int>)> Comparator;
	Comparator compFunction = ordenarMap;

	for(Resultado &i : this->resultados){
		if (i.get_pontuacao() == 1000000){
			vencedores[i.get_nomePessoa()]++;
		}
	}

	set<pair<string, int>, Comparator> vencedoresOrdenados(
		vencedores.begin(), vencedores.end(), compFunction);

	for (pair<string, int> element : vencedoresOrdenados){
		cout << element.first << " :: " << element.second << " Vitorias" << endl;
	}

} 

vector<Resultado> Ranking::get_resultados(){
	return this->resultados;
}
