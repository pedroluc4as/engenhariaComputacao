#pragma once
#include "Forma.h"

class Retangulo : public Forma {
private:
    Ponto cantoSuperiorEsquerdo;
    double largura, altura;
    double anguloRotacao;

public:
    Retangulo(Ponto canto, double l, double a);

    void desenhar(Canvas& canvas) const override;
    void mover(double dx, double dy) override;
    double area() const override;
    double perimetro() const override;
    std::unique_ptr<Forma> clonar() const override;

    void escalar(double fator) override;
    void rotacionar(double anguloGraus) override;
};