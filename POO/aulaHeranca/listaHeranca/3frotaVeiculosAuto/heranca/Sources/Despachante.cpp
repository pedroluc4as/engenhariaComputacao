#include "../Headers/Despachante.h"
#include <iostream>

Despachante::~Despachante() {
    for (size_t i = 0; i < frota.size(); i++) {
        delete frota[i]; // Libera a memória de cada veículo
    }
    frota.clear();
}

void Despachante::adicionar(VeiculoAutonomo* v) {
    frota.push_back(v);
}

void Despachante::atribuirRota(std::string destino) {
    for (size_t i = 0; i < frota.size(); i++) {
        frota[i]->planejarRota(destino);
    }
}

void Despachante::moverTodos() {
    for (size_t i = 0; i < frota.size(); i++) {
        frota[i]->mover();
    }
}

void Despachante::gerarRelatorio() const {
    std::cout << "\n=== Relatorio de Frota ===\n";
    for (size_t i = 0; i < frota.size(); i++) {
        frota[i]->relatorioStatus();
    }
}