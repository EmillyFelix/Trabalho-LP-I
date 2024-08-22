# Trabalho-LP-I
Arquivos para o projeto final da disciplina de Linguagem de Programação I

Estrutura do Projeto
Este projeto é uma simulação de um sistema de gerenciamento de viagens que inclui cidades, transportes, passageiros e trajetos. A organização do projeto é feita de maneira modular, dividida em várias categorias conforme a funcionalidade de cada classe e a organização do código.

Arquivos .cpp:

1. cidade.cpp
   
Descrição: Este arquivo implementa a classe Cidade, responsável por gerenciar o nome e o número de visitantes de uma cidade.

Métodos:

- Cidade::Cidade(string nome): Construtor que inicializa o nome da cidade.
- string Cidade::getNome(): Retorna o nome da cidade.
- int Cidade::getVisitantes(): Retorna o número de visitantes da cidade.
- void Cidade::addVisitantes(int n): Adiciona um número de visitantes à cidade.

2. passageiros.cpp
   
Descrição: Este arquivo implementa a classe Passageiro, que gerencia as informações dos passageiros, como nome e a cidade em que se encontram.

Métodos:

- Passageiro::Passageiro(string nome, Cidade* localAtual): Construtor que inicializa o nome do passageiro e a cidade atual.
- string Passageiro::getNome(): Retorna o nome do passageiro.
- Cidade* Passageiro::getLocalAtual(): Retorna a cidade atual do passageiro.
- void Passageiro::setLocalAtual(Cidade* localAtual): Define a nova cidade do passageiro.

3. rota.cpp
   
Descrição: Este arquivo implementa a classe Rota, responsável por calcular a melhor rota entre cidades, considerando o tipo de transporte.

Métodos:

vector<Trajeto> Rota::calcularMelhorRota(vector<Trajeto>* trajetos, Cidade* origem, Cidade* destino, char tipoTransporte): Calcula a melhor rota de acordo com o tipo de transporte entre a cidade de origem e destino.
Estruturas:

struct TrajetoInfo: Estrutura auxiliar utilizada na fila de prioridade para calcular a melhor rota.

4. trajeto.cpp
   
Descrição: Este arquivo implementa a classe Trajeto, que representa uma ligação entre duas cidades, com um tipo de transporte específico e uma distância associada.

Métodos:

- Trajeto::Trajeto(Cidade* origem, Cidade* destino, char tipo, int distancia): Construtor que inicializa um trajeto entre duas cidades.
- Cidade* Trajeto::getOrigem() const: Retorna a cidade de origem do trajeto.
- Cidade* Trajeto::getDestino() const: Retorna a cidade de destino do trajeto.
- char Trajeto::getTipo() const: Retorna o tipo de transporte utilizado no trajeto.
- int Trajeto::getDistancia() const: Retorna a distância do trajeto.
- void Trajeto::setOrigem(Cidade* origem): Define a cidade de origem.
- void Trajeto::setDestino(Cidade* destino): Define a cidade de destino.
- void Trajeto::setTipo(char tipo): Define o tipo de transporte.
- void Trajeto::setDistancia(int distancia): Define a distância do trajeto.

5. transporte.cpp
   
Descrição: Este arquivo implementa a classe Transporte, que gerencia os detalhes de um meio de transporte, como nome, tipo, capacidade, velocidade e localização atual.

Métodos:

- Transporte::Transporte(string nome, char tipo, int capacidade, int velocidade, Cidade* localAtual, int distanciaEntreDescanso, int tempoDescanso, int tempoDescansoAtual): Construtor que - inicializa os atributos do transporte.
- string Transporte::getNome(): Retorna o nome do transporte.
- char Transporte::getTipo(): Retorna o tipo do transporte.
- int Transporte::getCapacidade(): Retorna a capacidade do transporte.
- int Transporte::getVelocidade(): Retorna a velocidade do transporte.
- int Transporte::getDistanciaEntreDescansos(): Retorna a distância que o transporte pode percorrer antes de precisar descansar.
- int Transporte::getTempoDescanso(): Retorna o tempo necessário para o descanso.
- int Transporte::getTempoDescansoAtual(): Retorna o tempo de descanso atual.
- Cidade* Transporte::getLocalAtual(): Retorna a cidade atual do transporte.
- void Transporte::aumentarTempoDescansoAtual(): Aumenta o tempo de descanso atual, reiniciando-o se atingir o tempo de descanso total.
- void Transporte::setLocalAtual(Cidade* novoLocal): Define a nova cidade do transporte.


