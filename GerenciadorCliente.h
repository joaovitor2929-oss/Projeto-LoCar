#ifndef GERENCIADORCLIENTE_H
#define GERENCIADORCLIENTE_H
#include <map>
#include <vector>
#include "Cliente.h"

class GerenciadorCliente {
private:
    std::map<int, Cliente> clientes;
    int proximoId = 1;

public:
    int cadastrar(const std::string& nome, const std::string& documento,
                    const std::string& telefone);
    Cliente* buscarPorId(int id);
    Cliente* buscarPorCpf(const std::string& documento);
    std::vector<const Cliente*> buscarPorNome(const std::string& nome) const;
    bool estaVazia() const;
    void listarClientes() const;
    bool atualizarDados(int id, const std::string& novoNome, const std::string& novoTelefone);
    bool remover(int id);
};



#endif