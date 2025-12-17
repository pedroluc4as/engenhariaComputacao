#pragma once
#include "VeiculosDerivados.cpp"
#include <vector>
#include <memory>

class Despachante {
private:
    std::vector<std::unique_ptr<VeiculoAutonomo>> frota;

public:
    void adicionarVeiculo(std::unique_ptr<VeiculoAutonomo> v) {
        frota.push_back(std::move(v));
    }

    void despacharFrota(Posicao destinoGeral) {
        std::cout << "\n--- Despachando Frota ---\n";
        for (auto& v : frota) {
            v->planejarRota(destinoGeral);
            v->estrategiaRecarga();
            v->mover();
            std::cout << "-------------------------\n";
        }
    }

    void gerarRelatorioGeral() const {
        std::cout << "\n=== Relatorio Consolidado da Frota ===\n";
        for (const auto& v : frota) {
            v->relatorioStatus();
            std::cout << "Consumo Estimado: " << v->consumoPorKm() << " kWh/km\n";
        }
        std::cout << "======================================\n";
    }
};