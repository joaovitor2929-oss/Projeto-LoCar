#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

class Cliente {
private:
    int id;
    std::string nome;
    std::string cpf;
    std::string telefone;

public:
    Cliente(int id, std::string nome, std::string cpf,
            const std::string telefone);
    int getId() const;
    std::string getNome() const;
    std::string getCpf() const;
    std::string getTelefone() const;

    void setNome(std::string nome);
    void setTelefone(std::string telefone);
};

#endif