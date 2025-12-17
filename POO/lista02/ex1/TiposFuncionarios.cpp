#pragma once
#include "Funcionario.cpp"
#include <algorithm>
#include <stdexcept>

class Assalariado : public Funcionario {
private:
    double salarioMensal;

public:
    Assalariado(int id, std::string nome, std::string doc, double salario)
        : Funcionario(id, nome, doc), salarioMensal(salario) {
        if (salario < 0) throw std::invalid_argument("Salario nao pode ser negativo");
    }

    double calcularPagamento() const override {
        return salarioMensal;
    }

    std::string gerarDemonstrativo() const override {
        std::stringstream ss;
        ss << "[Assalariado] " << nome << " | Doc: " << documento 
           << " | Salario Fixo: R$ " << std::fixed << std::setprecision(2) << salarioMensal;
        return ss.str();
    }
};

class Horista : public Funcionario {
private:
    double valorHora;
    double horasTrabalhadas;

public:
    Horista(int id, std::string nome, std::string doc, double valorH, double horas)
        : Funcionario(id, nome, doc), valorHora(valorH), horasTrabalhadas(horas) {
        if (valorH < 0 || horas < 0) throw std::invalid_argument("Valores negativos invalidos");
    }

    double calcularPagamento() const override {
        double total = 0.0;
        if (horasTrabalhadas <= 44.0) {
            total = horasTrabalhadas * valorHora;
        } else {
            double horasExtras = horasTrabalhadas - 44.0;
            total = (44.0 * valorHora) + (horasExtras * valorHora * 1.5);
        }
        return total;
    }

    std::string gerarDemonstrativo() const override {
        std::stringstream ss;
        ss << "[Horista] " << nome << " | Horas: " << horasTrabalhadas 
           << " | Pagamento: R$ " << std::fixed << std::setprecision(2) << calcularPagamento();
        return ss.str();
    }
};

class Comissionado : public Funcionario {
private:
    double vendasBrutas;
    double percentualComissao; 
    double salarioBase;
    double tetoComissao;

public:
    Comissionado(int id, std::string nome, std::string doc, double vendas, double perc, double base = 0.0, double teto = 10000.0)
        : Funcionario(id, nome, doc), vendasBrutas(vendas), percentualComissao(perc), salarioBase(base), tetoComissao(teto) {
        if (perc < 0 || perc > 100) throw std::invalid_argument("Percentual invalido");
    }

    double calcularPagamento() const override {
        double comissao = vendasBrutas * (percentualComissao / 100.0);
        if (comissao > tetoComissao) comissao = tetoComissao;
        return salarioBase + comissao;
    }

    std::string gerarDemonstrativo() const override {
        std::stringstream ss;
        ss << "[Comissionado] " << nome << " | Vendas: " << vendasBrutas 
           << " | Base: " << salarioBase
           << " | Total: R$ " << std::fixed << std::setprecision(2) << calcularPagamento();
        return ss.str();
    }
};