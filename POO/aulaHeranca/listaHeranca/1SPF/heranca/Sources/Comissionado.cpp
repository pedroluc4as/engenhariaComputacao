#include "../Headers/Comissionado.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

Comissionado::Comissionado(int id, const std::string& nome, const std::string& doc,
                           double percentual, double vendas, double salarioBase, double teto)
    : Funcionario(id, nome, doc),
      percentual(percentual), vendas(vendas),
      salarioBase(salarioBase), tetoComissao(teto)
{
    if (percentual < 0 || percentual > 100)
        throw std::invalid_argument("Percentual de comissão deve estar entre 0 e 100");
}

double Comissionado::calcularPagamento() const {
    double comissao = vendas * (percentual / 100.0);
    if (comissao > tetoComissao)
        comissao = tetoComissao;
    return salarioBase + comissao;
}

std::string Comissionado::gerarDemonstrativo() const {
    std::ostringstream oss;
    oss << "Comissionado: " << nome << "\n"
        << "Vendas: R$ " << vendas << "\n"
        << "Percentual: " << percentual << "%\n"
        << "Salário base: R$ " << salarioBase << "\n"
        << "Pagamento total: R$ " << std::fixed << std::setprecision(2) << calcularPagamento() << "\n";
    return oss.str();
}