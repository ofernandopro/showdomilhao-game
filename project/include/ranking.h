#ifndef RANKING_H
#define RANKING_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <algorithm>
#include <string>
#include "resultado.h"

using namespace std;

class Ranking{
	private:				
		vector<Resultado> resultados;
		
	public:
		
		Ranking(vector<Resultado> resultados);
		
		
		void set_resultados(vector<Resultado>  resultados); 
		                     
		void addToListaResultados(Resultado resultado);
				
		vector<Resultado> get_lista_resultados();	
		
		void OrdenarPrimeiros();
		
		void PrintResultados();
		     
		void OrdenarUltimos();		
		
		void OrdenarMilhoes();          //ordenando por vit�rias
		
		vector<Resultado> get_resultados();
		
		
};

#endif
