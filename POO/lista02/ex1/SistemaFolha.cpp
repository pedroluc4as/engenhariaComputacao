#pragma once
#include "TiposFuncionarios.cpp"
#include <vector>
#include <memory>

class SistemaFolha {
private:
    std::vector<std::unique_ptr<Funcionario>> funcionarios;

public:
    void adicionarFuncionario(std::unique_ptr<Funcionario> f) {
        funcionarios.push_back(std::move(f));
    }

    void gerarFolhaPagamento() const {
        std::cout << "\n=== Folha de Pagamento ===\n";
        double totalEmpresa = 0.0;
        for (const auto& f : funcionarios) {
            std::cout << f->gerarDemonstrativo() << "\n";
            totalEmpresa += f->calcularPagamento();
        }
        std::cout << "--------------------------\n";
        std::cout << "Custo Total da Empresa: R$: REAIS" << std::fixed << std::setprecision(2) << totalEmpresa << "\n";
        std::cout << "==========================\n";
    }
};