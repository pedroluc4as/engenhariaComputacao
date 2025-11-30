#pragma once
#include "VeiculoAutonomo.h"

class OnibusAutonomo : public VeiculoAutonomo {
private:
    int lotacao;
    bool acessibilidade;

public:
    OnibusAutonomo(int id, std::string posicao, double bateria, int lotacao, bool acessibilidade);

    void planejarRota(std::string destino) override;
    void mover() override;
    void estrategiaRecarga() const override;

    bool detectarObstaculos() const override;
    double consumoPorKm() const override;
};