#include "../Headers/Circulo.h"
#include <cmath>
#include <stdexcept>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circulo::Circulo(Ponto c, double r) : centro(c), raio(r) {
    if (r <= 0) {
        throw std::invalid_argument("O raio do circulo deve ser maior que zero.");
    }
}

void Circulo::desenhar(Canvas& canvas) const {
    canvas.desenharCirculo(centro, raio);
}

void Circulo::mover(double dx, double dy) {
    centro.x += dx;
    centro.y += dy;
}

double Circulo::area() const {
    return M_PI * raio * raio;
}

double Circulo::perimetro() const {
    return 2 * M_PI * raio;
}

std::unique_ptr<Forma> Circulo::clonar() const {
    return std::make_unique<Circulo>(*this);
}

void Circulo::escalar(double fator) {
    if (fator <= 0) throw std::invalid_argument("Fator de escala deve ser positivo.");
    raio *= fator;
}

void Circulo::rotacionar([[maybe_unused]] double anguloGraus) {
}