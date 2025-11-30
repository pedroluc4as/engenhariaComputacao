#pragma once
#include "VeiculoAutonomo.h"

class CarroAutonomo : public VeiculoAutonomo {
private:
    int passageiros;
    double autonomia;

public:
    CarroAutonomo(int id, std::string posicao, double bateria, int passageiros, double autonomia);

    void planejarRota(std::string destino) override;
    void mover() override;
    void estrategiaRecarga() const override;

    bool detectarObstaculos() const override;
    double consumoPorKm() const override;
};

