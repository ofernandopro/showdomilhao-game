#include "repositorio.h"

/***************************
 * 
 *  CONSTRUTOR & AUXILIARES
 * 
 * ************************/

Repositorio::Repositorio() {
    // Pega caminho do diretorio
    char c[FILENAME_MAX];
    std::string res = GetCurrentDir(c, sizeof(c));
    string caminhoAtual = c;


    // Substitui \\, no caso do Windows
    string::iterator it;
    for(auto it = caminhoAtual.begin(); it != caminhoAtual.end();++it){
        if(*it == '\\'){
            *it = '/';
        }
    }

    caminhoPerguntas = caminhoAtual + "/resources/perguntas/";
    caminhoResultados = caminhoAtual + "/resources/resultados/resultados.txt";
}


// Função auxiliar que busca index de um valor em um array
int buscarIndexValorArray(int array[], int valor, int tamanho) {
    for (int i=0; i<tamanho; i++) {
        if (array[i] == valor) {
            return i;
        }
    }
    return -1;
}

// Função auxiliar que sorteia numeros sem repeticao
void sortearNumerosSemRepeticao (int *array, unsigned int numSorteados, int alcance) {
    srand (time (NULL));
    int sz, pos, src[alcance];
    unsigned int i;
    for (i = 0; i < sizeof(src)/sizeof(*src); i++)
        src[i] = i + 1;
    sz = alcance;
    for (i = 0; i < numSorteados; i++) {
        pos = rand() % sz;
        array[i] = src[pos];
        src[pos] = src[sz-1];
        sz--;
    }
}


/**************************************
 * 
 *   MÉTODOS DE PERGUNTAS
 * 
 **************************************/

// Número de perguntas precisa ser multiplo de 3, para pegar de todas as dificuldades
vector<Pergunta*> Repositorio::sortearPerguntas(int numPerguntas) {

    // Array com os indexes sorteados
    int indexPerguntasSorteadas[numPerguntas];

    // Vector que armazena as perguntas sorteadas
    vector<Pergunta*> perguntas;

    // Array com os nomes dos arquivos
    string nomesArquivos[] = {"faceis.txt", "medias.txt", "dificeis.txt"};


    int numSorteadas = numPerguntas / 3;

    // Lê perguntas para cada dificuldade
    for (int i=0; i<3; i++) {
        
        // Se o número de perguntas nao for multiplo de 3, sorteia mais medias
        if (i == 1 && numPerguntas % 3 != 0) {
            numSorteadas = numPerguntas / 3 + (1 + (numPerguntas % 2));
        }else {
            numSorteadas = numPerguntas / 3;
        }

        // Sorteia indexes das perguntas
        sortearNumerosSemRepeticao(indexPerguntasSorteadas, numSorteadas, 100);

        // Abre o arquivo
        ifstream arquivo(caminhoPerguntas + nomesArquivos[i]);

        if (arquivo.is_open()) {
            int numLinhaArquivo = 1; // variavel que armazena o index da linha que esta sendo lida
            string linha = ""; // variavel que armazena a linha que esta sendo lida

            // Procura indexes sorteados
            while( getline(arquivo, linha) ) {

                // Verifica se a linha foi sorteada
                if (buscarIndexValorArray(indexPerguntasSorteadas, numLinhaArquivo, numSorteadas) != -1) {
                    // Converte string em pergunta e adiciona na lista
                    perguntas.push_back(stringToPergunta(linha));              
                }

                numLinhaArquivo++;
            }
        }else{
            cout << "Erro ao abrir arquivo: " << caminhoPerguntas << endl;
        }

        // Fecha o arquivo
        arquivo.close();
    }

    return perguntas;
}


// Converte de objeto para string //
string Repositorio::perguntaToString(Pergunta *pergunta) {

    string linha = "";
    linha += pergunta->get_pergunta() + "****";
    linha += pergunta->get_alternativa(0)  + "****";
    linha += pergunta->get_alternativa(1)  + "****";
    linha += pergunta->get_alternativa(2)  + "****";
    linha += pergunta->get_alternativa(3)  + "****";
    linha += pergunta->get_alternativa(3)  + "****";
    linha += pergunta->get_alternativa(pergunta->get_respostaCorreta())  + "****";
    linha += to_string(pergunta->get_dificuldade())  + "****";

    return linha;
}

