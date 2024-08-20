#include "../headers/Cidade.h"

Cidade::Cidade(string nome) {
    this->nome = nome;
}

string Cidade::getNome() {
    return this->nome;
}

int Cidade::getVisitantes(){
    return this->visitantes;
}

void Cidade::addVisitantes(int n){
    this->visitantes = this->getVisitantes() + n;
}