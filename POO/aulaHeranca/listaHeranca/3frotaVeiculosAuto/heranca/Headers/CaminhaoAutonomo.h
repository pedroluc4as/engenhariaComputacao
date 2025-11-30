#pragma once
#include "VeiculoAutonomo.h"

class CaminhaoAutonomo : public VeiculoAutonomo {
private:
    double capacidadeCarga;
    int eixos;

public:
    CaminhaoAutonomo(int id, std::string posicao, double bateria, double capacidadeCarga, int eixos);

    void planejarRota(std::string destino) override;
    void mover() override;
    void estrategiaRecarga() const override;

    bool detectarObstaculos() const override;
    double consumoPorKm() const override;
};