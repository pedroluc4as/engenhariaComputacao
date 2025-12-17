#pragma once
#include "FormasConcretas.cpp"

class Ferramenta {
public:
    virtual void aplicar(Forma& f) = 0;
    virtual ~Ferramenta() = default;
};

class FerramentaRedimensionar : public Ferramenta {
private:
    double fator;
public:
    FerramentaRedimensionar(double f) : fator(f) {}

    void aplicar(Forma& f) override {
        try {
            if (auto* r = dynamic_cast<Retangulo*>(&f)) {
                r->redimensionar(fator);
                std::cout << "Ferramenta: Retangulo redimensionado.\n";
            } else if (auto* c = dynamic_cast<Circulo*>(&f)) {
                c->setRaio(c->getRaio() * fator);
                std::cout << "Ferramenta: Circulo redimensionado.\n";
            } else {
                std::cout << "Ferramenta: Redimensionamento nao suportado para esta forma.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Erro na ferramenta: " << e.what() << "\n";
        }
    }
};

class Renderer {
private:
    std::vector<std::unique_ptr<Forma>> canvas;

public:
    void adicionarForma(std::unique_ptr<Forma> f) {
        canvas.push_back(std::move(f));
    }

    void duplicarUltima() {
        if (!canvas.empty()) {
            canvas.push_back(canvas.back()->clonar());
            std::cout << "Renderer: Ultima forma duplicada via clone polimorfico.\n";
        }
    }

    void aplicarFerramentaEmTodas(Ferramenta& tool) {
        for (auto& f : canvas) {
            tool.aplicar(*f);
        }
    }

    void renderizarTudo() {
        std::cout << "\n--- Renderizando Canvas ---\n";
        for (const auto& f : canvas) {
            f->desenhar();
        }
        std::cout << "---------------------------\n";
    }
};