#pragma once
#include "Forma.h"

class Circulo : public Forma {
private:
    Ponto centro;
    double raio;

public:
    Circulo(Ponto c, double r);

    void desenhar(Canvas& canvas) const override;
    void mover(double dx, double dy) override;
    double area() const override;
    double perimetro() const override;
    std::unique_ptr<Forma> clonar() const override;

    void escalar(double fator) override;
    void rotacionar(double anguloGraus) override;

    double getRaio() const { return raio; }
};