#pragma once
#include "Funcionario.h"

class Horista : public Funcionario {
private:
    double valorHora;
    double horasTrabalhadas;

public:
    Horista(int id, const std::string& nome, const std::string& doc, double valorHora, double horas);
    double calcularPagamento() const override;
    std::string gerarDemonstrativo() const override;
};
