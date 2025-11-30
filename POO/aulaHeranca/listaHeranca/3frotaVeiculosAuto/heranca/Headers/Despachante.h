#pragma once
#include "VeiculoAutonomo.h"
#include <vector>

class Despachante {
private:
    // Mudamos de unique_ptr para ponteiro normal (VeiculoAutonomo*)
    std::vector<VeiculoAutonomo*> frota;

public:
    // Destrutor para limpar a memória
    ~Despachante();

    // Recebe um ponteiro normal agora
    void adicionar(VeiculoAutonomo* v);
    
    void atribuirRota(std::string destino);
    void moverTodos();
    void gerarRelatorio() const;
};