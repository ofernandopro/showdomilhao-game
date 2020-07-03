# JogoShowDoMilhao
Jogo criado em C++ sem interface gráfica inspirado no famoso Show do Milhão. 

# Documentação

O projeto Show do milhão foi desenvolvido com o intuito de explorar e colocar em prática os conhecimentos obtidos na disciplina Programação e Desenvolvimento de Software 2 (PDS2), no curso de Sistemas de Informação na UFMG. Dentre os vários conteúdos aplicados neste projeto, o foco foi na orientação à objetos, principalmente nos conceitos de herança, encapsulamento, poliformismo, entre outros.

O projeto foi realizado no segundo semestre de 2019. Os desenvolvedores do projeto tiveram forte inspiração no show de TV da SBT chamado "Show do milhão". Inclusive, todas as perguntas contidas neste jogo foram retiradas de lá, todos os créditos das perguntas pertencem à SBT.

### Fluxo Principal 

O fluxo principal é responsável por todo o funcionamento do jogo, e se encontra no arquivo main.
while(jogo>0) - loop infinito para o jogador sempre poder voltar para o menu principal quando perder, desistir ou se ganhar 1 milhão
while(opcaoEscolhida == 0) - escreve o menu na tela com as opções(1 para iniciar jogo, 2 para mostrar regras do jogo e 3 para mostrar ranking)
while(opcaoEscolhida==1) - inicia novo jogo, mostra perguntas Funções:
void mostrarPergunta() - imprime as perguntas de um arquivo externo e mostra ajudas
int valorPergunta(int qtdAcertos) - função que retorna o valor em dinheiro de cada pergunta de acordo com o numero da pergunta(valores pré-estabelecidos)
void menuOpcoes() - mostra o menu principal
void menuRanking() - mostra o menu do ranking
void regrasJogo() - mostra as regras do jogo
void ganhou1milhao() - animação para quando o jogador ganha 1 milhão
void mostrarAjudas() - mostra ajuda escolhida pelo jogador ou imprime que não é possivel usar ajudas caso já tenha usado todas
Ajuda* getAjuda(char, Pergunta) - retorna o tipo de ajuda de acordo com a ajuda escolhida pelo jogador

### Classes

#### Classe Pergunta

Pergunta() - Construtor vazio que inicializa a variável alternativas como um vetor de strings
Pergunta(string, string*, int, int) - inicializa pergunta, respostaCorreta, dificuldade e alternativas
Pergunta::get_respostaCorreta() - função que retorna um inteiro referente à resposta correta
Pergunta::get_dificuldade() - função que retorna um inteiro referente à dificuldade da pergunta
Pergunta::string get_pergunta() - função que retorna a pergunta
Pergunta::verificaAcerto(char respostaCorreta) - retorna verdadeiro ou falso para a alternativa marcada pelo jogador
Pergunta::mostraAlternativas() - retorna as alternativas
Classe PerguntaComAjuda
PerguntaComAjuda(Pergunta *pergunta, string ajuda) - O objeto é construído com uma instância de Pergunta e uma string, que é a ajuda que alguma classe Ajuda retornou
PerguntaComAjuda::get_ajuda() - Retorna a ajuda que alguma classe Ajuda retornou
PerguntaComAjuda::mostraAlternativas() - Escreve as alternativas usando o método mostraAlternativas() da classe Pergunta e logo abaixo escreve a string ajuda

#### Classe Resultado

Resultado::get_nomePessoa() - função string que contém o nome da pessoa respectivo àquele resultado
Resultado::get_pontuacao() - função inteira para armazenar a pontuação da pessoa
Resultado::get_dia, Resultado::get_mes, Resultado::get_ano - retornam a data daquele resultado
Repositório
Repositório é a classe responsável por gerenciar os arquivos de texto que armazenam as perguntas e resutlados. Ele possui apenas três métodos públicos e alguns outros auxiliares. Os arquivos que a classe gerencia são: resources/perguntas/faceis.txt, resources/perguntas/medias.txt, resources/perguntas/dificeis.txt
resources/resultados/resultados.txt

