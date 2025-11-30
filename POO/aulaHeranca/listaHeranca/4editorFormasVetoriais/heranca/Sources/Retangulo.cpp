#include "../Headers/Retangulo.h"
#include <stdexcept>

Retangulo::Retangulo(Ponto canto, double l, double a) 
    : cantoSuperiorEsquerdo(canto), largura(l), altura(a), anguloRotacao(0) {
    if (l <= 0 || a <= 0) {
        throw std::invalid_argument("Dimensões do retângulo devem ser positivas.");
    }
}

void Retangulo::desenhar(Canvas& canvas) const {
    canvas.desenharRetangulo(cantoSuperiorEsquerdo, largura, altura);
}

void Retangulo::mover(double dx, double dy) {
    cantoSuperiorEsquerdo.x += dx;
    cantoSuperiorEsquerdo.y += dy;
}

double Retangulo::area() const {
    return largura * altura;
}

double Retangulo::perimetro() const {
    return 2 * (largura + altura);
}

std::unique_ptr<Forma> Retangulo::clonar() const {
    return std::make_unique<Retangulo>(*this);
}

void Retangulo::escalar(double fator) {
    if (fator <= 0) throw std::invalid_argument("Fator de escala deve ser positivo.");
    largura *= fator;
    altura *= fator;
}

void Retangulo::rotacionar(double anguloGraus) {
    anguloRotacao += anguloGraus;
}