#pragma once
#include <string>

class Funcionario {
protected:
    int id;
    std::string nome;
    std::string documento;

public:
    Funcionario(int id, const std::string& nome, const std::string& doc);
    virtual ~Funcionario();

    int getId() const;
    std::string getNome() const;
    std::string getDocumento() const;

    virtual double calcularPagamento() const = 0;
    virtual std::string gerarDemonstrativo() const = 0;
};
