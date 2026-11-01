#include <iostream>
#include <cctype>
#include <utility>
#include "GerenciadorCliente.h"
using namespace std;

static string somenteDigitos(const string& texto) {
    string resultado;
    for (unsigned char c : texto) {
        if (isdigit(c)) resultado += c;
    }
    return resultado;
}

static string normalizarTexto(const string& texto) {
    static const vector<pair<string, char>> acentos = {
        {"á",'a'},{"à",'a'},{"â",'a'},{"ã",'a'},{"é",'e'},{"ê",'e'},{"í",'i'},
        {"ó",'o'},{"ô",'o'},{"õ",'o'},{"ú",'u'},{"ç",'c'},
        {"Á",'a'},{"À",'a'},{"Â",'a'},{"Ã",'a'},{"É",'e'},{"Ê",'e'},{"Í",'i'},
        {"Ó",'o'},{"Ô",'o'},{"Õ",'o'},{"Ú",'u'},{"Ç",'c'}
    };
    string resultado;
    for (size_t i = 0; i < texto.size(); ) {
        bool achou = false;
        for (const auto& par : acentos) {
            if (texto.compare(i, par.first.size(), par.first) == 0) {
                resultado += par.second;
                i += par.first.size();
                achou = true;
                break;
            }
        }
        if (!achou) {
            resultado += static_cast<char>(tolower(static_cast<unsigned char>(texto[i])));
            i++;
        }
    }
    return resultado;
}

int GerenciadorCliente::cadastrar(const string& nome, const string& cpf, const string& telefone) {
    string documento = somenteDigitos(cpf);
    if (documento.empty() || buscarPorCpf(documento) != nullptr){
        return -1;
    }

    int id = proximoId++;
    clientes.emplace(id, Cliente(id, nome, documento, telefone));
    return id;
}

Cliente *GerenciadorCliente::buscarPorId(int id) {
    auto it = clientes.find(id);
    return it == clientes.end() ? nullptr : &it->second;
}

Cliente *GerenciadorCliente::buscarPorCpf(const string& cpf) {
    string cpfLimpo = somenteDigitos(cpf);

    for (auto& par : clientes) {
        if (par.second.getCpf() == cpfLimpo) return &par.second;
    }
    return nullptr;
}

vector<const Cliente*> GerenciadorCliente::buscarPorNome(const string& nome) const {
    vector<const Cliente*> resultados;
    string buscado = normalizarTexto(nome);

    for (const auto& par : clientes) {
        if (normalizarTexto(par.second.getNome()).find(buscado) != string::npos) {
            resultados.push_back(&par.second);
        }
    }
    return resultados;
}

bool GerenciadorCliente::estaVazia() const {
    return clientes.empty();
}

void GerenciadorCliente::listarClientes() const {
     for (const auto& par : clientes) {
        cout << "ID: " << par.first 
             << " | Nome: " << par.second.getNome() 
             << " | CPF: " << par.second.getCpf() 
             << " | Tel: " << par.second.getTelefone() << "\n";
    }
}

bool GerenciadorCliente::atualizarDados(int id, const string& novoNome, const string& novoTelefone) {
    Cliente* pessoaBuscada = buscarPorId(id);

    if(pessoaBuscada == nullptr) {
        return false;
    }

    if(novoNome.empty() != NULL) {
        pessoaBuscada->setNome(novoNome);
    }

    if(novoTelefone.empty() != NULL) {
        pessoaBuscada->setTelefone(novoTelefone);
    }

    return true;
}

bool GerenciadorCliente::remover(int id) {
    return clientes.erase(id);
}
