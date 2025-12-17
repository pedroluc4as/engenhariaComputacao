#pragma once
#include "TiposMidia.cpp"
#include <vector>
#include <memory>

class GerenciadorCatalogo {
private:
    std::vector<std::unique_ptr<Midia>> catalogo;

public:
    void adicionarMidia(std::unique_ptr<Midia> m) {
        catalogo.push_back(std::move(m));
    }

    void listarTudo() const {
        std::cout << "\n--- Catalogo Completo ---\n";
        for (const auto& m : catalogo) {
            m->infoDetalhada();
        }
        std::cout << "-------------------------\n";
    }

    void reproduzirItem(int indice) {
        if (indice >= 0 && indice < (int)catalogo.size()) {
            catalogo[indice]->reproduzir();
        } else {
            std::cout << "Indice invalido.\n";
        }
    }

    void pesquisar(const std::string& termo) const {
        std::cout << "\nResultados para '" << termo << "':\n";
        bool encontrou = false;
        for (const auto& m : catalogo) {
            if (m->combina(termo)) {
                m->reproduzir(); 
                encontrou = true;
            }
        }
        if (!encontrou) std::cout << "Nenhum item encontrado.\n";
    }
};