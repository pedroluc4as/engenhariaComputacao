#include <iostream>
#include <vector>
#include <memory>

#include "../Headers/Assalariado.h"
#include "../Headers/Horista.h"
#include "../Headers/Comissionado.h"

int main() {
    std::vector<std::unique_ptr<Funcionario>> funcionarios;

    funcionarios.push_back(std::unique_ptr<Assalariado>(
        new Assalariado(1, "Pedro", "123.456.789-00", 3000.00)));

    funcionarios.push_back(std::unique_ptr<Horista>(
        new Horista(2, "Lucas", "987.654.321-00", 25.0, 50)));

    funcionarios.push_back(std::unique_ptr<Comissionado>(
        new Comissionado(3, "Isadora", "111.222.333-44", 10, 40000, 1500, 3000)));

    std::cout << "+++Folha de Pagamento+++\n\n";
    for (const auto& f : funcionarios) {
        std::cout << f->gerarDemonstrativo() << "\n";
    }

    return 0;
}
