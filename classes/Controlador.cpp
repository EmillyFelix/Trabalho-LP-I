#include <iostream>
#include "../headers/Controlador.h"
#include "../leituraEscrita/headers/leCidade.h"
#include "../leituraEscrita/headers/lePassageiro.h"

Controlador::Controlador(){
    cidades = carregarCidades();

    auto pesquisarCidadeLambda = [this](const string& nome) -> Cidade* {
        return this->pesquisarCidade(nome);
    };

    passageiros = carregarPassageiros(cidades, pesquisarCidadeLambda);
}

void Controlador::cadastrarCidade(string nome){
    Cidade* novaCidade = new Cidade(nome);
    salvarCidade(novaCidade);
    cidades = carregarCidades();
}

Cidade* Controlador::pesquisarCidade(string nome){
    for (auto& cidade: *cidades){
        if (cidade.getNome() == nome && cidade.getNome() != "Em_Transito"){
            return &cidade;
        }
    }
    cout << "Cidade "<< nome <<" não Encontrada." << endl;
    return nullptr;
}

void Controlador::cadastrarPassageiro(string nome, string nomeCidade){
    Cidade* localAtual = pesquisarCidade(nomeCidade);
    if (localAtual != nullptr){
        Passageiro* novoPassageiro = new Passageiro(nome, localAtual);
        salvarPassageiro(novoPassageiro);
        
        auto pesquisarCidadeLambda = [this](const string& nome) -> Cidade* {
            return this->pesquisarCidade(nome);
        };
    
        passageiros = carregarPassageiros(cidades, pesquisarCidadeLambda);
    }
}

void Controlador::relatarPassageiros(){
    if (passageiros != nullptr){
        for (auto& passageiro: *passageiros){
            string localAtual = passageiro.getLocalAtual()->getNome();

            if (localAtual!= "Em_Transito"){
                cout << passageiro.getNome() << " | " << localAtual << " | " << endl;
            } else {
                cout << passageiro.getNome() << "Em Trânsito " << "origem" << "destino" << endl;
            }
        }
    } else {
        cout << "Erro ao carregar os passageiros." << endl;
    }
    cout << endl;
}

void Controlador::relatarCidades(){
    if (cidades != nullptr){
        for (auto& cidade : *cidades) {
            if (cidade.getNome() != "Em_Transito"){
                cout << "- "<< cidade.getNome() << endl;
            }
        }
    } else {
        cout << "Erro ao carregar cidades.\n";
    }
    cout << endl;
}

Controlador::~Controlador(){
    delete cidades;
    delete passageiros;
}

// void Controlador::cadastrarTrajetos(string nomeOrigem, string nomeDestino, char tipo, int distancia){
//     //criar uma funcao que acesse o vetor de cidades cadastradas, use o metodo getNome() e se getNome() == nome, retornar a cidade (origem)
//     //fazer o mesmo para destino
//     //criar o trajeto
// }

// void cadastrarTransportes(string nome, char tipo, int capacidade, int velocidade, int distanciaEntreDescanso, int tempoDescanso, string localAtual){
//     //criar uma funcao que acesse o vetor de cidades cadastradas, use o metodo getNome() e se getNome() == nome, retornar a cidade (localAtual)
//     //criar o transpote
// }

// void iniciarViagem(string nomeTransporte, vector<string> nomesPassageiros, string nomeOrigem, string nomeDestino){
//     //criar uma funcao que acesse o vetor de transportes, use o getNome() e retorne o nome do transporte
//     //fazer o mesmo para nomeOrigem e nomeDestino
// }

// void avancarHoras(){
//     //transporte e viagem
// }