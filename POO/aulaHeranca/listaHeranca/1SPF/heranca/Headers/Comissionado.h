#pragma once
#include "Funcionario.h"

class Comissionado : public Funcionario {
private:
    double percentual;
    double vendas;
    double salarioBase;
    double tetoComissao;

public:
    Comissionado(int id, const std::string& nome, const std::string& doc,
                 double percentual, double vendas, double salarioBase = 0.0, double teto = 10000.0);
    double calcularPagamento() const override;
    std::string gerarDemonstrativo() const override;
};
