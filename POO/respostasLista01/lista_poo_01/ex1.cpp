#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Classe simples de domínio */
class Livro {
    string titulo, autor;
    int ano;
public:
    Livro(const string& t, const string& a, int y)
        : titulo(t), autor(a), ano(y) {
        cout << "[construtor] Livro: " << titulo << "\n";
    }
    ~Livro() { cout << "[destrutor] Livro: " << titulo << "\n"; }

    string info() const {
        return titulo + " (" + autor + ", " + to_string(ano) + ")";
    }
};

/* Biblioteca COMPÕE livros: guarda por valor (vector<Livro>) */
class Biblioteca {
    string nome;
    vector<Livro> acervo; // composição
public:
    Biblioteca(const string& n) : nome(n) {
        cout << "[construtor] Biblioteca: " << nome << "\n";
    }
    ~Biblioteca() { cout << "[destrutor] Biblioteca: " << nome << "\n"; }

    void adicionar(const Livro& l) { acervo.push_back(l); }
    void listar() const {
        cout << "Acervo de " << nome << ":\n";
        for (const auto& x : acervo) cout << " - " << x.info() << "\n";
    }
};

int main() {
    Biblioteca b("Central");
    b.adicionar(Livro("POO em C++", "Stroustrup", 2013));
    b.adicionar(Livro("Algorithms", "Sedgewick", 2011));
    b.listar();
    return 0;
}
