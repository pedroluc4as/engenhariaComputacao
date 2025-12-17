#include "Despachante.cpp"

int main() {
    Despachante despachante;

    despachante.adicionarVeiculo(std::make_unique<CarroAutonomo>(1, Posicao{0,0}, 100.0, 4));
    despachante.adicionarVeiculo(std::make_unique<CaminhaoAutonomo>(2, Posicao{10,10}, 85.0, 5000.0, 6));
    despachante.adicionarVeiculo(std::make_unique<OnibusAutonomo>(3, Posicao{5,5}, 90.0, 40, true));

    despachante.gerarRelatorioGeral();
    despachante.despacharFrota({100, 200});

    return 0;
}