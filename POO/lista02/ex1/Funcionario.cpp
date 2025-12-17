#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Funcionario {
protected:
    int id;
    std::string nome;
    std::string documento;

public:
    Funcionario(int id, std::string nome, std::string doc) 
        : id(id), nome(nome), documento(doc) {}
    
    virtual ~Funcionario() = default;

    virtual double calcularPagamento() const = 0;
    virtual std::string gerarDemonstrativo() const = 0;

    int getId() const { return id; }
    std::string getNome() const { return nome; }
};