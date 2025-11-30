#pragma once
#include <string>

struct Ponto {
    double x, y;
};

class Canvas {
public:
    virtual ~Canvas() = default;

    virtual void desenharCirculo(Ponto centro, double raio) = 0;
    virtual void desenharRetangulo(Ponto canto, double largura, double altura) = 0;
    virtual void desenharLinha(Ponto p1, Ponto p2) = 0;
};