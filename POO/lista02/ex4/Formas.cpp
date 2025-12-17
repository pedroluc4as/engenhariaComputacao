#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <stdexcept>

class Forma {
public:
    virtual ~Forma() = default;

    virtual void desenhar() const = 0;
    virtual void mover(double dx, double dy) = 0;
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual std::unique_ptr<Forma> clonar() const = 0;
};