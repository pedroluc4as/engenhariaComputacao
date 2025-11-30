#include "../Headers/GerenciadorMidia.h"
#include <iostream>

void GerenciadorMidia::add(std::unique_ptr<Midia> m) {
    midias.push_back(std::move(m));
}

void GerenciadorMidia::list() const {
    std::cout << "\n=== Catálogo de Mídias ===\n";
    for (const auto& m : midias)
        std::cout << m->infoDetalhada() << "\n";
}

void GerenciadorMidia::openAll() const {
    for (const auto& m : midias) {
        m->abrir();
        m->reproduzir();
    }
}

void GerenciadorMidia::filter(const std::string& filtro) const {
    std::cout << "\n=== Resultado da busca por \"" << filtro << "\" ===\n";
    for (const auto& m : midias)
        if (m->combina(filtro))
            std::cout << m->infoDetalhada() << "\n";
}
