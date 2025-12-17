#include "SistemaFolha.cpp"

int main() {
    SistemaFolha folha;

    try {
        folha.adicionarFuncionario(std::make_unique<Assalariado>(1, "Joao Silva", "123.456", 3000.0));
        
        folha.adicionarFuncionario(std::make_unique<Horista>(2, "Maria Souza", "789.012", 50.0, 50.0)); 
        
        folha.adicionarFuncionario(std::make_unique<Comissionado>(3, "Carlos Vendas", "345.678", 50000.0, 10.0, 1200.0));
        
        folha.adicionarFuncionario(std::make_unique<Comissionado>(4, "Ana Top", "999.888", 200000.0, 10.0, 1200.0, 5000.0));

        folha.gerarFolhaPagamento();

    } catch (const std::exception& e) {
        std::cerr << "Erro no sistema: " << e.what() << "\n";
    }

    return 0;
}