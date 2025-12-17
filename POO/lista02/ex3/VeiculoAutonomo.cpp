#pragma once
#include "VeiculoUtils.cpp"

class VeiculoAutonomo {
protected:
    int id;
    Posicao posicao;
    double bateria;
    ModuloNavegacao navegacao;
    ModuloDiagnostico diagnostico;

public:
    VeiculoAutonomo(int id, Posicao pos, double bat) 
        : id(id), posicao(pos), bateria(bat) {}

    virtual ~VeiculoAutonomo() = default;

    virtual void planejarRota(Posicao destino) {
        navegacao.calcularRota(posicao, destino, "Veiculo Generico");
    }

    virtual void mover() {
        if (bateria > 0) {
            detectarObstaculos();
            std::cout << "Veiculo " << id << " movendo-se.\n";
            bateria -= consumoPorKm();
        } else {
            std::cout << "Veiculo " << id << " sem bateria.\n";
        }
    }

    virtual void relatorioStatus() const {
        std::cout << "ID: " << id << " | Bat: " << bateria << "% | Pos: (" 
                  << posicao.x << ", " << posicao.y << ")\n";
    }

    virtual void estrategiaRecarga() const {
        std::cout << "Recarga padrao em estacao.\n";
    }

    virtual double consumoPorKm() const = 0;
    
    virtual void detectarObstaculos() {
        std::cout << "Sensores padrao escaneando perimetro.\n";
    }

    int getId() const { return id; }
};