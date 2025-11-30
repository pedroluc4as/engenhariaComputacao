#include "../Headers/CaminhaoAutonomo.h"
#include <iostream>

CaminhaoAutonomo::CaminhaoAutonomo(int id, std::string posicao, double bateria, double capacidadeCarga, int eixos)
    : VeiculoAutonomo(id, posicao, bateria), capacidadeCarga(capacidadeCarga), eixos(eixos) {}

void CaminhaoAutonomo::planejarRota(std::string destino) {
    std::cout << "Caminhao " << id << ": rota pesada para " << destino << "\n";
}

void CaminhaoAutonomo::mover() {
    std::cout << "Caminhao " << id << ": transporte de carga em andamento.\n";
    bateria -= consumoPorKm() * 7;
}

void CaminhaoAutonomo::estrategiaRecarga() const {
    std::cout << "Caminhao " << id << ": indo para doca de recarga industrial.\n";
}

bool CaminhaoAutonomo::detectarObstaculos() const {
    return true; // Caminhão é grande, detecta algo
}

double CaminhaoAutonomo::consumoPorKm() const {
    return 1.5;
}