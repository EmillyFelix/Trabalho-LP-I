#include "../headers/Transporte.h"

Transporte::Transporte(string nome, char tipo, int capacidade, int velocidade,  Cidade* localAtual, int distanciaEntreDescanso, int tempoDescanso, int tempoDescansoAtual) {
    this->nome = nome;
    this->tipo = tipo;
    this->capacidade = capacidade;
    this->velocidade = velocidade;
    this->localAtual = localAtual;
    this->distanciaEntreDescanso = distanciaEntreDescanso;
    this->tempoDescanso = tempoDescanso;
    this->tempoDescansoAtual = tempoDescansoAtual;
}

string Transporte::getNome() {
    return this->nome;
}

char Transporte::getTipo(){
    return this->tipo;
}

int Transporte::getCapacidade(){
    return this->capacidade;
}

int Transporte::getVelocidade(){
    return this->velocidade;
}

int Transporte::getDistanciaEntreDescansos(){
    return this->distanciaEntreDescanso;
}

int Transporte::getTempoDescanso(){
    return this->tempoDescanso;
}

int Transporte::getTempoDescansoAtual(){
    return this->tempoDescansoAtual;
}

Cidade* Transporte::getLocalAtual(){
    return this->localAtual;
}

void Transporte::aumentarTempoDescansoAtual(){
    this->tempoDescansoAtual = this->tempoDescansoAtual + 1;
    if (tempoDescansoAtual == tempoDescanso){
        tempoDescansoAtual = 0;
    }
}

void Transporte::setLocalAtual(Cidade* novoLocal){
    this->localAtual = novoLocal;
}