6. viagem.cpp
   
Descrição: Este arquivo implementa a classe Viagem, responsável por gerenciar uma viagem, incluindo o transporte, os passageiros e o trajeto.

Métodos:

- Viagem::Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto, int horasEmTransito, int distanciaPercorrida, bool emAndamento, bool hasProxima): Construtor que inicializa uma viagem sem uma viagem subsequente.
- Viagem::Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto, int horasEmTransito, int distanciaPercorrida, bool emAndamento, bool hasProxima, Viagem* proxima): Construtor que inicializa uma viagem com uma viagem subsequente.
- bool Viagem::isEmAndamento(): Retorna se a viagem está em andamento.
- bool Viagem::getHasProxima(): Retorna se existe uma próxima viagem.
- int Viagem::getHorasEmTransito(): Retorna o número de horas em trânsito.
- int Viagem::getDistanciaPercorrida(): Retorna a distância percorrida até o momento.
- Transporte* Viagem::getTransporte(): Retorna o transporte utilizado na viagem.
- vector<Passageiro*> Viagem::getPassageiros(): Retorna os passageiros da viagem.
- Trajeto* Viagem::getTrajeto(): Retorna o trajeto atual da viagem.
- Viagem* Viagem::getProxima(): Retorna a próxima viagem, se houver.
- void Viagem::iniciarViagem(Cidade* emTransito): Inicia a viagem, alterando a localização dos passageiros e do transporte para "em trânsito".
- void Viagem::finalizarViagem(): Finaliza a viagem, redefinindo o tempo em trânsito.
- void Viagem::avancarHoras(): Avança o tempo em horas se a viagem estiver em andamento.
- void Viagem::relatarEstado(): Relata o estado atual da viagem (em desenvolvimento).


Arquivos .h

1. cidade.h
Descrição:
Este arquivo define a classe Cidade, que é responsável por armazenar e gerenciar informações relacionadas a uma cidade, como seu nome e o número de visitantes.

Definições de Classe:

Classe: Cidade
Membros Privados:
- string nome: Nome da cidade.
- int visitantes: Número de visitantes da cidade.
- Membros Públicos:
- Cidade(string nome): Construtor que inicializa a cidade com um nome.
- string getNome(): Retorna o nome da cidade.
- int getVisitantes(): Retorna o número de visitantes da cidade.
- void addVisitantes(int n): Adiciona um número de visitantes à cidade.

Guarda de Inclusão:

#ifndef CIDADE_H
#define CIDADE_H
#endif

2. passageiros.h
Descrição:
Este arquivo define a classe Passageiro, que gerencia informações sobre passageiros, como o nome e a cidade onde estão atualmente.

Definições de Classe:

Classe: Passageiro
- Membros Privados:
- string nome: Nome do passageiro.
- Cidade* localAtual: Ponteiro para a cidade atual onde o passageiro está.
- Membros Públicos:
- Passageiro(string nome, Cidade* localAtual): Construtor que inicializa o passageiro com um nome e a cidade atual.
- string getNome(): Retorna o nome do passageiro.
- Cidade* getLocalAtual(): Retorna a cidade atual do passageiro.
- void setLocalAtual(Cidade* localAtual): Define a nova cidade do passageiro.

Guarda de Inclusão:

#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H
#endif

3. rota.h
Descrição:
Este arquivo define a classe Rota, que calcula a melhor rota entre duas cidades com base em trajetos disponíveis e no tipo de transporte.

Definições de Classe:

Classe: Rota
Membros Públicos:
- static vector<Trajeto> calcularMelhorRota(vector<Trajeto>* trajetos, Cidade* origem, Cidade* destino, char tipoTransporte): Método estático que calcula a melhor rota entre a cidade de origem e destino, considerando o tipo de transporte.

Guarda de Inclusão:

#ifndef ROTA_H
#define ROTA_H
#endif

4. trajeto.h
Descrição:
Este arquivo define a classe Trajeto, que representa um trajeto entre duas cidades, incluindo o tipo de transporte e a distância associada.

Definições de Classe:

Classe: Trajeto
Membros Privados:
- Cidade* origem: Ponteiro para a cidade de origem.
- Cidade* destino: Ponteiro para a cidade de destino.
- char tipo: Tipo de transporte ('A' para aquático, 'T' para terrestre).
- int distancia: Distância do trajeto em quilômetros.

