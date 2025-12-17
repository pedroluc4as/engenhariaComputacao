#pragma once
#include <iostream>
#include <string>
#include <cmath>

struct Posicao {
    double x;
    double y;
};

class ModuloNavegacao {
public:
    void calcularRota(Posicao atual, Posicao destino, const std::string& tipoVeiculo) {
        std::cout << "[Nav] Calculando rota para " << tipoVeiculo << " de (" 
                  << atual.x << "," << atual.y << ") ate (" 
                  << destino.x << "," << destino.y << ")\n";
    }
};

class ModuloDiagnostico {
public:
    void executarCheckup(int id) {
        std::cout << "[Diag] Diagnostico completo do sistema ID: " << id << ". Tudo OK.\n";
    }
};