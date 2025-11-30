#pragma once
#include "Funcionario.h"

class Assalariado : public Funcionario {
private:
    double salarioMensal;

public:
    Assalariado(int id, const std::string& nome, const std::string& doc, double salario);
    double calcularPagamento() const override;
    std::string gerarDemonstrativo() const override;
};