Membros Públicos:
- Trajeto(Cidade* origem, Cidade* destino, char tipo, int distancia): Construtor que inicializa um trajeto com origem, destino, tipo de transporte e distância.
- Cidade* getOrigem() const: Retorna a cidade de origem do trajeto.
- Cidade* getDestino() const: Retorna a cidade de destino do trajeto.
- char getTipo() const: Retorna o tipo de transporte utilizado no trajeto.
- int getDistancia() const: Retorna a distância do trajeto.
- void setOrigem(Cidade* origem): Define a cidade de origem.
- void setDestino(Cidade* destino): Define a cidade de destino.
- void setTipo(char tipo): Define o tipo de transporte.
- void setDistancia(int distancia): Define a distância do trajeto.

Guarda de Inclusão:

#ifndef TRAJETO_H
#define TRAJETO_H
#endif

5. transporte.h
Descrição:
Este arquivo define a classe Transporte, que gerencia os detalhes de um meio de transporte, como nome, tipo, capacidade, velocidade, e localização atual.

Definições de Classe:

Classe: Transporte
Membros Privados:
- string nome: Nome do transporte.
- char tipo: Tipo de transporte ('A' para aquático, 'T' para terrestre).
- int capacidade: Capacidade de passageiros.
- int velocidade: Velocidade do transporte em km/h.
- int distanciaEntreDescanso: Distância que o transporte pode percorrer antes de precisar descansar.
- int tempoDescanso: Tempo necessário de descanso em horas.
- int tempoDescansoAtual: Tempo de descanso atual em horas.
- Cidade* localAtual: Ponteiro para a cidade atual onde o transporte está.

Membros Públicos:
- Transporte(string nome, char tipo, int capacidade, int velocidade, Cidade* localAtual, int distanciaEntreDescanso, int tempoDescanso, int tempoDescansoAtual=0): Construtor que - ------ inicializa os atributos do transporte.
- string getNome(): Retorna o nome do transporte.
- char getTipo(): Retorna o tipo do transporte.
- int getCapacidade(): Retorna a capacidade do transporte.
- int getVelocidade(): Retorna a velocidade do transporte.
- int getDistanciaEntreDescansos(): Retorna a distância que o transporte pode percorrer antes de precisar descansar.
- int getTempoDescanso(): Retorna o tempo necessário de descanso.
- int getTempoDescansoAtual(): Retorna o tempo de descanso atual.
- Cidade* getLocalAtual(): Retorna a cidade atual do transporte.
- void aumentarTempoDescansoAtual(): Aumenta o tempo de descanso atual em uma unidade, e reseta se atingir o tempo de descanso total.
- void setLocalAtual(Cidade* novoLocal): Define a nova cidade do transporte.

Guarda de Inclusão:

#ifndef TRANSPORTE_H
#define TRANSPORTE_H
#endif

6. viagem.h
Descrição:
Este arquivo define a classe Viagem, responsável por gerenciar uma viagem, incluindo o transporte, os passageiros, o trajeto, e o estado da viagem.

Definições de Classe:

Classe: Viagem
Membros Privados:
- Transporte* transporte: Ponteiro para o transporte utilizado na viagem.
- vector<Passageiro*> passageiros: Vetor de ponteiros para os passageiros da viagem.
- Cidade* origem: Ponteiro para a cidade de origem da viagem.
- Trajeto* trajeto: Ponteiro para o trajeto da viagem.
- Viagem* proxima: Ponteiro para a próxima viagem (se houver).
- int horasEmTransito: Número de horas em trânsito.
- int distanciaPercorrida: Distância percorrida até o momento.
- bool emAndamento: Indicador de se a viagem está em andamento.
- bool hasProxima: Indicador de se há uma próxima viagem.

Membros Públicos:
- Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto, int horasEmTransito, int distanciaPercorrida, bool emAndamento, bool hasProxima): Construtor para - - --- inicializar uma viagem sem viagem subsequente.
- Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto, int horasEmTransito, int distanciaPercorrida, bool emAndamento, bool hasProxima, Viagem* proxima): - - -- Construtor para inicializar uma viagem com uma viagem subsequente.
- bool isEmAndamento(): Retorna se a viagem está em andamento.
- bool getHasProxima(): Retorna se há uma próxima viagem.
- int getHorasEmTransito(): Retorna o número de horas em trânsito.
- int getDistanciaPercorrida(): Retorna a distância percorrida até o momento.
- Transporte* getTransporte(): Retorna o transporte utilizado na viagem.
- vector<Passageiro*> getPassageiros(): Retorna os passageiros da viagem.
- Trajeto* getTrajeto(): Retorna o trajeto atual da viagem.
- Viagem* getProxima(): Retorna a próxima viagem, se houver.
- void iniciarViagem(Cidade* emTransito): Inicia a viagem e muda a localização dos passageiros e do transporte para "em trânsito".
- void finalizarViagem(): Finaliza a viagem e redefine o tempo em trânsito.
- void avancarHoras(): Avança o tempo em horas se a viagem estiver em andamento.
- void relatarEstado(): Relata o estado atual da viagem.

