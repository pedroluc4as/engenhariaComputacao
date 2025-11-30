#include "../Headers/CarroAutonomo.h"
#include <iostream>

CarroAutonomo::CarroAutonomo(int id, std::string posicao, double bateria, int passageiros, double autonomia)
    : VeiculoAutonomo(id, posicao, bateria), passageiros(passageiros), autonomia(autonomia) {}

void CarroAutonomo::planejarRota(std::string destino) {
    std::cout << "Carro " << id << ": rota calculada para " << destino << "\n";
}

void CarroAutonomo::mover() {
    if (detectarObstaculos()) {
        std::cout << "Carro " << id << ": obstaculo! Desviando...\n";
    } else {
        std::cout << "Carro " << id << ": dirigindo suavemente.\n";
        bateria -= consumoPorKm() * 5; // Simula gasto
    }
}

void CarroAutonomo::estrategiaRecarga() const {
    std::cout << "Carro " << id << ": indo para estacao eletrica rapida.\n";
}

bool CarroAutonomo::detectarObstaculos() const {
    return false; // Sem obstaculos por enquanto
}

double CarroAutonomo::consumoPorKm() const {
    return 0.8;
}