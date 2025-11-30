#include "../Headers/OnibusAutonomo.h"
#include <iostream>

OnibusAutonomo::OnibusAutonomo(int id, std::string posicao, double bateria, int lotacao, bool acessibilidade)
    : VeiculoAutonomo(id, posicao, bateria), lotacao(lotacao), acessibilidade(acessibilidade) {}

void OnibusAutonomo::planejarRota(std::string destino) {
    std::cout << "Onibus " << id << ": rota com paradas ate " << destino << "\n";
}

void OnibusAutonomo::mover() {
    std::cout << "Onibus " << id << ": parando no proximo ponto.\n";
    bateria -= consumoPorKm() * 6;
}

void OnibusAutonomo::estrategiaRecarga() const {
    std::cout << "Onibus " << id << ": retornando a garagem central.\n";
}

bool OnibusAutonomo::detectarObstaculos() const {
    return false;
}

double OnibusAutonomo::consumoPorKm() const {
    return 1.0;
}