Guarda de Inclusão:

#ifndef VIAGEM_H
#define VIAGEM_H
#endif



Arquivos de Leitura/Escrita

1. leCidade.cpp
Descrição:
Este arquivo implementa as funções para salvar e carregar objetos da classe Cidade em um arquivo de texto.

Funções:

- void salvarCidade(Cidade *cidade): Salva o nome de uma cidade no arquivo cidades.txt. O arquivo é aberto no modo de apêndice para adicionar novas cidades sem sobrescrever as existentes.
- vector<Cidade>* carregarCidades(): Carrega os nomes das cidades do arquivo cidades.txt e os armazena em um vetor de objetos Cidade. Retorna um ponteiro para esse vetor.

2. lePassageiros.cpp
   
Descrição:Este arquivo implementa as funções para salvar e carregar objetos da classe Passageiro em um arquivo de texto.

Funções:

- void salvarPassageiro(Passageiro *passageiro): Salva o nome do passageiro e o nome da cidade onde ele está atualmente no arquivo passageiros.txt. O arquivo é aberto no modo de apêndice para adicionar novos passageiros sem sobrescrever os existentes.
- vector<Passageiro>* carregarPassageiros(vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade): Carrega os passageiros do arquivo passageiros.txt, associando-os às cidades que já foram carregadas. Retorna um ponteiro para um vetor de objetos Passageiro.

Observação:
A função carregarPassageiros depende de uma função pesquisarCidade para buscar a cidade correspondente a partir de uma string com o nome da cidade.

3. leTrajeto.cpp
   
Descrição:Este arquivo implementa as funções para salvar e carregar objetos da classe Trajeto em um arquivo de texto.

Funções:

- void salvarTrajeto(Trajeto *trajeto): Salva as informações de um trajeto no arquivo trajetos.txt, incluindo a cidade de origem, cidade de destino, tipo de transporte e a distância. O arquivo é aberto no modo de apêndice.
- vector<Trajeto>* carregarTrajetos(vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade): Carrega os trajetos do arquivo trajetos.txt, associando-os às cidades correspondentes. Retorna um ponteiro para um vetor de objetos Trajeto.

Observação:
A função carregarTrajetos também depende de uma função pesquisarCidade para buscar as cidades de origem e destino.

4. leTransporte.cpp

Descrição:Este arquivo implementa as funções para salvar e carregar objetos da classe Transporte em um arquivo de texto.

Funções:

- void salvarTransporte(Transporte *transporte): Salva as informações de um transporte no arquivo transportes.txt, incluindo o nome, tipo, capacidade, velocidade, cidade atual, distância entre descansos, tempo de descanso e tempo de descanso atual. O arquivo é aberto no modo de apêndice.
- vector<Transporte>* carregarTransportes(vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade): Carrega os transportes do arquivo transportes.txt, associando-os às cidades correspondentes. Retorna um ponteiro para um vetor de objetos Transporte.

Observação:
A função carregarTransportes depende de uma função pesquisarCidade para buscar a cidade atual do transporte.

5. leViagem.cpp

Descrição:
Este arquivo implementa as funções para salvar e carregar objetos da classe Viagem em um arquivo de texto.

Funções:

- void salvarViagem(Viagem *viagem): Salva as informações de uma viagem no arquivo viagens.txt, incluindo o transporte, trajeto, passageiros, horas em trânsito, distância percorrida, se a viagem está em andamento, se há uma próxima viagem, e um ponteiro para a próxima viagem, se houver. O arquivo é aberto no modo de apêndice.
- vector<Viagem>* carregarViagens(vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade, vector<Passageiro>* passageiros, function<Passageiro*(const string&)> pesquisarPassageiro, vector<Transporte>* transportes, function<Transporte*(const string&)> pesquisarTransporte, vector<Trajeto>* trajetos, function<Trajeto*(const string&, const string&, const char&)> pesquisarTrajeto): Carrega as viagens do arquivo viagens.txt, associando-as ao transporte, trajeto, e passageiros correspondentes. Retorna um ponteiro para um vetor de objetos Viagem.