Os métodos da classe são:

vector<Pergunta*> sortearPerguntas(int) - Sorteia as perguntas do jogo a partir do número de perguntas passado por parâmetro, já fazendo a divisão por dificuldade
vector buscarResultados() - Retorna todos os resultados salvos no arquivo resultados.txt
void salvarResultado(Resultado) - Salva um novo resultado no arquivo resultados.txt
private string resultadoToString(Resultado) - Converte um objeto do tipo resultado em string, para salvar no arquivo de texto
private Resultado stringToResultado(string) - Cria um objeto do tipo Resultado a partir de uma string lida do arquivo resultados.txt
private Pergunta stringToPergunta(string) - Cria um objeto do tipo Pergunta a partir de uma string lida dos arquivo da pasta resources/perguntas/
A classe também possui três atributos, são eles:

string caminhoPerguntas - Indica o caminho para a pasta onde ficam salvas as perguntas
string caminhoResultados - Indica o caminho para a pasta onde ficam salvas as perguntas
string sequenciaSeparadora - É utilizado para definir a separação entre os atributos durante a conversão de string para objeto e vice-versa.
Rankings O ranking é uma classe simples que possui apenas um atributo, que é um vector de resultados. Sempre que o jogo é finalizado, o resultado é adicionado à esse vector, portanto, a atualização do ranking é instantânea.
-Ranking(Resultado*) - Construtor da classe que recebe como parâmetro um vector de resultados salvo ao final do jogo. Salva nome, pontuação e data.

-void ordenarPrimeiros() - Ordena os resultados entre os melhores jogadores. -void ordenarUltimos() - Ordena os resultados entre os piores jogadores. obs: Ambas as funções ordenarPrimeiros e ordenarUltimos possuem uma função booleana auxiliar correspondente que é usada como terceiro parâmetro da função sort. -void ordenarMilhoes() - Ordena os jogadores que possuem maior número de vitórias, ou seja, aqueles que obteram a pontuação de um milhão o maior número de vezes.

#### Classe Ajudas
8.1. Classe Ajuda A classe Ajuda é uma classe com o objetivo de servir para representar ajudas indefinidas (inválidas) e servir para ser o modelo (pai), para as classes AjudaConhecido, AjudaCartas e AjudaUniversitarios herdarem. Cada uma das classes filhas de comportam de uma forma.

Ajuda(Pergunta*) - Constrói-se a classe com uma pergunta.

string Ajuda::get_options() - Retorna as opções que o usuário tem para usar a ajuda.

void Ajuda::choose_option(int) - Seleciona a opção da ajuda, este método já constroi a PerguntaComAjuda nas classes que herdam Ajuda.

PerguntaComAjuda* Ajuda::get_perguntaComAjuda() - Retorna uma instância de PerguntaComAjuda, que é a Pergunta que foi passada no construtor já adaptada.

#### Classe AjudaConhecido

string AjudaConhecido::get_options() - Retorna as opções: Ajuda do irmão, do pai, da mãe ou do amigo.
void AjudaConhecido::choose_option(int) - Seleciona a opção da ajuda, a dica que a opção dá tem 80% de chance de acerto.
8.3. Classe AjudaCartas

string AjudaCartas::get_options() - Retorna as opções: Carta 1, 2, 3 ou 4.
void AjudaCartas::choose_option(int) - Seleciona a carta, ao selecionar, a Pergunta com Ajuda será gerada com 1, 2 ou 3 alternativas eliminadas.
8.4. Classe AjudaUniversitarios

AjudaUniversitarios(Pergunta*) - Constrói-se a classe com uma pergunta e já a modifica sorteando de forma inteligente porcentagens de recomendações dosuniversitários. Há uma grande chance de que a maioria dos universitários recomende a alternativa correta, porém a chance não é de 100%, algumas vezes os universitários falham.
string AjudaUniversitarios::get_options() - Retorna uma string vazia.
void AjudaUniversitarios::choose_option(int) - Método vazio, não faz nada.
