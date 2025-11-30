#pragma once
#include <string>

class VeiculoAutonomo {
protected:
    int id;
    std::string posicao;
    double bateria;

public:
    VeiculoAutonomo(int id, std::string posicao, double bateria);
    virtual ~VeiculoAutonomo();

    // Métodos virtuais para polimorfismo
    virtual void planejarRota(std::string destino) = 0; // Tirei o const& pra simplificar
    virtual void mover() = 0;
    virtual void estrategiaRecarga() const = 0;
    
    // Métodos comuns
    virtual void relatorioStatus() const;
    
    // Auxiliares (protegidos ou publicos dependendo do uso)
    virtual bool detectarObstaculos() const = 0;
    virtual double consumoPorKm() const = 0;
};