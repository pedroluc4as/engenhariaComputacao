#pragma once
#include "Canvas.h"
#include <memory>

class Forma {
public:
    virtual ~Forma() = default;

    virtual void desenhar(Canvas& canvas) const = 0;
    virtual void mover(double dx, double dy) = 0;
    virtual double area() const = 0;
    virtual double perimetro() const = 0;

    virtual std::unique_ptr<Forma> clonar() const = 0;

    virtual void escalar(double fator) = 0;
    virtual void rotacionar(double anguloGraus) = 0;
};