#include "../Headers/Ferramentas.h"

FerramentaRedimensionar::FerramentaRedimensionar(double f) : fator(f) {}

void FerramentaRedimensionar::aplicar(Forma& forma) const {
    try {
        forma.escalar(fator);
        std::cout << "Ferramenta: Objeto redimensionado em " << fator << "x\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao aplicar ferramenta: " << e.what() << "\n";
    }
}

FerramentaRotacionar::FerramentaRotacionar(double a) : angulo(a) {}

void FerramentaRotacionar::aplicar(Forma& forma) const {
    forma.rotacionar(angulo);
    std::cout << "Ferramenta: Objeto rotacionado em " << angulo << " graus\n";
}