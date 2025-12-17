#include "Ferramentas.cpp"

int main() {
    Renderer renderer;

    try {
        renderer.adicionarForma(std::make_unique<Circulo>(10, 10, 5));
        renderer.adicionarForma(std::make_unique<Retangulo>(0, 0, 20, 10));
        
        std::vector<std::pair<double, double>> tri = {{0,0}, {10,0}, {5,10}};
        renderer.adicionarForma(std::make_unique<Poligono>(tri));

        renderer.renderizarTudo();

        FerramentaRedimensionar redimensionador(2.0);
        std::cout << "\n[Aplicando Ferramenta de Redimensionamento 2x]\n";
        renderer.aplicarFerramentaEmTodas(redimensionador);

        renderer.duplicarUltima();

        renderer.renderizarTudo();

        std::cout << "\n[Teste de Excecao]\n";
        renderer.adicionarForma(std::make_unique<Circulo>(0, 0, -5)); 

    } catch (const std::exception& e) {
        std::cerr << "Erro capturado na main: " << e.what() << "\n";
    }

    return 0;
}