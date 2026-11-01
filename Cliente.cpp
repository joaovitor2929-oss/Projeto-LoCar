#include <iostream>
#include "Cliente.h"
using namespace std;

Cliente::Cliente(int id, std::string nome, std::string cpf, const std::string telefone) {
}

int Cliente::getId() const {
    return id;
}

string Cliente::getNome() const {
    return nome;
}

string Cliente::getCpf() const {
    return cpf;
}

string Cliente::getTelefone() const {
    return telefone;
}

void Cliente::setNome(string nome) {
    this->nome = nome;
}
void Cliente::setTelefone(string telefone) {
    this->telefone = telefone;
}