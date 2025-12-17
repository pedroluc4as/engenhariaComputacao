#pragma once
#include "VeiculoAutonomo.cpp"

class CarroAutonomo : public VeiculoAutonomo {
private:
    int passageiros;
    bool pilotoAutomaticoAvancado;

public:
    CarroAutonomo(int id, Posicao pos, double bat, int pass) 
        : VeiculoAutonomo(id, pos, bat), passageiros(pass), pilotoAutomaticoAvancado(true) {}

    double consumoPorKm() const override {
        return 0.5 + (passageiros * 0.1);
    }

    void estrategiaRecarga() const override {
        std::cout << "Carro: Buscando estacao de recarga rapida (Supercharger).\n";
    }

    void detectarObstaculos() override {
        std::cout << "Carro: LIDAR 360 ativo para pedestres e veiculos.\n";
    }
};

class CaminhaoAutonomo : public VeiculoAutonomo {
private:
    double capacidadeCarga;
    int eixos;

public:
    CaminhaoAutonomo(int id, Posicao pos, double bat, double carga, int eixos)
        : VeiculoAutonomo(id, pos, bat), capacidadeCarga(carga), eixos(eixos) {}

    void planejarRota(Posicao destino) override {
        std::cout << "[Nav Caminhao] Verificando altura de pontes e restricao de peso...\n";
        navegacao.calcularRota(posicao, destino, "Caminhao Pesado");
    }

    double consumoPorKm() const override {
        return 2.0 + (capacidadeCarga * 0.05);
    }

    void estrategiaRecarga() const override {
        std::cout << "Caminhao: Buscando doca industrial de alta voltagem.\n";
    }
};

class OnibusAutonomo : public VeiculoAutonomo {
private:
    int lotacao;
    bool acessibilidade;

public:
    OnibusAutonomo(int id, Posicao pos, double bat, int lot, bool acess)
        : VeiculoAutonomo(id, pos, bat), lotacao(lot), acessibilidade(acess) {}

    void planejarRota(Posicao destino) override {
        std::cout << "[Nav Onibus] Ajustando rota para incluir pontos de parada obrigatorios.\n";
        navegacao.calcularRota(posicao, destino, "Onibus Urbano");
    }

    double consumoPorKm() const override {
        return 1.5;
    }

    void mover() override {
        std::cout << "Onibus: Verificando portas fechadas e passageiros sentados.\n";
        VeiculoAutonomo::mover();
    }
};