Observação:
Esta função carregarViagens depende de várias funções de pesquisa (pesquisarCidade, pesquisarPassageiro, pesquisarTransporte, e pesquisarTrajeto) para associar corretamente os objetos carregados a partir do arquivo de texto.



Arquivos de Cabeçalho de Leitura/Escrita

1. leCidade.h

Descrição:Este arquivo de cabeçalho define as funções para salvar e carregar objetos da classe Cidade a partir de um arquivo de texto.

Funções:

- void salvarCidade(Cidade *cidade): Salva o nome de uma cidade em um arquivo.
std::vector<Cidade>* carregarCidades(): Carrega os nomes das cidades a partir de um arquivo e retorna um vetor de objetos Cidade.

Guarda de Inclusão:

#ifndef LECIDADE_H
#define LECIDADE_H
#endif

2. lePassageiros.h

Descrição: Este arquivo de cabeçalho define as funções para salvar e carregar objetos da classe Passageiro a partir de um arquivo de texto.

Funções:

- void salvarPassageiro(Passageiro *passageiro): Salva as informações de um passageiro em um arquivo.
- std::vector<Passageiro>* carregarPassageiros(std::vector<Cidade>* cidades, std::function<Cidade*(const std::string&)> pesquisarCidade): Carrega passageiros a partir de um arquivo e os associa às cidades correspondentes. Retorna um vetor de objetos Passageiro.

Guarda de Inclusão:

#ifndef LEPASSAGEIRO_H
#define LEPASSAGEIRO_H
#endif

3. leTrajeto.h
Descrição:Este arquivo de cabeçalho define as funções para salvar e carregar objetos da classe Trajeto a partir de um arquivo de texto.

Funções:

- void salvarTrajeto(Trajeto *trajeto): Salva as informações de um trajeto em um arquivo.
- std::vector<Trajeto>* carregarTrajetos(std::vector<Cidade>* cidades, std::function<Cidade*(const std::string&)> pesquisarCidade): Carrega trajetos a partir de um arquivo e os associa às cidades correspondentes. Retorna um vetor de objetos Trajeto.

Guarda de Inclusão:

#ifndef LETRAJETO_H
#define LETRAJETO_H
#endif

4. leTransporte.h

Descrição:Este arquivo de cabeçalho define as funções para salvar e carregar objetos da classe Transporte a partir de um arquivo de texto.

Funções:

- void salvarTransporte(Transporte *transporte): Salva as informações de um transporte em um arquivo.
- std::vector<Transporte>* carregarTransportes(std::vector<Cidade>* cidades, std::function<Cidade*(const std::string&)> pesquisarCidade): Carrega transportes a partir de um arquivo e os associa às cidades correspondentes. Retorna um vetor de objetos Transporte.

Guarda de Inclusão:

#ifndef LETRANSPORTE_H
#define LETRANSPORTE_H
#endif

5. leViagem.h

Descrição:Este arquivo de cabeçalho define as funções para salvar e carregar objetos da classe Viagem a partir de um arquivo de texto.

Funções:

-void salvarViagem(Viagem *viagem): Salva as informações de uma viagem em um arquivo.
-std::vector<Viagem>* carregarViagens( std::vector<Cidade>* cidades, std::function<Cidade*(const std::string&)> pesquisarCidade, std::vector<Passageiro>* passageiros, -- 
-std::function<Passageiro*(const std::string&)> pesquisarPassageiro, std::vector<Transporte>* transportes, std::function<Transporte*(const std::string&)> pesquisarTransporte, -- ---------std::vector<Trajeto>* trajetos, std::function<Trajeto*(const std::string&, const std::string&, const char&)> pesquisarTrajeto ): Carrega viagens a partir de um arquivo, associando-as -aos objetos correspondentes de transporte, trajeto, e passageiros. Retorna um vetor de objetos Viagem.

Guarda de Inclusão:

#ifndef LEVIAGEM_H
#define LEVIAGEM_H
#endif

Outros Arquivos Importantes

obj/
Descrição: Diretório onde os arquivos objeto gerados durante a compilação são armazenados.

main.cpp
Descrição: O arquivo principal que inicia a execução do programa.
Responsabilidade: Contém a função main() que coordena a execução do programa, criando e manipulando os objetos das classes principais e orquestrando a lógica do sistema.
Precisa ser finalizado


makefile
Descrição: Arquivo de automação usado para compilar o projeto.
Responsabilidade: Define as regras para a compilação dos arquivos fonte e linkagem dos arquivos objeto, facilitando o processo de construção do software.
