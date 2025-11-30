#pragma once
#include "Forma.h"
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>

class CanvasConsole : public Canvas {
public:
    void desenharCirculo(Ponto centro, double raio) override {
        std::cout << "[Tela] Circulo em (" << centro.x << ", " << centro.y << ") r=" << raio << "\n";
    }
    void desenharRetangulo(Ponto canto, double l, double a) override {
        std::cout << "[Tela] Retangulo em (" << canto.x << ", " << canto.y << ") " << l << "x" << a << "\n";
    }
    void desenharLinha(Ponto p1, Ponto p2) override {
        std::cout << "[Tela] Linha de (" << p1.x << ", " << p1.y << ") ate (" << p2.x << ", " << p2.y << ")\n";
    }
};

class CanvasSVG : public Canvas {
private:
    std::ofstream& stream;
public:
    explicit CanvasSVG(std::ofstream& os) : stream(os) {}

    void desenharCirculo(Ponto centro, double raio) override {
        stream << "<circle cx=\"" << centro.x << "\" cy=\"" << centro.y 
               << "\" r=\"" << raio << "\" stroke=\"black\" fill=\"none\" />\n";
    }
    void desenharRetangulo(Ponto canto, double l, double a) override {
        stream << "<rect x=\"" << canto.x << "\" y=\"" << canto.y 
               << "\" width=\"" << l << "\" height=\"" << a 
               << "\" stroke=\"black\" fill=\"none\" />\n";
    }
    void desenharLinha(Ponto p1, Ponto p2) override {
        stream << "<line x1=\"" << p1.x << "\" y1=\"" << p1.y 
               << "\" x2=\"" << p2.x << "\" y2=\"" << p2.y 
               << "\" stroke=\"black\" />\n";
    }
};

class Renderer {
public:
    void renderizarCena(const std::vector<std::unique_ptr<Forma>>& formas, Canvas& canvas) {
        for (const auto& forma : formas) {
            forma->desenhar(canvas);
        }
    }
};