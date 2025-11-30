#include "../Headers/Horista.h"
#include <sstream>
#include <iomanip>

Horista::Horista(int id, const std::string& nome, const std::string& doc, double valorHora, double horas)
    : Funcionario(id, nome, doc), valorHora(valorHora), horasTrabalhadas(horas) {}

double Horista::calcularPagamento() const {
    const double horasBase = 44.0;
    if (horasTrabalhadas <= horasBase)
        return horasTrabalhadas * valorHora;

    double extras = horasTrabalhadas - horasBase;
    return (horasBase * valorHora) + (extras * valorHora * 1.5);
}

std::string Horista::gerarDemonstrativo() const {
    std::ostringstream oss;
    oss << "Horista: " << nome << "\n"
        << "Horas trabalhadas: " << horasTrabalhadas << "\n"
        << "Valor hora: R$ " << valorHora << "\n"
        << "Pagamento: R$ " << std::fixed << std::setprecision(2) << calcularPagamento() << "\n";
    return oss.str();
}