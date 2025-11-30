#include <iostream>
#include "../Headers/Despachante.h"
#include "../Headers/CarroAutonomo.h"
#include "../Headers/CaminhaoAutonomo.h"
#include "../Headers/OnibusAutonomo.h"

int main() {
    Despachante d;

    d.adicionar(new CarroAutonomo(1, "Centro", 90, 4, 350.0));
    d.adicionar(new CaminhaoAutonomo(2, "Porto", 80, 12000.0, 4));
    d.adicionar(new OnibusAutonomo(3, "Rodoviaria", 70, 40, true));

    d.atribuirRota("Aeroporto Internacional");
    d.moverTodos();
    d.gerarRelatorio();

    // O destrutor do Despachante vai limpar a memória automaticamente ao fim do main
    return 0;
}