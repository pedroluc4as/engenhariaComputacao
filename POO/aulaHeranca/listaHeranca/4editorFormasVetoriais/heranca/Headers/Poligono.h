#pragma once
#include "Forma.h"
#include <vector>

class Poligono : public Forma {
private:
    std::vector<Ponto> vertices;

    void validarVertices();

public:
    Poligono(const std::vector<Ponto>& listaVertices);

    void desenhar(Canvas& canvas) const override;
    void mover(double dx, double dy) override;
    double area() const override;
    double perimetro() const override;
    std::unique_ptr<Forma> clonar() const override;

    void escalar(double fator) override;
    void rotacionar(double anguloGraus) override;
};