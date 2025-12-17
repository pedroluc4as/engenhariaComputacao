#pragma once
#include "Formas.cpp"

class Circulo : public Forma {
private:
    double x, y, raio;

public:
    Circulo(double x, double y, double r) : x(x), y(y), raio(r) {
        if (r <= 0) throw std::invalid_argument("Raio deve ser positivo");
    }

    void desenhar() const override {
        std::cout << "Desenhando Circulo em (" << x << "," << y << ") com raio " << raio << "\n";
    }

    void mover(double dx, double dy) override {
        x += dx; y += dy;
    }

    double area() const override { return 3.14159 * raio * raio; }
    double perimetro() const override { return 2 * 3.14159 * raio; }

    std::unique_ptr<Forma> clonar() const override {
        return std::make_unique<Circulo>(*this);
    }
    
    void setRaio(double r) {
        if (r <= 0) throw std::invalid_argument("Raio deve ser positivo");
        raio = r;
    }
    
    double getRaio() const { return raio; }
};

class Retangulo : public Forma {
private:
    double x, y, largura, altura;

public:
    Retangulo(double x, double y, double w, double h) : x(x), y(y), largura(w), altura(h) {
        if (w <= 0 || h <= 0) throw std::invalid_argument("Dimensoes devem ser positivas");
    }

    void desenhar() const override {
        std::cout << "Desenhando Retangulo em (" << x << "," << y << ") [" << largura << "x" << altura << "]\n";
    }

    void mover(double dx, double dy) override {
        x += dx; y += dy;
    }

    double area() const override { return largura * altura; }
    double perimetro() const override { return 2 * (largura + altura); }

    std::unique_ptr<Forma> clonar() const override {
        return std::make_unique<Retangulo>(*this);
    }

    void redimensionar(double fator) {
        if (fator <= 0) throw std::invalid_argument("Fator deve ser positivo");
        largura *= fator;
        altura *= fator;
    }
};

class Poligono : public Forma {
private:
    std::vector<std::pair<double, double>> vertices;

public:
    Poligono(const std::vector<std::pair<double, double>>& v) : vertices(v) {
        if (vertices.size() < 3) throw std::invalid_argument("Poligono precisa de no minimo 3 vertices");
    }

    void desenhar() const override {
        std::cout << "Desenhando Poligono com " << vertices.size() << " vertices.\n";
    }

    void mover(double dx, double dy) override {
        for (auto& v : vertices) {
            v.first += dx;
            v.second += dy;
        }
    }

    double area() const override {
        return 0.0; 
    }

    double perimetro() const override {
        return 0.0; 
    }

    std::unique_ptr<Forma> clonar() const override {
        return std::make_unique<Poligono>(*this);
    }
};  