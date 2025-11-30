#include "../Headers/Assalariado.h"
#include <sstream>
#include <iomanip>

Assalariado::Assalariado(int id, const std::string& nome, const std::string& doc, double salario)
    : Funcionario(id, nome, doc), salarioMensal(salario) {}

double Assalariado::calcularPagamento() const {
    return salarioMensal;
}

std::string Assalariado::gerarDemonstrativo() const {
    std::ostringstream oss;
    oss << "Assalariado: " << nome << "\n"
        << "Salário Mensal: R$ " << std::fixed << std::setprecision(2) << salarioMensal << "\n";
    return oss.str();
}