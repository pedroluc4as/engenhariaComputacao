#include "../Headers/Poligono.h"
#include <cmath>
#include <numeric>
#include <stdexcept>

Poligono::Poligono(const std::vector<Ponto>& listaVertices) : vertices(listaVertices) {
    validarVertices();
}

void Poligono::validarVertices() {
    if (vertices.size() < 3) {
        throw std::invalid_argument("Poligono deve ter pelo menos 3 vertices.");
    }
}

void Poligono::desenhar(Canvas& canvas) const {
    for (size_t i = 0; i < vertices.size(); ++i) {
        Ponto p1 = vertices[i];
        Ponto p2 = vertices[(i + 1) % vertices.size()];
        canvas.desenharLinha(p1, p2);
    }
}

void Poligono::mover(double dx, double dy) {
    for (auto& v : vertices) {
        v.x += dx;
        v.y += dy;
    }
}

double Poligono::area() const {
    double area = 0.0;
    size_t j = vertices.size() - 1;
    for (size_t i = 0; i < vertices.size(); ++i) {
        area += (vertices[j].x + vertices[i].x) * (vertices[j].y - vertices[i].y);
        j = i;
    }
    return std::abs(area / 2.0);
}

double Poligono::perimetro() const {
    double perimetro = 0.0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        Ponto p1 = vertices[i];
        Ponto p2 = vertices[(i + 1) % vertices.size()];
        perimetro += std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }
    return perimetro;
}

std::unique_ptr<Forma> Poligono::clonar() const {
    return std::make_unique<Poligono>(*this);
}

void Poligono::escalar(double fator) {
    if (fator <= 0) throw std::invalid_argument("Fator de escala deve ser positivo.");
    
    Ponto pivo = vertices[0];
    for (size_t i = 1; i < vertices.size(); ++i) {
        vertices[i].x = pivo.x + (vertices[i].x - pivo.x) * fator;
        vertices[i].y = pivo.y + (vertices[i].y - pivo.y) * fator;
    }
}

void Poligono::rotacionar(double anguloGraus) {
    double rad = anguloGraus * (3.14159265358979323846 / 180.0);
    double cosA = std::cos(rad);
    double sinA = std::sin(rad);
    Ponto pivo = vertices[0];

    for (size_t i = 1; i < vertices.size(); ++i) {
        double dx = vertices[i].x - pivo.x;
        double dy = vertices[i].y - pivo.y;
        vertices[i].x = pivo.x + (dx * cosA - dy * sinA);
        vertices[i].y = pivo.y + (dx * sinA + dy * cosA);
    }
}