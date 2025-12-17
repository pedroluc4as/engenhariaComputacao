#include "GerenciadorCatalogo.cpp"

int main() {
    GerenciadorCatalogo gerenciador;

    gerenciador.adicionarMidia(std::make_unique<Musica>("Bohemian Rhapsody", 1975, 354, "Queen", 320));
    gerenciador.adicionarMidia(std::make_unique<Video>("Inception", 2010, 8880, "4K", "H.264"));
    
    std::vector<std::string> convidados = {"Elon Musk", "Joe Rogan"};
    gerenciador.adicionarMidia(std::make_unique<Podcast>("JRE #1169", 2018, 9000, "Joe Rogan", convidados));

    gerenciador.listarTudo();

    std::cout << "\n[Testando Pesquisa Polimorfica: 'Queen']\n";
    gerenciador.pesquisar("Queen");

    std::cout << "\n[Testando Pesquisa Polimorfica: '4K']\n";
    gerenciador.pesquisar("4K");
    
    std::cout << "\n[Testando Pesquisa Polimorfica: 'Elon']\n";
    gerenciador.pesquisar("Elon");

    return 0;
}