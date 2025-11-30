#include "../Headers/VeiculoAutonomo.h"
#include <iostream>

VeiculoAutonomo::VeiculoAutonomo(int id, std::string posicao, double bateria)
    : id(id), posicao(posicao), bateria(bateria) {}

VeiculoAutonomo::~VeiculoAutonomo() {}

void VeiculoAutonomo::relatorioStatus() const {
    std::cout << "[ID " << id << "] Posicao: " << posicao
              << " | Bateria: " << bateria << "%" << std::endl;
}