// Converte de string para objeto //
Pergunta* Repositorio::stringToPergunta(string perguntaStr) {
    Pergunta *pergunta = new Pergunta();
    size_t pos = 0;
    stringstream ss;

    // LÊ ENUNCIADO
    pos = perguntaStr.find(sequenciaSeparadora);
    pergunta->set_pergunta(perguntaStr.substr(0, pos));
    perguntaStr.erase(0, pos + sequenciaSeparadora.length());

    // LÊ ALTERNATIVAS
    for (int i=0; i<4; i++) {
        pos = perguntaStr.find(sequenciaSeparadora);
        pergunta->set_alternativa(i, (perguntaStr.substr(0, pos)));
        perguntaStr.erase(0, pos + sequenciaSeparadora.length());
    }
    
    // LÊ RESPOSTA CORRETA
    pos = perguntaStr.find(sequenciaSeparadora);
    int resposta = 0;
    ss << perguntaStr.substr(0, pos);  
    ss >> resposta;
    ss.clear();
    pergunta->set_respostaCorreta(resposta);
    perguntaStr.erase(0, pos + sequenciaSeparadora.length());

    // LÊ DIFICULDADE
    pos = perguntaStr.find(sequenciaSeparadora);
    int dificuldade = 0;
    ss << perguntaStr.substr(0, pos);  
    ss >> dificuldade;
    ss.clear();
    pergunta->set_dificuldade(dificuldade);
    perguntaStr.erase(0, pos + sequenciaSeparadora.length());

    return pergunta;
}


/**************************************
 * 
 *   MÉTODOS DE RESULTADOS
 * 
 **************************************/

// Salva resultado de um jogo no banco de dados
 void Repositorio::salvarResultado(Resultado resultado) {

    // Converte resultado em string
    string resultadoStr = resultadoToString(resultado); 

    // Abre arquivo
    ofstream arquivo;
    arquivo.open(caminhoResultados, ios_base::app);

    // Salva o resultado convertido
    if (arquivo.is_open()) {
        arquivo << resultadoStr + "\n";
    }else{
        cout << "Erro ao abrir arquivo: " << caminhoResultados;
    }
    
    arquivo.close();
 }

vector<Resultado> Repositorio::buscarResultados() {
    vector<Resultado> resultados;

    // Abre o arquivo
    ifstream arquivo(caminhoResultados);

    if (arquivo.is_open()) {

        // variavel que guarda linha atual do arquivo
        string linha;

        // Percorre arquivo
        while( getline(arquivo, linha) ) {
            resultados.push_back(stringToResultado(linha));
        }
    }

    // Fecha o arquivo
    arquivo.close();

    return resultados;
}

// Converte de objeto para string //
string Repositorio::resultadoToString(Resultado resultado) {

    string linha = "";
    linha += resultado.get_nomePessoa() + "****";

    linha += to_string(resultado.get_pontuacao()) + "****";
    linha += to_string(resultado.get_dia())  + "****";
    linha += to_string(resultado.get_mes()) + "****";
    linha += to_string(resultado.get_ano())  + "****";

    return linha;
}

// Converte de string para objeto //
Resultado Repositorio::stringToResultado(string resultadoStr) {    
    size_t pos = 0;
    stringstream ss;

    // LÊ NOME
    pos = resultadoStr.find(sequenciaSeparadora);
    string nomePessoa = resultadoStr.substr(0, pos);
    resultadoStr.erase(0, pos + sequenciaSeparadora.length());

    // LÊ PONTUAÇÃO
    pos = resultadoStr.find(sequenciaSeparadora);
    float pontuacao = 0;
    ss << resultadoStr.substr(0, pos);  
    ss >> pontuacao;   
    ss.clear();
    resultadoStr.erase(0, pos + sequenciaSeparadora.length());
    
    // LÊ DIA
    pos = resultadoStr.find(sequenciaSeparadora);
    int dia = 0;
    ss << resultadoStr.substr(0, pos);  
    ss >> dia;
    ss.clear();
    resultadoStr.erase(0, pos + sequenciaSeparadora.length());

    // LÊ MÊS
    pos = resultadoStr.find(sequenciaSeparadora);
    int mes = 0;
    ss << resultadoStr.substr(0, pos);  
    ss >> mes;
    ss.clear();   
    resultadoStr.erase(0, pos + sequenciaSeparadora.length());
    
    // LÊ ANO
    pos = resultadoStr.find(sequenciaSeparadora);
    int ano = 0;
    ss << resultadoStr.substr(0, pos);  
    ss >> ano;
    ss.clear();   
    resultadoStr.erase(0, pos + sequenciaSeparadora.length());

    Resultado resultado = Resultado(nomePessoa, pontuacao, dia, mes, ano);

    return resultado;
}

